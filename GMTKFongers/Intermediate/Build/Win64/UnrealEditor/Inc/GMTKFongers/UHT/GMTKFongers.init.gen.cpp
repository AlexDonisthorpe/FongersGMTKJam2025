// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGMTKFongers_init() {}
	GMTKFONGERS_API UFunction* Z_Construct_UDelegateFunction_GMTKFongers_BulletCountUpdatedDelegate__DelegateSignature();
	GMTKFONGERS_API UFunction* Z_Construct_UDelegateFunction_GMTKFongers_PawnDeathDelegate__DelegateSignature();
	GMTKFONGERS_API UFunction* Z_Construct_UDelegateFunction_GMTKFongers_SprintStateChangedDelegate__DelegateSignature();
	GMTKFONGERS_API UFunction* Z_Construct_UDelegateFunction_GMTKFongers_UpdateSprintMeterDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GMTKFongers;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GMTKFongers()
	{
		if (!Z_Registration_Info_UPackage__Script_GMTKFongers.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_GMTKFongers_BulletCountUpdatedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GMTKFongers_PawnDeathDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GMTKFongers_SprintStateChangedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GMTKFongers_UpdateSprintMeterDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/GMTKFongers",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x9C3169BF,
				0xA6BDE9FA,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GMTKFongers.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_GMTKFongers.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GMTKFongers(Z_Construct_UPackage__Script_GMTKFongers, TEXT("/Script/GMTKFongers"), Z_Registration_Info_UPackage__Script_GMTKFongers, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x9C3169BF, 0xA6BDE9FA));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
