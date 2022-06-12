// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProceduralWorld/Public/PluginSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePluginSettings() {}
// Cross Module References
	PROCEDURALWORLD_API UClass* Z_Construct_UClass_UPluginSettings_NoRegister();
	PROCEDURALWORLD_API UClass* Z_Construct_UClass_UPluginSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_ProceduralWorld();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
// End Cross Module References
	void UPluginSettings::StaticRegisterNativesUPluginSettings()
	{
	}
	UClass* Z_Construct_UClass_UPluginSettings_NoRegister()
	{
		return UPluginSettings::StaticClass();
	}
	struct Z_Construct_UClass_UPluginSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultWall_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DefaultWall;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DestroyableWall_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DestroyableWall;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Floor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Floor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPluginSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ProceduralWorld,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPluginSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PluginSettings.h" },
		{ "ModuleRelativePath", "Public/PluginSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPluginSettings_Statics::NewProp_DefaultWall_MetaData[] = {
		{ "AllowedClasses", "Blueprint" },
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PluginSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPluginSettings_Statics::NewProp_DefaultWall = { "DefaultWall", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPluginSettings, DefaultWall), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(Z_Construct_UClass_UPluginSettings_Statics::NewProp_DefaultWall_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::NewProp_DefaultWall_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPluginSettings_Statics::NewProp_DestroyableWall_MetaData[] = {
		{ "AllowedClasses", "Blueprint" },
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PluginSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPluginSettings_Statics::NewProp_DestroyableWall = { "DestroyableWall", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPluginSettings, DestroyableWall), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(Z_Construct_UClass_UPluginSettings_Statics::NewProp_DestroyableWall_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::NewProp_DestroyableWall_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPluginSettings_Statics::NewProp_Floor_MetaData[] = {
		{ "AllowedClasses", "Blueprint" },
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PluginSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPluginSettings_Statics::NewProp_Floor = { "Floor", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPluginSettings, Floor), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(Z_Construct_UClass_UPluginSettings_Statics::NewProp_Floor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::NewProp_Floor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPluginSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPluginSettings_Statics::NewProp_DefaultWall,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPluginSettings_Statics::NewProp_DestroyableWall,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPluginSettings_Statics::NewProp_Floor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPluginSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPluginSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPluginSettings_Statics::ClassParams = {
		&UPluginSettings::StaticClass,
		"WorldPluginSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPluginSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPluginSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPluginSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPluginSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPluginSettings, 2430561751);
	template<> PROCEDURALWORLD_API UClass* StaticClass<UPluginSettings>()
	{
		return UPluginSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPluginSettings(Z_Construct_UClass_UPluginSettings, &UPluginSettings::StaticClass, TEXT("/Script/ProceduralWorld"), TEXT("UPluginSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPluginSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
