#pragma once

// Dumped with Dumper-7!


#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------------------------------------------------
// FUNCTIONS
//---------------------------------------------------------------------------------------------------------------------


// BlueprintGeneratedClass BP_PalRichTextDecorator_UICommon.BP_PalRichTextDecorator_UICommon_C
// (None)

class UClass* UBP_PalRichTextDecorator_UICommon_C::StaticClass()
{
	static class UClass* Clss = nullptr;

	if (!Clss)
		Clss = UObject::FindClassFast("BP_PalRichTextDecorator_UICommon_C");

	return Clss;
}


// BP_PalRichTextDecorator_UICommon_C BP_PalRichTextDecorator_UICommon.Default__BP_PalRichTextDecorator_UICommon_C
// (Public, ClassDefaultObject, ArchetypeObject, WasLoaded, LoadCompleted)

class UBP_PalRichTextDecorator_UICommon_C* UBP_PalRichTextDecorator_UICommon_C::GetDefaultObj()
{
	static class UBP_PalRichTextDecorator_UICommon_C* Default = nullptr;

	if (!Default)
		Default = static_cast<UBP_PalRichTextDecorator_UICommon_C*>(UBP_PalRichTextDecorator_UICommon_C::StaticClass()->DefaultObject);

	return Default;
}


// Function BP_PalRichTextDecorator_UICommon.BP_PalRichTextDecorator_UICommon_C.GetTextStringInternal
// (Event, Protected, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                     WorldContextObject                                               (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class FName                        ID                                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FString                      ReturnValue                                                      (Parm, OutParm, ZeroConstructor, ReturnParm, HasGetValueTypeHash)
// class FText                        CallFunc_GetLocalizedText_ReturnValue                            (None)
// class FString                      CallFunc_Conv_TextToString_ReturnValue                           (ZeroConstructor, HasGetValueTypeHash)

class FString UBP_PalRichTextDecorator_UICommon_C::GetTextStringInternal(class UObject* WorldContextObject, class FName ID, class FText CallFunc_GetLocalizedText_ReturnValue, const class FString& CallFunc_Conv_TextToString_ReturnValue)
{
	static class UFunction* Func = nullptr;

	if (!Func)
		Func = Class->GetFunction("BP_PalRichTextDecorator_UICommon_C", "GetTextStringInternal");

	Params::UBP_PalRichTextDecorator_UICommon_C_GetTextStringInternal_Params Parms{};

	Parms.WorldContextObject = WorldContextObject;
	Parms.ID = ID;
	Parms.CallFunc_GetLocalizedText_ReturnValue = CallFunc_GetLocalizedText_ReturnValue;
	Parms.CallFunc_Conv_TextToString_ReturnValue = CallFunc_Conv_TextToString_ReturnValue;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;

}


// Function BP_PalRichTextDecorator_UICommon.BP_PalRichTextDecorator_UICommon_C.GetTagName
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                      ReturnValue                                                      (Parm, OutParm, ZeroConstructor, ReturnParm, HasGetValueTypeHash)

class FString UBP_PalRichTextDecorator_UICommon_C::GetTagName()
{
	static class UFunction* Func = nullptr;

	if (!Func)
		Func = Class->GetFunction("BP_PalRichTextDecorator_UICommon_C", "GetTagName");

	Params::UBP_PalRichTextDecorator_UICommon_C_GetTagName_Params Parms{};


	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;

}

}


