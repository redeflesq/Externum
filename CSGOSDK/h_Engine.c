#include "h_Engine.h"
#include "Game/Engine/Defines.h"

DWORD gPID = NULL;
DWORD engineBase = NULL;
DWORD clientBase = NULL;
HWND gHWND = NULL;

HANDLE h_csgo_hook()
{
	HANDLE Handle = NULL;

	do {
		gHWND = FindWindowA(0, (GAME_CAPTION));
		Sleep(100);
	} while (gHWND == 0);

	GetWindowThreadProcessId(gHWND, &gPID);
	Handle = OpenProcess(PROCESS_ALL_ACCESS, 0, gPID);

	do {
		clientBase = get_module_base_address(gPID, ("client.dll"));
		Sleep(100);
	} while (!clientBase);

	do {
		engineBase = get_module_base_address(gPID, ("engine.dll"));
		Sleep(100);
	} while (!engineBase);

	return Handle;
}