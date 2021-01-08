#pragma once

#include <Windows.h>
#include "../Memory/memory.h"
#include "Engine/Offsets.h"
#include "../h_Engine.h"
#include "Engine/Structs.h"

DWORD GetClientState();
ClientState GetClientStateState(DWORD dwClientState);
int GetClientStateChokedCommands(DWORD dwClientState);
int GetClientStateDeltaTicks(DWORD dwClientState);
DWORD GetGlowObjectManager();
ViewMatrix GetViewMatrix();
void SetSendPackets(char bSet);