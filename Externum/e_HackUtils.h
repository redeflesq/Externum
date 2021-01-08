#pragma once

#include "../CSGOSDK/sdk.h"

int player_on_screen(ViewMatrix view_matrix, Vector3 from);
int world_to_screen(ViewMatrix view_matrix, RECT rect, Vector3 from, Vector3* to);
int LocalPlayerWeaponCanAttack(DWORD dwClientState, DWORD dwPlayerBase, int iTickRate);