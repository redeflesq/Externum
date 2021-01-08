#include "g_Engine.h"

DWORD GetClientState()
{
	DWORD _dwClientState = 0;
	ReadMemInt(engineBase + dwClientState, &_dwClientState);
	return _dwClientState;
}

ClientState GetClientStateState(DWORD dwClientState)
{
	ClientState iClientState = ClientState_Lobby;
	ReadMemInt(dwClientState + dwClientState_State, &iClientState);
	return (ClientState)(dwClientState != NULL ? iClientState : ClientState_Lobby);
}

int GetClientStateChokedCommands(DWORD dwClientState)
{
	int iChokedCommands = 0;
	ReadMemInt(dwClientState + clientstate_choked_commands, &iChokedCommands);
	return iChokedCommands;
}

int GetClientStateDeltaTicks(DWORD dwClientState)
{
	int iDeltaTicks = 0;
	ReadMemInt(dwClientState + clientstate_delta_ticks, &iDeltaTicks);
	return iDeltaTicks;
}

DWORD GetGlowObjectManager()
{
	DWORD _dwGlowObjectManager = 0;
	ReadMemInt(clientBase + dwGlowObjectManager, &_dwGlowObjectManager);
	return _dwGlowObjectManager;
}

ViewMatrix GetViewMatrix()
{
	ViewMatrix _ViewMatrix;
	//ReadProcessMemory(hnMemoryHandle, clientBase + dwViewMatrix, &_ViewMatrix, sizeof(ViewMatrix), NULL);
	ReadMem(clientBase + dwViewMatrix, sizeof(ViewMatrix), &_ViewMatrix);
	return _ViewMatrix;
}

void SetSendPackets(char bSet)
{
	WriteMemChar(engineBase + dwbSendPackets, &bSet);
}
