// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomViewport.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "Framework/Application/SlateApplication.h"
#include "SEditorViewport.h"
#include "SLevelViewport.h"
#include "SAssetEditorViewport.h"
#include "Slate/SceneViewport.h"
#include "UObject/Object.h"
#include "Components/StaticMeshComponent.h"
#include "Widgets/Input/SFilePathPicker.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"
#include "Engine/StaticMeshActor.h"
#include "Widgets/Input/SDirectoryPicker.h"
#include "EditorDirectories.h"
#include "SAssetSearchBox.h"
#include "ContentBrowserModule.h"
#include "Delegates/DelegateSignatureImpl.inl"
#include "IContentBrowserSingleton.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/SViewport.h"

#define LOCTEXT_NAMESPACE "FCustomViewportModule"


static const FName DummyDockTab("SlateTest");



void FCustomViewportModule::StartupModule()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(DummyDockTab, FOnSpawnTab::CreateRaw(this, &FCustomViewportModule::CreateSlateTab))
	.SetGroup(WorkspaceMenu::GetMenuStructure().GetDeveloperToolsMiscCategory());;
	MyThumbnailPool = MakeShareable(new FAssetThumbnailPool(16, false));


	FCoreDelegates::OnPreExit.AddLambda([this]()
		{
			if (!MyViewport.IsValid())
				return;

			MyViewport->PreviewScene.Reset();
			MyViewport->TypedViewportClient.Reset();
			MyViewport.Reset();
		});
}
bool FCustomViewportModule::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	if (FParse::Command(&Cmd, TEXT("Dummy")))
	{

		return true;
	}
	return false;
}

FReply FCustomViewportModule::OnGenerateClick()
{
	DestroyAll();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Result[0]);
	UWorld* GenWorld = Procedural.CreateWorld();
	Procedural.ParseOnWorld(GenWorld, WallPath.ObjectPath.ToString(), DestructibleWallPath.ObjectPath.ToString(), FloorPath.ObjectPath.ToString(), FPaths::ConvertRelativePathToFull(Result[0]));
	return FReply::Handled();
}

FReply FCustomViewportModule::OnUpdateClick()
{
	DestroyAll();
	Procedural.ParseOnWorld(World, WallPath.ObjectPath.ToString(), DestructibleWallPath.ObjectPath.ToString(), FloorPath.ObjectPath.ToString(), FPaths::ConvertRelativePathToFull(Result[0]));
	return FReply::Handled();
}

void FCustomViewportModule::DirectoryChanged(const FString& NewDir)
{
	TexturePath = NewDir;
}

void FCustomViewportModule::OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes, TArray<FString>& OutFileNames)
{
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	OutFileNames.Empty();
	DesktopPlatform->OpenFileDialog(nullptr, DialogTitle, DefaultPath, FString(""), FileTypes, 0, OutFileNames);
	FGlobalTabmanager::Get()->TryInvokeTab(DummyDockTab);
	////void* ParentWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandl();
	//void* ParentWindowHandle = World->GetGameViewport()->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	//IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	//if (DesktopPlatform)
	//{
	//	//Opening the file picker!
	//	uint32 SelectionFlag = 0; //A value of 0 represents single file selection while a value of 1represent multiple file selection
	//	
	//}

}


FReply FCustomViewportModule::OnSelectPath()
{
	OpenFileDialog(TEXT("Prova"), TEXT(""), TEXT("Image Files|*png"), Result);

	return FReply::Handled();
}

void FCustomViewportModule::DestroyAll()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(World, AStaticMeshActor::StaticClass(), FoundActors);
	for(AActor* act: FoundActors)
	{
		act->Destroy();
	}
}


