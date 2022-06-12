// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Docking/SDockTab.h"
#include "EditorViewportTest.h"
#include "ProceduralWorld.h"
#include "Modules/ModuleManager.h"

class CUSTOMVIEWPORT_API FCustomViewportModule : public IModuleInterface, public FSelfRegisteringExec
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void SpawnCube(UWorld* W);

	TSharedRef<SDockTab> CreateSlateTab(const FSpawnTabArgs& TabArgs);
	bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
	TSharedPtr<SDockTab> Window;


	TSharedPtr<FAssetThumbnailPool> MyThumbnailPool;
	FProceduralWorldModule Procedural;
	FReply OnGenerateClick();
	FReply OnUpdateClick();
	void DirectoryChanged(const FString& NewDir);
	//settings
	UWorld* World;
	FString TexturePath;
	FAssetData WallPath;
	FAssetData DestructibleWallPath;
	FAssetData FloorPath;
	/*SObjectPropertyEntryBox EntryBox;*/

	void OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes, TArray<FString>& OutFileNames);

	FReply OnSelectPath();
	TArray<FString> Result;
	TSharedPtr<FSceneViewport> SceneView;
	TSharedPtr<EditorViewportTest> MyViewport;

	void DestroyAll();

};


