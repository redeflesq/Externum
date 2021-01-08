#include <Windows.h>
#include <stdio.h>
#include "e_HackEngine.h"


int main()
{
	SetConsoleTitleA("Externum");

	printf("Run CSGO\n");

	e_HackCSGOHook();

	printf("CSGO Hooked.\n\n");

	printf("[F6]  [ON/OFF] - Glow\n");
	printf("[F7]  [ON/OFF] - ESP-Health\n");
	printf("[F8]  [ON/OFF] - Triggerbot\n");
	printf("[F9]  [EXIT]   - Panic Key\n");
	printf("[INS] [ON/OFF] - Sleep after glow/esp iteration\n");

	e_HackStart();
	e_HackStop();

	return 0;
}