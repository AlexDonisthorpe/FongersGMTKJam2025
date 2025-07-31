// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GMTKFongers/GMTKFongersCameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeGMTKFongersCameraManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
GMTKFONGERS_API UClass* Z_Construct_UClass_AGMTKFongersCameraManager();
GMTKFONGERS_API UClass* Z_Construct_UClass_AGMTKFongersCameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_GMTKFongers();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AGMTKFongersCameraManager ************************************************
void AGMTKFongersCameraManager::StaticRegisterNativesAGMTKFongersCameraManager()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AGMTKFongersCameraManager;
UClass* AGMTKFongersCameraManager::GetPrivateStaticClass()
{
	using TClass = AGMTKFongersCameraManager;
	if (!Z_Registration_Info_UClass_AGMTKFongersCameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("GMTKFongersCameraManager"),
			Z_Registration_Info_UClass_AGMTKFongersCameraManager.InnerSingleton,
			StaticRegisterNativesAGMTKFongersCameraManager,
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
	return Z_Registration_Info_UClass_AGMTKFongersCameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AGMTKFongersCameraManager_NoRegister()
{
	return AGMTKFongersCameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AGMTKFongersCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "GMTKFongersCameraManager.h" },
		{ "ModuleRelativePath", "GMTKFongersCameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGMTKFongersCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGMTKFongersCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_GMTKFongers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGMTKFongersCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGMTKFongersCameraManager_Statics::ClassParams = {
	&AGMTKFongersCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGMTKFongersCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AGMTKFongersCameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGMTKFongersCameraManager()
{
	if (!Z_Registration_Info_UClass_AGMTKFongersCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGMTKFongersCameraManager.OuterSingleton, Z_Construct_UClass_AGMTKFongersCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGMTKFongersCameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGMTKFongersCameraManager);
AGMTKFongersCameraManager::~AGMTKFongersCameraManager() {}
// ********** End Class AGMTKFongersCameraManager **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCameraManager_h__Script_GMTKFongers_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGMTKFongersCameraManager, AGMTKFongersCameraManager::StaticClass, TEXT("AGMTKFongersCameraManager"), &Z_Registration_Info_UClass_AGMTKFongersCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGMTKFongersCameraManager), 1605864895U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCameraManager_h__Script_GMTKFongers_1000626142(TEXT("/Script/GMTKFongers"),
	Z_CompiledInDeferFile_FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCameraManager_h__Script_GMTKFongers_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCameraManager_h__Script_GMTKFongers_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
