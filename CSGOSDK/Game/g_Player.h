#pragma once

#include <Windows.h>
#include "../Memory/memory.h"
#include "Engine/Offsets.h"
#include "../h_Engine.h"
#include "Engine/Structs.h"

DWORD PlayerGetBase(int iID);
int PlayerGetFlag(DWORD dwBase);
int PlayerGetHealth(DWORD dwBase);
int PlayerGetArmor(DWORD dwBase);
Vector3 PlayerGetPosition(DWORD dwBase);
int PlayerGetGlowIndex(DWORD dwBase);
void PlayerSetEntityGlow(DWORD dwGlowObjectManager, int iGlowIndex, RGBA RGBA, int Occluded, int UnOccluded, int Full);
Team PlayerGetTeam(DWORD dwBase);
float PlayerGetSpawnTime(DWORD dwBase);
DWORD PlayerWeaponGetActive(DWORD dwBase);
DWORD PlayerWeaponGetEntity(DWORD dwActiveWeapon);
int PlayerWeaponGetDefinitionIndex(DWORD dwWeaponEntity);
int PlayerWeaponGetID(int iDefinitionIndex);
int PlayerIsDormant(DWORD dwBase);