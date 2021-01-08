#include "e_HackUtils.h"

int player_on_screen(ViewMatrix view_matrix, Vector3 from)
{
	float w = 0.0f;
	w = view_matrix.v4.f1 * from.x + view_matrix.v4.f2 * from.y + view_matrix.v4.f3 * from.z + view_matrix.v4.f4;
	if (w < 0.01f) {
		return 0;
	} else {
		return 1;
	}
}

int world_to_screen(ViewMatrix view_matrix, RECT rect, Vector3 from, Vector3* to)
{
	float w = 0.0f;
	to->x = view_matrix.v1.f1 * from.x + view_matrix.v1.f2 * from.y + view_matrix.v1.f3 * from.z + view_matrix.v1.f4;
	to->y = view_matrix.v2.f1 * from.x + view_matrix.v2.f2 * from.y + view_matrix.v2.f3 * from.z + view_matrix.v2.f4;
	w = view_matrix.v4.f1 * from.x + view_matrix.v4.f2 * from.y + view_matrix.v4.f3 * from.z + view_matrix.v4.f4;
	if (w < 0.01f)
		return 0;
	float invw = 1.0f / w;
	to->x *= invw;
	to->y *= invw;
	int width = (int)(rect.right - rect.left);
	int height = (int)(rect.bottom - rect.top);
	float x = width / 2;
	float y = height / 2;
	x += 0.5 * to->x * width + 0.5;
	y -= 0.5 * to->y * height + 0.5;
	to->x = x + rect.left;
	to->y = y + rect.top;
	return 1;
}

int LocalPlayerWeaponCanAttack(DWORD dwClientState, DWORD dwPlayerBase, int iTickRate) //Default tick rate in match making == 64
{
	int iTicks = GetClientStateDeltaTicks(dwClientState);
	int iNextAttack = ((int)LocalPlayerGetNextAttack(dwPlayerBase)) * iTickRate;
	
	if (iTicks > iNextAttack) {
		return (iTicks > ((int)LocalPlayerGetNextPrimaryAttack(dwPlayerBase)) * iTickRate);	
	} else {
		return 0;
	}
}