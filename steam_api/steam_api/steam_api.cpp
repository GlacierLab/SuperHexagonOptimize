#include <windows.h>
#include <stdio.h>
HINSTANCE mHinst = 0, mHinstDLL = 0;
UINT_PTR mProcs[59] = {0};


LPCSTR mImportNames[] = {"GetHSteamPipe", "GetHSteamUser", "SteamAPI_GetHSteamPipe", "SteamAPI_GetHSteamUser", "SteamAPI_GetSteamInstallPath", "SteamAPI_Init", "SteamAPI_InitSafe", "SteamAPI_IsSteamRunning", "SteamAPI_RegisterCallResult", "SteamAPI_RegisterCallback", "SteamAPI_RestartAppIfNecessary", "SteamAPI_RunCallbacks", "SteamAPI_SetBreakpadAppID", "SteamAPI_SetMiniDumpComment", "SteamAPI_SetTryCatchCallbacks", "SteamAPI_Shutdown", "SteamAPI_UnregisterCallResult", "SteamAPI_UnregisterCallback", "SteamAPI_UseBreakpadCrashHandler", "SteamAPI_WriteMiniDump", "SteamApps", "SteamClient", "SteamContentServer", "SteamContentServerUtils", "SteamContentServer_Init", "SteamContentServer_RunCallbacks", "SteamContentServer_Shutdown", "SteamController", "SteamFriends", "SteamGameServer", "SteamGameServerApps", "SteamGameServerHTTP", "SteamGameServerNetworking", "SteamGameServerStats", "SteamGameServerUtils", "SteamGameServer_BSecure", "SteamGameServer_GetHSteamPipe", "SteamGameServer_GetHSteamUser", "SteamGameServer_GetIPCCallCount", "SteamGameServer_GetSteamID", "SteamGameServer_Init", "SteamGameServer_InitSafe", "SteamGameServer_RunCallbacks", "SteamGameServer_Shutdown", "SteamHTTP", "SteamMatchmaking", "SteamMatchmakingServers", "SteamNetworking", "SteamRemoteStorage", "SteamScreenshots", "SteamUGC", "SteamUnifiedMessages", "SteamUser", "SteamUserStats", "SteamUtils", "Steam_GetHSteamUserCurrent", "Steam_RegisterInterfaceFuncs", "Steam_RunCallbacks", "g_pSteamClientGameServer"};
BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved ) {
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
	SetEnvironmentVariable("FNA3D_FORCE_DRIVER","Vulkan");
	mHinst = hinstDLL;
	if ( fdwReason == DLL_PROCESS_ATTACH ) {
		mHinstDLL = LoadLibrary( "ori_steam_api.dll" );
		if ( !mHinstDLL )
			return ( FALSE );
		for ( int i = 0; i < 59; i++ )
			mProcs[ i ] = (UINT_PTR)GetProcAddress( mHinstDLL, mImportNames[ i ] );
	} else if ( fdwReason == DLL_PROCESS_DETACH ) {
		FreeLibrary( mHinstDLL );
	}
	return ( TRUE );
}

