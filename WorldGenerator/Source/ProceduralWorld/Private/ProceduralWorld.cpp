// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProceduralWorld.h"
#include "ImageUtils.h"
#include "Factories/WorldFactory.h"
#include "Misc/FileHelper.h"
#include "PluginSettings.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/DirectionalLight.h"

#define LOCTEXT_NAMESPACE "FProceduralWorldModule"


void FProceduralWorldModule::StartupModule()
{
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	if (ISettingsModule* SettingModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingModule->RegisterSettings("Project", "Plugins", "WorldPluginSettings",
			LOCTEXT("RuntimeSettingsName", "Procedural World Settings"),
			LOCTEXT("RuntimeSettingsDescription", "Configure my setting"),
			GetMutableDefault<UPluginSettings>()
		);
		
	}
	
}

void FProceduralWorldModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("WorldPluginSettings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "WorldPluginSettings");
	}
}

UWorld* FProceduralWorldModule::CreateWorld()
{
	uint32 RandomInt = FMath::RandRange(0, 9000);
	FString WorldName = FString::Printf(TEXT("ProceduralWorld_%d"), RandomInt);
	UPackage* Package = CreatePackage(*(FString::Printf(TEXT("/Game/World/%s"),*WorldName)));
	UWorldFactory* WorldFactory = NewObject<UWorldFactory>();

	UObject* ObjectWorld = WorldFactory->FactoryCreateNew(WorldFactory->SupportedClass, Package, *WorldName, EObjectFlags::RF_Standalone | EObjectFlags::RF_Public, nullptr, GWarn);
	UWorld* World = Cast<UWorld>(ObjectWorld);
	FAssetRegistryModule::AssetCreated(ObjectWorld);
	World->MarkPackageDirty();
	return World;
}
void FProceduralWorldModule::ParseMap(UWorld* World,FString TexturePath = FString(TEXT("")))
{
	if (!World)
	{
		GenWorld = CreateWorld();
	}
	else
	{
		GenWorld = World;
	}
	if (TexturePath.Compare(FString(TEXT(""))) == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *TexturePath);
		TexturePath = FString(TEXT("C:\\Users\\andre\\Desktop\\Texture_UE\\Mappa.png"));
	}
	FString FileName = TexturePath;
	TArray<uint8> Buffer;
	FFileHelper::LoadFileToArray(Buffer, *FileName);
	UTexture2D* Texture = FImageUtils::ImportBufferAsTexture2D(Buffer);
	//ADirectionalLight* Directional = GenWorld->SpawnActor<ADirectionalLight>();
	//Directional->SetMobility(EComponentMobility::Movable);
	AStaticMeshActor* AFloor = GenWorld->SpawnActor<AStaticMeshActor>(Floor->GeneratedClass);
	FVector FloorSize = AFloor->GetStaticMeshComponent()->GetStaticMesh()->GetBounds().GetBox().GetSize();
	FVector FloorLocation = FVector(0, 0, 0);
	FloorLocation.X = ((Texture->GetSizeX() / 2) * 100) - 50;
	FloorLocation.Y = ((Texture->GetSizeY() / 2) * 100) - 50;
	FloorLocation.Z = -50;
	AFloor->SetActorLocation(FloorLocation);

	const FColor* FormatedImageData = static_cast<const FColor*>(Texture->PlatformData->Mips[0].BulkData.LockReadOnly());
	for (int32 X = 0; X < Texture->GetSizeX(); X++)
	{
		for (int32 Y = 0; Y < Texture->GetSizeY(); Y++)
		{
			FColor PixelColor = FormatedImageData[Y * Texture->GetSizeX() + X];
			ParseColor(PixelColor, X, Y);
		}
	}
	Texture->PlatformData->Mips[0].BulkData.Unlock();

}

bool FProceduralWorldModule::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	if (FParse::Command(&Cmd, TEXT("Create")))
	{
		UPluginSettings* PluginSettings = GetMutableDefault<UPluginSettings>();
		DefaultWall = LoadObject<UBlueprint>(nullptr, *(PluginSettings->DefaultWall.GetAssetPathString()));
		DestroyableWall = LoadObject<UBlueprint>(nullptr, *(PluginSettings->DestroyableWall.GetAssetPathString()));
		Floor = LoadObject<UBlueprint>(nullptr, *(PluginSettings->Floor.GetAssetPathString()));
		ParseMap(nullptr);
		return true;
	}
	return false;
}

void FProceduralWorldModule::ParseOnWorld(UWorld* World,FString Def, FString Destr, FString Flr,FString TexturePath)
{
	UPluginSettings* PluginSettings = GetMutableDefault<UPluginSettings>();
	DefaultWall = LoadObject<UBlueprint>(nullptr, *(Def));
	DestroyableWall = LoadObject<UBlueprint>(nullptr, *(Destr));
	Floor = LoadObject<UBlueprint>(nullptr, *(Flr));
	ParseMap(World,TexturePath);
}

void FProceduralWorldModule::ParseColor(FColor Color,int32 X, int32 Y)
{
	FVector Offset = FVector(100,100, 0);
	
	if (Color.B == 255)
	{
		AStaticMeshActor* Spawned = GenWorld->SpawnActor<AStaticMeshActor>(DefaultWall->GeneratedClass);
		Spawned->SetActorLocation(FVector(X, Y, 0) * Offset);
	}
	else if (Color.R == 255)
	{
		AStaticMeshActor* Spawned = GenWorld->SpawnActor<AStaticMeshActor>(DestroyableWall->GeneratedClass);
		Spawned->SetActorLocation(FVector(X, Y, 0) * Offset);
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FProceduralWorldModule, ProceduralWorld)