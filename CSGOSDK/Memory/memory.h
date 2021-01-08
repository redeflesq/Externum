#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <stdio.h>

HANDLE hnMemoryHandle;

#define WriteMem(lpBaseAddress, lpSizeVar, lpBuffer) WriteProcessMemory(hnMemoryHandle, ((DWORD)(lpBaseAddress)), lpBuffer, lpSizeVar, 0)
#define ReadMem(lpBaseAddress, lpSizeVar, lpBuffer) ReadProcessMemory(hnMemoryHandle, ((DWORD)(lpBaseAddress)), lpBuffer, lpSizeVar, 0)

#define WriteMemChar(lpBaseAddress, lpBuffer) WriteMem(lpBaseAddress, sizeof(char), ((char*)lpBuffer))
#define WriteMemInt(lpBaseAddress, lpBuffer) WriteMem(lpBaseAddress, sizeof(int), ((int*)lpBuffer))
#define WriteMemFloat(lpBaseAddress, lpBuffer) WriteMem(lpBaseAddress, sizeof(float), ((float*)lpBuffer))

#define ReadMemChar(lpBaseAddress, lpBuffer) ReadMem(lpBaseAddress, sizeof(char), ((char*)lpBuffer))
#define ReadMemInt(lpBaseAddress, lpBuffer) ReadMem(lpBaseAddress, sizeof(int), ((int*)lpBuffer))
#define ReadMemFloat(lpBaseAddress, lpBuffer) ReadMem(lpBaseAddress, sizeof(float), ((float*)lpBuffer))

DWORD get_module_base_address(DWORD pID, char* moduleName);