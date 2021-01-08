#pragma once

enum Offsets
{
    cs_gamerules_data = 0x0,
    m_ArmorValue = 0xB378,
    m_Collision = 0x320,
    m_CollisionGroup = 0x474,
    m_Local = 0x2FBC,
    m_MoveType = 0x25C,
    m_OriginalOwnerXuidHigh = 0x31C4,
    m_OriginalOwnerXuidLow = 0x31C0,
    m_SurvivalGameRuleDecisionTypes = 0x1328,
    m_SurvivalRules = 0xD00,
    m_aimPunchAngle = 0x302C,
    m_aimPunchAngleVel = 0x3038,
    m_angEyeAnglesX = 0xB37C,
    m_angEyeAnglesY = 0xB380,
    m_bBombPlanted = 0x9A5,
    m_bFreezePeriod = 0x20,
    m_bGunGameImmunity = 0x3944,
    m_bHasDefuser = 0xB388,
    m_bHasHelmet = 0xB36C,
    m_bInReload = 0x32A5,
    m_bIsDefusing = 0x3930,
    m_bIsQueuedMatchmaking = 0x74,
    m_bIsScoped = 0x3928,
    m_bIsValveDS = 0x7C,
    m_bSpotted = 0x93D,
    m_bSpottedByMask = 0x980,
    m_bStartedArming = 0x33F0,
    m_bUseCustomAutoExposureMax = 0x9D9,
    m_bUseCustomAutoExposureMin = 0x9D8,
    m_bUseCustomBloomScale = 0x9DA,
    m_clrRender = 0x70,
    m_dwBoneMatrix = 0x26A8,
    m_fAccuracyPenalty = 0x3330,
    m_fFlags = 0x104,
    m_flC4Blow = 0x2990,
    m_flCustomAutoExposureMax = 0x9E0,
    m_flCustomAutoExposureMin = 0x9DC,
    m_flCustomBloomScale = 0x9E4,
    m_flDefuseCountDown = 0x29AC,
    m_flDefuseLength = 0x29A8,
    m_flFallbackWear = 0x31D0,
    m_flFlashDuration = 0xA420,
    m_flFlashMaxAlpha = 0xA41C,
    m_flLastBoneSetupTime = 0x2924,
    m_flLowerBodyYawTarget = 0x3A90,
    m_flNextAttack = 0x2D70,
    m_flNextPrimaryAttack = 0x3238,
    m_flSimulationTime = 0x268,
    m_flTimerLength = 0x2994,
    m_hActiveWeapon = 0x2EF8,
    m_hMyWeapons = 0x2DF8,
    m_hObserverTarget = 0x338C,
    m_hOwner = 0x29CC,
    m_hOwnerEntity = 0x14C,
    m_iAccountID = 0x2FC8,
    m_iClip1 = 0x3264,
    m_iCompetitiveRanking = 0x1A84,
    m_iCompetitiveWins = 0x1B88,
    m_iCrosshairId = 0xB3E4,
    m_iEntityQuality = 0x2FAC,
    m_iFOV = 0x31E4,
    m_iFOVStart = 0x31E8,
    m_iGlowIndex = 0xA438,
    m_iHealth = 0x100,
    m_iItemDefinitionIndex = 0x2FAA,
    m_iItemIDHigh = 0x2FC0,
    m_iMostRecentModelBoneCounter = 0x2690,
    m_iObserverMode = 0x3378,
    m_iShotsFired = 0xA390,
    m_iState = 0x3258,
    m_iTeamNum = 0xF4,
    m_lifeState = 0x25F,
    m_nFallbackPaintKit = 0x31C8,
    m_nFallbackSeed = 0x31CC,
    m_nFallbackStatTrak = 0x31D4,
    m_nForceBone = 0x268C,
    m_nTickBase = 0x3430,
    m_rgflCoordinateFrame = 0x444,
    m_szCustomName = 0x303C,
    m_szLastPlaceName = 0x35B4,
    m_thirdPersonViewAngles = 0x31D8,
    m_totalRoundsPlayed = 0x64,
    m_vecOrigin = 0x138,
    m_vecVelocity = 0x114,
    m_vecViewOffset = 0x108,
    m_viewPunchAngle = 0x3020,
    anim_overlays = 0x2980,
    clientstate_choked_commands = 0x4D30,
    clientstate_delta_ticks = 0x174,
    clientstate_last_outgoing_command = 0x4D2C,
    clientstate_net_channel = 0x9C,
    convar_name_hash_table = 0x2F0F8,
    dwClientState = 0x58EFE4,
    dwClientState_GetLocalPlayer = 0x180,
    dwClientState_IsHLTV = 0x4D48,
    dwClientState_Map = 0x28C,
    dwClientState_MapDirectory = 0x188,
    dwClientState_MaxPlayer = 0x388,
    dwClientState_PlayerInfo = 0x52C0,
    dwClientState_State = 0x108,
    dwClientState_ViewAngles = 0x4D90,
    dwEntityList = 0x4DA2E14,
    dwForceAttack = 0x31D43A4,
    dwForceAttack2 = 0x31D43B0,
    dwForceBackward = 0x31D435C,
    dwForceForward = 0x31D4368,
    dwForceJump = 0x524CD74,
    dwForceLeft = 0x31D4380,
    dwForceRight = 0x31D4374,
    dwGameDir = 0x62D7F8,
    dwGameRulesProxy = 0x52C005C,
    dwGetAllClasses = 0xDB2D7C,
    dwGlobalVars = 0x58ECE8,
    dwGlowObjectManager = 0x52EB3F8,
    dwInput = 0x51F43F8,
    dwInterfaceLinkList = 0x945994,
    dwLocalPlayer = 0xD8B2BC,
    dwMouseEnable = 0xD90E60,
    dwMouseEnablePtr = 0xD90E30,
    dwPlayerResource = 0x31D26D0,
    dwRadarBase = 0x51D7B8C,
    dwSensitivity = 0xD90CFC,
    dwSensitivityPtr = 0xD90CD0,
    dwSetClanTag = 0x8A1A0,
    dwViewMatrix = 0x4D94714,
    dwWeaponTable = 0x51F4EB8,
    dwWeaponTableIndex = 0x325C,
    dwYawPtr = 0xD90AC0,
    dwZoomSensitivityRatioPtr = 0xD95D60,
    dwbSendPackets = 0xD73CA,
    dwppDirect3DDevice9 = 0xA7050,
    find_hud_element = 0x2581EED0,
    force_update_spectator_glow = 0x3AE2C2,
    interface_engine_cvar = 0x3E9EC,
    is_c4_owner = 0x3BAD80,
    m_bDormant = 0xED,
    m_flSpawnTime = 0xA370,
    m_pStudioHdr = 0x294C,
    m_pitchClassPtr = 0x51D7E28,
    m_yawClassPtr = 0xD90AC0,
    model_ambient_min = 0x59205C,
    set_abs_angles = 0x1E05B0,
    set_abs_origin = 0x1E03F0
};

