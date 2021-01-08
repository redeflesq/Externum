#pragma once

#include <Windows.h>

typedef struct RGB
{
	BYTE Red;
	BYTE Green;
	BYTE Blue;
} RGB;

typedef struct RGBA
{
	float Red;
	float Green;
	float Blue;
	float Alpha;
} RGBA;

typedef struct Vector2
{
	float x, y;
} Vector2;

typedef struct Vector3
{
	float x, y, z;
} Vector3;

typedef struct Vector4
{
	float x, y, z, w;
} Vector4;

typedef struct _p_ViewMatrix
{
	float f1, f2, f3, f4;
} _p_ViewMatrix;

typedef struct ViewMatrix
{
	_p_ViewMatrix v1, v2, v3, v4;
} ViewMatrix;

typedef enum ClientStates {
	ClientState_Lobby = 0,
	ClientState_Loading = 1,
	ClientState_Connecting = 2,
	ClientState_Connected = 5,
	ClientState_Ingame = 6
} ClientState;

typedef enum Team {
	Team_T = 2,
	Team_CT = 3
} Team;