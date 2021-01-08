#include "Glow.h"
#include "../../e_HackEngine.h"
#include "../Features.h"

void fGlow()
{
	DWORD dwClientState = GetClientState();
	int iLocalPlayerID = LocalPlayerGetID(dwClientState);
	DWORD dwGlowObjectManager = GetGlowObjectManager();
	ViewMatrix vmViewMatrix = GetViewMatrix();
	DWORD dwLocalPlayerBase = PlayerGetBase(iLocalPlayerID);
	Team tmLocalPlayerTeam = PlayerGetTeam(dwLocalPlayerBase);

	RGBA rgbaTeamCT = (RGBA){ 0, 0, 255, 255 };
	RGBA rgbaTeamT = (RGBA){ 255, 0, 0, 255 };

	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		if (!PlayerIsValidID(i)) {
			continue;
		}

		if (i == iLocalPlayerID) {
			continue;
		}

		DWORD dwPlayerBase = PlayerGetBase(i);

		if (dwPlayerBase == 0) {
			continue;
		}

		if (PlayerIsDormant(dwPlayerBase)) {
			continue;
		}

		if (!player_on_screen(vmViewMatrix, PlayerGetPosition(dwPlayerBase))) {
			continue;
		}

		Team tmPlayerTeam = PlayerGetTeam(dwPlayerBase);

		if (tmPlayerTeam == tmLocalPlayerTeam) {
			continue;
		}

		PlayerSetEntityGlow(
			dwGlowObjectManager,
			PlayerGetGlowIndex(dwPlayerBase),
			(tmPlayerTeam == Team_CT ? rgbaTeamCT : rgbaTeamT),
			1,
			0,
			FHandle.Visuals.Glow.bFull
		);
	}
}