void FCustomViewportModule::ShutdownModule()
{
	//isrequestingexits
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(DummyDockTab);
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FCustomViewportModule::SpawnCube(UWorld* W)
{
	AStaticMeshActor* act = W->SpawnActor<AStaticMeshActor>();
	act->GetStaticMeshComponent()->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Engine/VREditor/BasicMeshes/SM_Cube_01.SM_Cube_01'")));
}

TSharedRef<SDockTab> FCustomViewportModule::CreateSlateTab(const FSpawnTabArgs& TabArgs)
{
	Procedural = FModuleManager::GetModuleChecked<FProceduralWorldModule>("ProceduralWorld");

	//TSharedPtr<SEditorViewport> ViewportPtr = SNew(SEditorViewport);
	FDetailWidgetRow wid = FDetailWidgetRow();
	MyViewport = SNew(EditorViewportTest);
	/*Viewport.Get().OnToggleRealtime();
	TSharedPtr<FEditorViewportClient> Client = Viewport.Get().GetViewportClient();*/
	SceneView = MyViewport->GetSceneViewport();
	World = MyViewport->GetSceneViewport().Get()->GetClient()->GetWorld();
	Window = SNew(SDockTab)
		.TabRole(ETabRole::MajorTab)
		[
			SNew(SSplitter).Orientation(Orient_Horizontal)
			+SSplitter::Slot().Value(0.25f)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot().AutoHeight()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().AutoWidth()
					.HAlign(EHorizontalAlignment::HAlign_Center)
					.VAlign(EVerticalAlignment::VAlign_Center)
					[
						SNew(STextBlock)
						
						.Text(FText::FromString(TEXT("Default Wall")))
					]
					+SHorizontalBox::Slot().HAlign(EHorizontalAlignment::HAlign_Right).Padding(0,0,10,0)
					[
						SNew(SObjectPropertyEntryBox)
						.AllowedClass(UBlueprint::StaticClass())
						.ObjectPath_Lambda([this]()->FString {return WallPath.GetAsset()->GetPathName();})
						.OnObjectChanged_Lambda([this](const FAssetData& Data)->void {WallPath = Data; })
						.ThumbnailPool(MyThumbnailPool)
						.DisplayThumbnail(true)
					]
				]
				+ SVerticalBox::Slot().AutoHeight()
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot().AutoWidth()
						.HAlign(EHorizontalAlignment::HAlign_Center)
						.VAlign(EVerticalAlignment::VAlign_Center)
						[
							SNew(STextBlock)
							.Text(FText::FromString(TEXT("Destructible Wall")))
						]
						+ SHorizontalBox::Slot().HAlign(EHorizontalAlignment::HAlign_Right).Padding(0, 0, 10, 0)
						[
							SNew(SObjectPropertyEntryBox)
							.AllowedClass(UBlueprint::StaticClass())
							.ObjectPath_Lambda([this]()->FString {return DestructibleWallPath.GetAsset()->GetPathName(); })
							.OnObjectChanged_Lambda([this](const FAssetData& Data)->void {DestructibleWallPath = Data; })
							.ThumbnailPool(MyThumbnailPool)
							.DisplayThumbnail(true)
						]
						
					]
				+ SVerticalBox::Slot().AutoHeight()
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot().AutoWidth()
						.HAlign(EHorizontalAlignment::HAlign_Center)
						.VAlign(EVerticalAlignment::VAlign_Center)
						[
							SNew(STextBlock).Text(FText::FromString(TEXT("Floor")))
						]
						+ SHorizontalBox::Slot().HAlign(EHorizontalAlignment::HAlign_Right).Padding(0, 0, 10, 0)
						[
							SNew(SObjectPropertyEntryBox)
							.AllowedClass(UBlueprint::StaticClass())
							.ObjectPath_Lambda([this]()->FString {return FloorPath.GetAsset()->GetPathName(); })
							.OnObjectChanged_Lambda([this](const FAssetData& Data)->void {FloorPath = Data; })
							.ThumbnailPool(MyThumbnailPool)
							.DisplayThumbnail(true)
						]
					]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(SButton)
					.Text(FText::FromString(TEXT("Select Texture")))
					.OnClicked(FOnClicked::CreateRaw(this,&FCustomViewportModule::OnSelectPath))
					/*.OnPathPicked(SDirectoryPicker::FOnDirectoryChanged::CreateRaw(this, &FCustomViewportModule::DirectoryChanged))*/
				]
				+SVerticalBox::Slot().AutoHeight()
				[
					SNew(SButton)
					.Text(FText::FromString(TEXT("Update Preview")))
					.OnClicked(FOnClicked::CreateRaw(this,&FCustomViewportModule::OnUpdateClick))
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(SButton).Text(FText::FromString(TEXT("Generate Level")))
					.OnClicked(FOnClicked::CreateRaw(this, &FCustomViewportModule::OnGenerateClick))
				]
			]
			+ SSplitter::Slot()
			[
				MyViewport.ToSharedRef()
			]
		];


	//World->SpawnActor<
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(World, AActor::StaticClass(), Actors);
	for (AActor* act : Actors)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *act->GetName());
		
	}
	return Window.ToSharedRef();
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomViewportModule, CustomViewport)