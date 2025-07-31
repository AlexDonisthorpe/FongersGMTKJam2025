// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GMTKFongers/GMTKFongersGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeGMTKFongersGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
GMTKFONGERS_API UClass* Z_Construct_UClass_AGMTKFongersGameMode();
GMTKFONGERS_API UClass* Z_Construct_UClass_AGMTKFongersGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_GMTKFongers();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AGMTKFongersGameMode *****************************************************
void AGMTKFongersGameMode::StaticRegisterNativesAGMTKFongersGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AGMTKFongersGameMode;
UClass* AGMTKFongersGameMode::GetPrivateStaticClass()
{
	using TClass = AGMTKFongersGameMode;
	if (!Z_Registration_Info_UClass_AGMTKFongersGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("GMTKFongersGameMode"),
			Z_Registration_Info_UClass_AGMTKFongersGameMode.InnerSingleton,
			StaticRegisterNativesAGMTKFongersGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AGMTKFongersGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AGMTKFongersGameMode_NoRegister()
{
	return AGMTKFongersGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AGMTKFongersGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GMTKFongersGameMode.h" },
		{ "ModuleRelativePath", "GMTKFongersGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGMTKFongersGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGMTKFongersGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GMTKFongers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGMTKFongersGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGMTKFongersGameMode_Statics::ClassParams = {
	&AGMTKFongersGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGMTKFongersGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AGMTKFongersGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGMTKFongersGameMode()
{
	if (!Z_Registration_Info_UClass_AGMTKFongersGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGMTKFongersGameMode.OuterSingleton, Z_Construct_UClass_AGMTKFongersGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGMTKFongersGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGMTKFongersGameMode);
AGMTKFongersGameMode::~AGMTKFongersGameMode() {}
// ********** End Class AGMTKFongersGameMode *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersGameMode_h__Script_GMTKFongers_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGMTKFongersGameMode, AGMTKFongersGameMode::StaticClass, TEXT("AGMTKFongersGameMode"), &Z_Registration_Info_UClass_AGMTKFongersGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGMTKFongersGameMode), 3144627990U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersGameMode_h__Script_GMTKFongers_3314076876(TEXT("/Script/GMTKFongers"),
	Z_CompiledInDeferFile_FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersGameMode_h__Script_GMTKFongers_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersGameMode_h__Script_GMTKFongers_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
