#include "pch.h"
#include "feature.h"
using namespace SDK;

void ESP()
{
	APalPlayerCharacter* pPalCharacter = Config.GetPalPlayerCharacter();
	if (!pPalCharacter)
		return;

	UPalShooterComponent* pShootComponent = pPalCharacter->ShooterComponent;
	if (!pShootComponent)
		return;

	APalWeaponBase* pWeapon = pShootComponent->HasWeapon;
	if (pWeapon)
		DrawUActorComponent(pWeapon->InstanceComponents, ImColor(128, 0, 0));

	if (!Config.UCIM)
		return;

	TArray<SDK::APalCharacter*> T = {};
	Config.UCIM->GetAllPalCharacter(&T);
	if (!T.IsValid())
		return;

	for (int i = 0; i < T.Count(); i++)
		ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(10, 10 + (i * 30)), ImColor(128, 0, 0), T[i]->GetFullName().c_str());
}

void ESP_DEBUG(float mDist, ImVec4 color, UClass* mEntType)
{
	APalPlayerCharacter* pLocalPlayer = Config.GetPalPlayerCharacter();
	if (!pLocalPlayer)
		return;

	APalPlayerController* pPlayerController = static_cast<APalPlayerController*>(pLocalPlayer->Controller);
	if (!pPlayerController)
		return;

	std::vector<AActor*> actors;
	if (!config::GetAllActorsofType(mEntType, &actors, true))
		return;

	auto draw = ImGui::GetWindowDrawList();

	__int32 actorsCount = actors.size();
	for (AActor* actor : actors)
	{
		FVector actorLocation = actor->K2_GetActorLocation();
		FVector localPlayerLocation = pLocalPlayer->K2_GetActorLocation();
		float distantTo = pLocalPlayer->GetDistanceTo(actor);
		if (distantTo > mDist)
			continue;

		FVector2D outScreen;
		if (!pPlayerController->ProjectWorldLocationToScreen(actorLocation, &outScreen, true))
			continue;

		char data[0x256];
		const char* StringData = "OBJECT: [%s]\nCLASS: [%s]\nINDEX: [%d]\nPOSITION: { %0.0f, %0.0f, %0.0f }\nDISTANCE: [%.0fm]";
		if (distantTo >= 1000.f)
		{
			distantTo /= 1000.f;
			StringData = "OBJECT: [%s]\nCLASS: [%s]\nINDEX: [%d]\nPOSITION: { %0.0f, %0.0f, %0.0f }\nDISTANCE: [%.0fkm]";
		}
		sprintf_s(data, StringData, actor->GetName().c_str(), actor->Class->GetFullName().c_str(), actorLocation.X, actorLocation.Y, actorLocation.Z, distantTo);

		ImVec2 screen = ImVec2(static_cast<float>(outScreen.X), static_cast<float>(outScreen.Y));
		draw->AddText(screen, ImColor(color), data);
	}
}

void DrawUActorComponent(SDK::TArray<SDK::UActorComponent*> Comps, ImColor color)
{
	ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), color, "Drawing...");
	if (Comps.IsValid())
	{
		for (int i = 0; i < Comps.Count(); i++)
		{

			if (Comps[i] != NULL)
			{

				ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(10, 10 + (i * 30)), color, Comps[i]->GetFullName().c_str());
			}
		}
	}
}