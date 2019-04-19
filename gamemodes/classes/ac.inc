/*
	AC by LukeSQLY
	for Fox-RP.pl
					*/
#include "gamemodes/foxyrp.pwn"

#define MAX_ATTEMPS 3
#define AC_DEBUG 1

enum CheatInfo {
	vAttemps,
	vPlayer
};
new vCheat[MAX_PLAYERS][CheatInfo];


forward GetPlayerTrueID(playerid);
public GetPlayerTrueID(playerid)
{
	new string[25];
	format(string, sizeof(string), "%d", playerid);
	SCM(playerid, COLOR_RED, string);
	return string;
}



