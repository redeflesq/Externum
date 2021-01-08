#pragma once

#include <Windows.h>
#include "../Memory/memory.h"
#include "Engine/Offsets.h"

int LocalPlayerOnServer(int iDeltaTicks);
int LocalPlayerGetID(DWORD dwClientState);
void LocalPlayerSetFOV(DWORD dwBase, int iFOV);
int LocalPlayerGetFOV(DWORD dwBase);
int LocalPlayerGetEntityIdOnCrosshair(DWORD dwBase);
float LocalPlayerGetNextAttack(DWORD dwBase);
float LocalPlayerGetNextPrimaryAttack(DWORD dwBase);