extern "C" __declspec(naked) void __stdcall GetHSteamPipe_wrapper(){__asm{jmp mProcs[0*4]}}
extern "C" __declspec(naked) void __stdcall GetHSteamUser_wrapper(){__asm{jmp mProcs[1*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_GetHSteamPipe_wrapper(){__asm{jmp mProcs[2*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_GetHSteamUser_wrapper(){__asm{jmp mProcs[3*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_GetSteamInstallPath_wrapper(){__asm{jmp mProcs[4*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_Init_wrapper(){__asm{jmp mProcs[5*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_InitSafe_wrapper(){__asm{jmp mProcs[6*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_IsSteamRunning_wrapper(){__asm{jmp mProcs[7*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_RegisterCallResult_wrapper(){__asm{jmp mProcs[8*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_RegisterCallback_wrapper(){__asm{jmp mProcs[9*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_RestartAppIfNecessary_wrapper(){__asm{jmp mProcs[10*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_RunCallbacks_wrapper(){__asm{jmp mProcs[11*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_SetBreakpadAppID_wrapper(){__asm{jmp mProcs[12*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_SetMiniDumpComment_wrapper(){__asm{jmp mProcs[13*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_SetTryCatchCallbacks_wrapper(){__asm{jmp mProcs[14*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_Shutdown_wrapper(){__asm{jmp mProcs[15*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_UnregisterCallResult_wrapper(){__asm{jmp mProcs[16*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_UnregisterCallback_wrapper(){__asm{jmp mProcs[17*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_UseBreakpadCrashHandler_wrapper(){__asm{jmp mProcs[18*4]}}
extern "C" __declspec(naked) void __stdcall SteamAPI_WriteMiniDump_wrapper(){__asm{jmp mProcs[19*4]}}
extern "C" __declspec(naked) void __stdcall SteamApps_wrapper(){__asm{jmp mProcs[20*4]}}
extern "C" __declspec(naked) void __stdcall SteamClient_wrapper(){__asm{jmp mProcs[21*4]}}
extern "C" __declspec(naked) void __stdcall SteamContentServer_wrapper(){__asm{jmp mProcs[22*4]}}
extern "C" __declspec(naked) void __stdcall SteamContentServerUtils_wrapper(){__asm{jmp mProcs[23*4]}}
extern "C" __declspec(naked) void __stdcall SteamContentServer_Init_wrapper(){__asm{jmp mProcs[24*4]}}
extern "C" __declspec(naked) void __stdcall SteamContentServer_RunCallbacks_wrapper(){__asm{jmp mProcs[25*4]}}
extern "C" __declspec(naked) void __stdcall SteamContentServer_Shutdown_wrapper(){__asm{jmp mProcs[26*4]}}
extern "C" __declspec(naked) void __stdcall SteamController_wrapper(){__asm{jmp mProcs[27*4]}}
extern "C" __declspec(naked) void __stdcall SteamFriends_wrapper(){__asm{jmp mProcs[28*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_wrapper(){__asm{jmp mProcs[29*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServerApps_wrapper(){__asm{jmp mProcs[30*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServerHTTP_wrapper(){__asm{jmp mProcs[31*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServerNetworking_wrapper(){__asm{jmp mProcs[32*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServerStats_wrapper(){__asm{jmp mProcs[33*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServerUtils_wrapper(){__asm{jmp mProcs[34*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_BSecure_wrapper(){__asm{jmp mProcs[35*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_GetHSteamPipe_wrapper(){__asm{jmp mProcs[36*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_GetHSteamUser_wrapper(){__asm{jmp mProcs[37*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_GetIPCCallCount_wrapper(){__asm{jmp mProcs[38*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_GetSteamID_wrapper(){__asm{jmp mProcs[39*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_Init_wrapper(){__asm{jmp mProcs[40*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_InitSafe_wrapper(){__asm{jmp mProcs[41*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_RunCallbacks_wrapper(){__asm{jmp mProcs[42*4]}}
extern "C" __declspec(naked) void __stdcall SteamGameServer_Shutdown_wrapper(){__asm{jmp mProcs[43*4]}}
extern "C" __declspec(naked) void __stdcall SteamHTTP_wrapper(){__asm{jmp mProcs[44*4]}}
extern "C" __declspec(naked) void __stdcall SteamMatchmaking_wrapper(){__asm{jmp mProcs[45*4]}}
extern "C" __declspec(naked) void __stdcall SteamMatchmakingServers_wrapper(){__asm{jmp mProcs[46*4]}}
extern "C" __declspec(naked) void __stdcall SteamNetworking_wrapper(){__asm{jmp mProcs[47*4]}}
extern "C" __declspec(naked) void __stdcall SteamRemoteStorage_wrapper(){__asm{jmp mProcs[48*4]}}
extern "C" __declspec(naked) void __stdcall SteamScreenshots_wrapper(){__asm{jmp mProcs[49*4]}}
extern "C" __declspec(naked) void __stdcall SteamUGC_wrapper(){__asm{jmp mProcs[50*4]}}
extern "C" __declspec(naked) void __stdcall SteamUnifiedMessages_wrapper(){__asm{jmp mProcs[51*4]}}
extern "C" __declspec(naked) void __stdcall SteamUser_wrapper(){__asm{jmp mProcs[52*4]}}
extern "C" __declspec(naked) void __stdcall SteamUserStats_wrapper(){__asm{jmp mProcs[53*4]}}
extern "C" __declspec(naked) void __stdcall SteamUtils_wrapper(){__asm{jmp mProcs[54*4]}}
extern "C" __declspec(naked) void __stdcall Steam_GetHSteamUserCurrent_wrapper(){__asm{jmp mProcs[55*4]}}
extern "C" __declspec(naked) void __stdcall Steam_RegisterInterfaceFuncs_wrapper(){__asm{jmp mProcs[56*4]}}
extern "C" __declspec(naked) void __stdcall Steam_RunCallbacks_wrapper(){__asm{jmp mProcs[57*4]}}
extern "C" __declspec(naked) void __stdcall g_pSteamClientGameServer_wrapper(){__asm{jmp mProcs[58*4]}}
