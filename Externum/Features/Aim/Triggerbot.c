#include "Triggerbot.h"
#include "../../e_HackEngine.h"
#include "../Features.h"
#include "../../Utils/nmath.h"

void fTriggerbot()
{
	if (!(GetAsyncKeyState(VK_MENU)  == -32768)) {
		return;
	}

	int iDelay = 0;
	int iFireTime = 0;

	DWORD dwClientState = GetClientState();
	int iLocalPlayerID = LocalPlayerGetID(dwClientState);
	DWORD dwLocalPlayerBase = PlayerGetBase(iLocalPlayerID);

	if (!LocalPlayerWeaponCanAttack(dwClientState, dwLocalPlayerBase, 64)) {
		return;
	}

	int iPlayerIdOnCrosshair = LocalPlayerGetEntityIdOnCrosshair(dwLocalPlayerBase);

	if (!PlayerIsValidID(iPlayerIdOnCrosshair)) {
		return;
	}

	DWORD dwPlayerBase = PlayerGetBase(iPlayerIdOnCrosshair);

	if (dwPlayerBase == 0) {
		return;
	}

	int iPlayerHealth = PlayerGetHealth(dwPlayerBase);

	if (iPlayerHealth < 1) {
		return;
	}

	Team tmPlayerTeam = PlayerGetTeam(dwPlayerBase);
	Team tmLocalPlayerTeam = PlayerGetTeam(dwLocalPlayerBase);

	if (tmPlayerTeam == tmLocalPlayerTeam) {
		return;
	}

	DWORD dwLocalPlayerWeaponActive = PlayerWeaponGetActive(dwLocalPlayerBase);
	DWORD dwLocalPlayerWeaponEntity = PlayerWeaponGetEntity(dwLocalPlayerWeaponActive);
	int iLocalPlayerWeaponDefinitionIndex = PlayerWeaponGetDefinitionIndex(dwLocalPlayerWeaponEntity);
	int iLocalPlayerWeaponID = PlayerWeaponGetID(iLocalPlayerWeaponDefinitionIndex);

	int ptShot = 5;
	int ptNoShot = 4;

	iFireTime = FHandle.Aim.Triggerbot.iFiretime;

	if (iLocalPlayerWeaponID == WEAPON_REVOLVER)
	{
		iFireTime = 400;

		Vector3 v3LocalPlayerPos = PlayerGetPosition(dwLocalPlayerBase);
		Vector3 v3PlayerPos = PlayerGetPosition(dwPlayerBase);

		float fDistance = M_DISTANCE(
			v3LocalPlayerPos.x - v3PlayerPos.x, 
			v3LocalPlayerPos.y - v3PlayerPos.y,
			v3LocalPlayerPos.z - v3PlayerPos.z,
		);

		int iAttackType = 0;

		if (fDistance > 250) {
			iAttackType = 1;
		}
		else
		{
			iAttackType = 2;
		}

		switch (iAttackType)
		{
		case 1:
			if (FHandle.Aim.Triggerbot.bRevolverOnlyOnEnemy) {
				goto Attack1_RevolverOnlyOnEnemy;
			}
			else
			{
				goto Attack1;
			}
		case 2:
			goto Attack2;
		}
	}
	else
	{
		goto Attack1;
	}
	return;

Attack1:
	Sleep(iDelay);
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
	Sleep(iFireTime);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
	return;

Attack1_RevolverOnlyOnEnemy:
	Sleep(iDelay);
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
	Sleep(200);
	if (!PlayerIsValidID(LocalPlayerGetEntityIdOnCrosshair(dwLocalPlayerBase))) {
		mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
	}
	Sleep(200);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
	return;

Attack2:
	Sleep(iDelay);
	mouse_event(MOUSEEVENTF_RIGHTDOWN, NULL, NULL, NULL, NULL);
	Sleep(iFireTime);
	mouse_event(MOUSEEVENTF_RIGHTUP, NULL, NULL, NULL, NULL);
	return;
}