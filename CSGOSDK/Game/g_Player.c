#include "g_Player.h"

DWORD PlayerGetBase(int iID)
{
	DWORD dwBase = 0;
	ReadMemInt(clientBase + dwEntityList + iID * 16, &dwBase);
	return dwBase;
}

int PlayerGetFlag(DWORD dwBase)
{
	int iFlag = 0;
	ReadMemInt(dwBase + m_fFlags, &iFlag);
	return iFlag;
}

int PlayerGetHealth(DWORD dwBase)
{
	int iHealth = 0;
	ReadMemInt(dwBase + m_iHealth, &iHealth);
	return iHealth;
}

int PlayerGetArmor(DWORD dwBase)
{
	int iArmor = 0;
	ReadMemInt(dwBase + m_ArmorValue, &iArmor);
	return iArmor;
}

Vector3 PlayerGetPosition(DWORD dwBase)
{
	Vector3 v3Position = (Vector3){0.f,0.f,0.f};
	ReadMemFloat(dwBase + m_vecOrigin + 0, &v3Position.x);
	ReadMemFloat(dwBase + m_vecOrigin + 4, &v3Position.y);
	ReadMemFloat(dwBase + m_vecOrigin + 8, &v3Position.z);
	return v3Position;
}

int PlayerGetGlowIndex(DWORD dwBase)
{
	int iGlowIndex = 0;
	ReadMemInt(dwBase + m_iGlowIndex, &iGlowIndex);
	return iGlowIndex;
}

void PlayerSetEntityGlow(DWORD dwGlowObjectManager, int iGlowIndex, RGBA RGBA, int Occluded, int UnOccluded, int Full)
{
	RGBA.Red = RGBA.Red / 255;
	RGBA.Green = RGBA.Green / 255;
	RGBA.Blue = RGBA.Blue / 255;
	RGBA.Alpha = RGBA.Alpha / 255;

	WriteMemFloat(dwGlowObjectManager + iGlowIndex * 0x38 + 0x4, &(RGBA.Red));
	WriteMemFloat(dwGlowObjectManager + iGlowIndex * 0x38 + 0x8, &(RGBA.Green));
	WriteMemFloat(dwGlowObjectManager + iGlowIndex * 0x38 + 0xC, &(RGBA.Blue));
	WriteMemFloat(dwGlowObjectManager + iGlowIndex * 0x38 + 0x10, &(RGBA.Alpha));
	WriteMemInt(dwGlowObjectManager + iGlowIndex * 0x38 + 0x24, &(Occluded));
	WriteMemInt(dwGlowObjectManager + iGlowIndex * 0x38 + 0x25, &(UnOccluded));
	WriteMemInt(dwGlowObjectManager + iGlowIndex * 0x38 + 0x26, &(Full));
}

Team PlayerGetTeam(DWORD dwBase)
{
	Team tmTeam;
	ReadMemInt(dwBase + m_iTeamNum, &tmTeam);
	return tmTeam;
}

float PlayerGetSpawnTime(DWORD dwBase)
{
	float fSpawnTime = 0;
	ReadMemFloat(dwBase + m_flSpawnTime, &fSpawnTime);
	return fSpawnTime;
}

DWORD PlayerWeaponGetActive(DWORD dwBase)
{
	DWORD iActiveWeapon = 0;
	ReadMemInt(dwBase + m_hActiveWeapon, &iActiveWeapon);
	iActiveWeapon = iActiveWeapon & 0xFFF;
	return iActiveWeapon;
}

DWORD PlayerWeaponGetEntity(DWORD dwActiveWeapon)
{
	DWORD dwWeaponEntity = 0;
	ReadMemInt(clientBase + dwEntityList + (dwActiveWeapon - 1) * 0x10, &dwWeaponEntity);
	return dwWeaponEntity;
}

int PlayerWeaponGetDefinitionIndex(DWORD dwWeaponEntity) // Skin ID
{
	int iDefinitionIndex = 0;
	ReadMemInt(dwWeaponEntity + m_iItemDefinitionIndex, &iDefinitionIndex);
	return iDefinitionIndex;
}

int PlayerWeaponGetID(int iDefinitionIndex)
{
	return iDefinitionIndex & 0xFFFF;
}

int PlayerIsDormant(DWORD dwBase)
{
	int bDormant = 0;
	ReadMemInt(dwBase + m_bDormant, &bDormant);
	return bDormant;
}
