#include "memory.h"

HANDLE hnMemoryHandle = NULL;

DWORD get_module_base_address(DWORD pID, char* moduleName)
{
	DWORD ModuleBaseAddress = NULL;
	HANDLE ss = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
	if (ss != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 me;
		me.dwSize = sizeof(MODULEENTRY32);

		if (Module32First(ss, &me))
		{
			do
			{
				if (!strcmp(me.szModule, moduleName))
				{
					ModuleBaseAddress = (DWORD)me.modBaseAddr;
					break;
				}
			} while (Module32Next(ss, &me));
		}
		CloseHandle(ss);
	}
	return ModuleBaseAddress;
}