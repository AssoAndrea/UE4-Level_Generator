// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ISettingsModule.h"
#include "Modules/ModuleManager.h"

class PROCEDURALWORLD_API FProceduralWorldModule : public IModuleInterface, public FSelfRegisteringExec
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
	void ParseOnWorld(UWorld* World, FString Def, FString Destr, FString Flr, FString TexturePath);
	UWorld* GenWorld;
	UBlueprint* DefaultWall;
	UBlueprint* DestroyableWall;
	UBlueprint* Floor;
	UWorld* CreateWorld();


private:
	void ParseColor(FColor Color, int32 X, int32 Y);


	void ParseMap(UWorld* World, FString TexturePath);


	
};

