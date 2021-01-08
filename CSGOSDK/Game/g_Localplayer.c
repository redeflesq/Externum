#include "g_Localplayer.h"

int LocalPlayerOnServer(int iDeltaTicks)
{
	if (iDeltaTicks == -1) {
		return 0;
	}
	else {
		return 1;
	}
}

int LocalPlayerGetID(DWORD dwClientState)
{
	int iID = 0;
	ReadMemInt(dwClientState + dwClientState_GetLocalPlayer, &iID);
	return iID;
}

void LocalPlayerSetFOV(DWORD dwBase, int iFOV)
{
	WriteMemInt(dwBase + m_iFOV, &iFOV);
}

int LocalPlayerGetFOV(DWORD dwBase)
{
	int iFOV = 0;
	ReadMemInt(dwBase + m_iFOV, &iFOV);
	return iFOV;
}

int LocalPlayerGetEntityIdOnCrosshair(DWORD dwBase)
{
	int iID = 0;
	ReadMemInt(dwBase + m_iCrosshairId, &iID);
	return (iID - 1);
}

float LocalPlayerGetNextAttack(DWORD dwBase)
{
	float fNextAttack = 0.f;
	ReadMemFloat(dwBase + m_flNextAttack, &fNextAttack);
	return fNextAttack;
}

float LocalPlayerGetNextPrimaryAttack(DWORD dwBase)
{
	float fNextPrimaryAttack = 0.f;
	ReadMemFloat(dwBase + m_flNextPrimaryAttack, &fNextPrimaryAttack);
	return fNextPrimaryAttack;
}