#pragma once

#include <Windows.h>
#include "e_HackUtils.h"
#include "../CSGOSDK/sdk.h"

int bHackActive;
DWORD gPID;
HWND gHWND;

int player_on_screen(ViewMatrix view_matrix, Vector3 from);
int world_to_screen(ViewMatrix view_matrix, RECT rect, Vector3 from, Vector3* to);
void e_HackCSGOHook();
void e_HackStart();
void e_HackStop();