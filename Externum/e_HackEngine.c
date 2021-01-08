#include "e_HackEngine.h"
#include "Features/Features.h"

#define SWT_START while (bHackActive){ if(bSleepBefore){ Sleep(1); }
#define SWT_STOP Sleep(1); }
#define FSWITCH_HANDLER(KEY, F) if (GetAsyncKeyState(KEY) & 1) { F = !F; }

int bLocalPlayerOnServer = 0;
int bCSGOisActiveWindow = 0;
int bHackActive = 1;
int bSleepBefore = 1;

void ev_MainThread();
void WINAPI ev_AdtlThread();
void WINAPI ev_KeyboardThread();

HANDLE hnAdtlThread, hnKeyboardThread;

void e_HackCSGOHook()
{
	hnMemoryHandle = h_csgo_hook();
}

void e_HackStart()
{
	FHandle.Visuals.bEnabled = 1;
	FHandle.Visuals.Glow.bEnabled = 1;
	FHandle.Visuals.Glow.rgbaColor = (RGBA){ 0,255,0,255 };
	FHandle.Visuals.Glow.bFull = 0;

	FHandle.Visuals.ESP.bEnabled = 1;

	FHandle.Aim.bEnabled = 1;
	FHandle.Aim.Triggerbot.bEnabled = 1;
	FHandle.Aim.Triggerbot.bRevolverOnlyOnEnemy = 1; //Can shot only crosshair on enemy
	FHandle.Aim.Triggerbot.iDelay = 1;
	FHandle.Aim.Triggerbot.iFiretime = 16;

	hnKeyboardThread = CreateThread(0, 0, ev_KeyboardThread, 0, 0, 0);
	hnAdtlThread = CreateThread(0, 0, ev_AdtlThread, 0, 0, 0);
	
	ev_MainThread();
}

void e_HackStop()
{
	fESP_Disable();
	bHackActive = 0;
	free(hnKeyboardThread);
	free(hnAdtlThread);
}

void ev_MainThread()
{
	fESP_Enable();
	
	SWT_START

		bLocalPlayerOnServer = LocalPlayerOnServer(GetClientStateDeltaTicks(GetClientState()));
		bCSGOisActiveWindow = (GetForegroundWindow() == gHWND);

		if (!bLocalPlayerOnServer || !bCSGOisActiveWindow) {
			continue;
		}

		if (FHandle.Visuals.bEnabled) {
			if (FHandle.Visuals.Glow.bEnabled) {
				fGlow();
			}

			if (FHandle.Visuals.ESP.bEnabled) {
				fESP();
			}
		}

	SWT_STOP
}

void WINAPI ev_AdtlThread()
{
	SWT_START

		if (!bLocalPlayerOnServer || !bCSGOisActiveWindow) {
			continue;
		}

		if (FHandle.Aim.bEnabled) {
			if (FHandle.Aim.Triggerbot.bEnabled) {
				fTriggerbot();
			}
		}

	SWT_STOP
}

void WINAPI ev_KeyboardThread()
{
	SWT_START

		FSWITCH_HANDLER(VK_F6, FHandle.Visuals.Glow.bEnabled)
		FSWITCH_HANDLER(VK_F7, FHandle.Visuals.ESP.bEnabled)
		FSWITCH_HANDLER(VK_F8, FHandle.Aim.Triggerbot.bEnabled)
		FSWITCH_HANDLER(VK_F9, bHackActive)
		FSWITCH_HANDLER(VK_INSERT, bSleepBefore)

	SWT_STOP
}