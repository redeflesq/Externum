#include "g_Compares.h"

int PlayerIsValidID(int iID)
{
	if (iID > -1 && iID < MAX_PLAYERS) {
		return 1;
	} else {
		return 0;
	}
}