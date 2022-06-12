// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PluginSettings.generated.h"

/**
 * 
 */
UCLASS(config = WorldPluginSettings)
class PROCEDURALWORLD_API UPluginSettings : public UObject
{
	GENERATED_BODY()


public:
	UPluginSettings(const FObjectInitializer& obj);
	UPROPERTY(Config, EditAnywhere, Category = Settings, meta = (AllowedClasses = "Blueprint"))
	FSoftObjectPath DefaultWall;

	UPROPERTY(Config, EditAnywhere, Category = Settings, meta = (AllowedClasses = "Blueprint"))
	FSoftObjectPath DestroyableWall;

	UPROPERTY(Config, EditAnywhere, Category = Settings, meta = (AllowedClasses = "Blueprint"))
	FSoftObjectPath Floor;
	
};
