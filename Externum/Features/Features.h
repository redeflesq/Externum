#pragma once

#include "../e_HackEngine.h"

#define _BOOL _Bool

struct FHandle
{
	struct FHandleAim
	{
		_BOOL bEnabled;
		struct FHandleAimTriggerbot
		{
			_BOOL bEnabled, bRevolverOnlyOnEnemy;
			int iDelay, iFiretime;
		} Triggerbot;
	} Aim;

	struct FHandleVisuals
	{
		_BOOL bEnabled;
		struct FHandleVisualsGlow
		{
			_BOOL bEnabled, bFull;
			RGBA rgbaColor;
		} Glow;
		struct FHandleVisualsESP
		{
			_BOOL bEnabled;
		} ESP;
	} Visuals;
} FHandle;

#include "Aim/Triggerbot.h"
#include "Visuals/Glow.h"
#include "Visuals/ESP.h"