enum WeaponID
{
    WEAPON_DEAGLE = 1,
    WEAPON_ELITE = 2,
    WEAPON_FIVESEVEN = 3,
    WEAPON_GLOCK = 4,
    WEAPON_AK47 = 7,
    WEAPON_AUG = 8,
    WEAPON_AWP = 9,
    WEAPON_FAMAS = 10,
    WEAPON_G3SG1 = 11,
    WEAPON_GALILAR = 13,
    WEAPON_M249 = 14,
    WEAPON_M4A1 = 16,
    WEAPON_MAC10 = 17,
    WEAPON_P90 = 19,
    WEAPON_UMP45 = 24,
    WEAPON_XM1014 = 25,
    WEAPON_BIZON = 26,
    WEAPON_MAG7 = 27,
    WEAPON_NEGEV = 28,
    WEAPON_SAWEDOFF = 29,
    WEAPON_TEC9 = 30,
    WEAPON_TASER = 31,
    WEAPON_HKP2000 = 32,
    WEAPON_MP7 = 33,
    WEAPON_MP9 = 34,
    WEAPON_NOVA = 35,
    WEAPON_P250 = 36,
    WEAPON_SCAR20 = 38,
    WEAPON_SG556 = 39,
    WEAPON_SSG08 = 40,
    WEAPON_KNIFE = 42,
    WEAPON_FLASHBANG = 43,
    WEAPON_HEGRENADE = 44,
    WEAPON_SMOKEGRENADE = 45,
    WEAPON_MOLOTOV = 46,
    WEAPON_DECOY = 47,
    WEAPON_INCGRENADE = 48,
    WEAPON_C4 = 49,
    WEAPON_KNIFE_T = 59,
    WEAPON_M4A1_SILENCER = 60,
    WEAPON_USP_SILENCER = 61,
    WEAPON_CZ75A = 63,
    WEAPON_REVOLVER = 64,
    WEAPON_KNIFE_BAYONET = 500,
    WEAPON_KNIFE_FLIP = 505,
    WEAPON_KNIFE_GUT = 506,
    WEAPON_KNIFE_KARAMBIT = 507,
    WEAPON_KNIFE_M9_BAYONET = 508,
    WEAPON_KNIFE_TACTICAL = 509,
    WEAPON_KNIFE_FALCHION = 512,
    WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
    WEAPON_KNIFE_BUTTERFLY = 515,
    WEAPON_KNIFE_PUSH = 516
};