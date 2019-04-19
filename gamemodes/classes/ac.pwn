/*
	AC by LukeSQLY
	for Fox-RP.pl
					*/

#include 		"classes\zmienne.inc"

#define MAX_ATTEMPS 3
#define AC_DEBUG 1


enum CheatInfo {
	vAttemps,
	vPlayer
};
new vCheat[MAX_PLAYERS][CheatInfo];




forward AC_CallDebug(playerid);
public AC_CallDebug(playerid)
{
	SCM(playerid, COLOR_RED, "debug ac");
	return 1;
}

forward AC_NotAllowedGun(playerid);
public AC_NotAllowedGun(playerid)
{
	new string[128], gunid;
	if(PlayerInfo[playerid][pAdmin] >= 1) {
		return 1;
	}
	
	if(GetPlayerWeapon(playerid) == 38) {
		format(string, sizeof(string), "Weapon hack (minigun)", GetPlayerWeapon(playerid));
		KickPlayer(playerid, "System", string);
	}
	
	if(GetPlayerWeapon(playerid) == 35) {
		format(string, sizeof(string), "Weapon hack (RPG)", GetPlayerWeapon(playerid));
		KickPlayer(playerid, "System", string);
	}
	
	if(GetPlayerWeapon(playerid) == 36) {
		format(string, sizeof(string), "Weapon hack (HSR)", GetPlayerWeapon(playerid));
		KickPlayer(playerid, "System", string);
	}
	return 1;
}


/*forward AC_CheckUsedGun(playerid);
public AC_CheckUsedGun(playerid)
{
	new string[128];
	if(IsPlayerNPC(playerid)) return 1;
    if(UsedWeap[playerid] > 1 && (GetPlayerWeapon(playerid) != UsedWeap[playerid])) {
		format(string, sizeof(string), "Weapon hack (%d)", GetPlayerWeapon(playerid));
		KickPlayer(playerid, "System", string);
    }
	
	 if(UsedWeap[playerid] > 0 && GetPlayerWeapon != 0) {
		format(string, sizeof(string), "SPWeapon hack (%d)", GetPlayerWeapon(playerid));
		KickPlayer(playerid, "System", string);
    }
	return 1;
}*/


