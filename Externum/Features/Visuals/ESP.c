#define _CRT_SECURE_NO_WARNINGS

#include "ESP.h"
#include "../../e_HackEngine.h"
#include "../../Utils/nmath.h"

int fpESP_Players[MAX_PLAYERS];
RECT rect;
HDC hDC = NULL;

HFONT fESP_GetFont(int iSize);
void fESP_WriteText(int _Xpos, int _Ypos, char* _szMessage, COLORREF bgColor, COLORREF textColor, HFONT hfont);

void fESP_Enable()
{
	hDC = GetDC(NULL);
	SetTextAlign(hDC, TA_CENTER | TA_NOUPDATECP);
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		fpESP_Players[i] = 0;
	}
}

void fESP_Disable()
{
	free(&rect);
	free(hDC);
	free(fpESP_Players);
}

void fESP()
{
	GetWindowRect(gHWND, &rect);
	DWORD dwClientState = GetClientState();
	int iLocalPlayerID = LocalPlayerGetID(dwClientState);
	DWORD dwLocalPlayerBase = PlayerGetBase(iLocalPlayerID);
	ViewMatrix vmViewMatrix = GetViewMatrix();
	Vector3 v3LocalPlayerPos = PlayerGetPosition(dwLocalPlayerBase);
	Team tmLocalPlayerTeam = PlayerGetTeam(dwLocalPlayerBase);

	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		if (!PlayerIsValidID(i)) {
			i = 0;
		}

		if (i == iLocalPlayerID) {
			continue;
		}

		DWORD dwPlayerBase = PlayerGetBase(i);

		if (dwPlayerBase == 0) {
			continue;
		}

		Team tmPlayerTeam = PlayerGetTeam(dwPlayerBase);

		if (tmPlayerTeam == tmLocalPlayerTeam) {
			continue;
		}

		int iPlayerHealth = PlayerGetHealth(dwPlayerBase);

		if (iPlayerHealth == 0) {
			continue;
		}

		Vector3 v3PlayerPos = PlayerGetPosition(dwPlayerBase);

		if (v3PlayerPos.x == 0 && v3PlayerPos.y == 0 && v3PlayerPos.z == 0) {
			continue;
		}

		float p_pl_distance = F_DISTANCE(
			v3LocalPlayerPos.x - v3PlayerPos.x,
			v3LocalPlayerPos.y - v3PlayerPos.y
		);

		Vector3 tempCoords;

		if (PlayerIsDormant(dwPlayerBase)) {

			fpESP_Players[i]++;

			int iMaxDistance = 1000 - G_DISTANCE(p_pl_distance) * 10;

			if (iMaxDistance < 0) {
				iMaxDistance = 1;
			}

			if (fpESP_Players[i] > iMaxDistance) {
				continue;
			}
		}
		else
		{
			fpESP_Players[i] = 0;
		}

		if (world_to_screen(vmViewMatrix, rect, v3PlayerPos, &tempCoords)) {
			
			Team tmPlayerTeam = PlayerGetTeam(dwPlayerBase);

			char buf[sizeof(int)];
			snprintf(buf, sizeof buf, "%d", iPlayerHealth);

			int xl_distance = (int)G_DISTANCE(tempCoords.x - rect.left);
			int yt_distance = (int)G_DISTANCE(tempCoords.y - rect.top);

			if (xl_distance > 3 && yt_distance > 4) {
				if (tempCoords.y + 40 < rect.bottom && tempCoords.x + 30 < rect.right) {
					fESP_WriteText(
						tempCoords.x,
						tempCoords.y - 4 + G_DISTANCE(
							G_DISTANCE((rect.right - rect.left) + (rect.bottom - rect.top)) +
							G_DISTANCE(p_pl_distance)
						),
						buf,
						(tmPlayerTeam == Team_CT ? RGB(0, 0, 255) : RGB(255, 0, 0)),
						RGB(0, 255, 0),
						fESP_GetFont(12)
					);
				}
			}
		}
	}
}

HFONT fESP_GetFont(int iSize)
{
	HFONT hfont;
	LOGFONT logFont;
	memset(&logFont, 0, sizeof(LOGFONT));
	logFont.lfHeight = -iSize;
	logFont.lfWeight = FW_BOLD;
	hfont = CreateFontIndirectA(&logFont);
	return hfont;
}

void fESP_WriteText(int _Xpos, int _Ypos, char* _szMessage, COLORREF bgColor, COLORREF textColor, HFONT hfont)
{
	SetBkColor(hDC, bgColor);
	SetTextColor(hDC, textColor);
	SelectObject(hDC, hfont);
	TextOutA(hDC, _Xpos, _Ypos, _szMessage, strlen(_szMessage));
}
