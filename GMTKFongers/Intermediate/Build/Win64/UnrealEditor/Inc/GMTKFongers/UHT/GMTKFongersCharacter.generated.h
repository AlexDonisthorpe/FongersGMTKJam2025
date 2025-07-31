// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GMTKFongersCharacter.h"

#ifdef GMTKFONGERS_GMTKFongersCharacter_generated_h
#error "GMTKFongersCharacter.generated.h already included, missing '#pragma once' in GMTKFongersCharacter.h"
#endif
#define GMTKFONGERS_GMTKFongersCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AGMTKFongersCharacter ****************************************************
#define FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoMove); \
	DECLARE_FUNCTION(execDoAim);


GMTKFONGERS_API UClass* Z_Construct_UClass_AGMTKFongersCharacter_NoRegister();

#define FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGMTKFongersCharacter(); \
	friend struct Z_Construct_UClass_AGMTKFongersCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GMTKFONGERS_API UClass* Z_Construct_UClass_AGMTKFongersCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AGMTKFongersCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/GMTKFongers"), Z_Construct_UClass_AGMTKFongersCharacter_NoRegister) \
	DECLARE_SERIALIZER(AGMTKFongersCharacter)


#define FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGMTKFongersCharacter(AGMTKFongersCharacter&&) = delete; \
	AGMTKFongersCharacter(const AGMTKFongersCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGMTKFongersCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGMTKFongersCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AGMTKFongersCharacter) \
	NO_API virtual ~AGMTKFongersCharacter();


#define FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h_21_PROLOG
#define FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGMTKFongersCharacter;

// ********** End Class AGMTKFongersCharacter ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_GMTKJamFongers_GMTKFongers_Source_GMTKFongers_GMTKFongersCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
