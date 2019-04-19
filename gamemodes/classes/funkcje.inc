
forward ShowTuningCostMenu(playerid, componentid);
forward ShowTuningMainMenu(playerid);
forward TuningHandler();
forward GetComponentValue(componentid);
forward GetComponentSlot(componentid);
forward RemoveVehiclePaintjob(vehicleid);
forward GetComponent(vehicleid, slot);
forward SavePaintjob(vehicleid, paintjobid);
forward SaveComponent(playerid, vehicleid, componentid);
forward ShowPaintjobCostMenu(playerid, paintjobid);
forward StopPlayerTune(playerid);
forward LoadTuning(vehicleid);

AddVehicleComponentEx(vehicleid, componentid)
{
    AddVehicleComponent(vehicleid, componentid);
	new idd = FindSpawnID(vehicleid);
	for(new s = 0; s < 17; s++)
	{
	    CarInfo[idd][mod][s] = GetVehicleComponentInSlot(vehicleid, s);
	}
	saveTuning(TuneVehicle);
	return 1;
}

ChangeVehiclePaintjobEx(vehicleid, paintjobid)
{
	new idd = FindSpawnID(vehicleid);
    ChangeVehiclePaintjob(vehicleid, paintjobid);
    CarInfo[idd][paintjob] = paintjobid;
	saveTuning(TuneVehicle);
	return 1;
}



public StopPlayerTune(playerid)
{
    PlayerPlaySound(playerid, 1184, 0, 0, 0);
	KillTimer(TuneTimer);
	KillTimer(TuneHTimer);
    //SetPlayerInterior(playerid, 0);
    //LinkVehicleToInterior(TuneVehicle, 0);
    //PutPlayerInVehicle(playerid, TuneVehicle, 0);
    //SetVehiclePos(TuneVehicle, TuningLocations[TuneEntry][0], TuningLocations[TuneEntry][1], TuningLocations[TuneEntry][2]);
	TunnerID = -1;
	TuneVehicle = -1;
	SetCameraBehindPlayer(playerid);
	TogglePlayerControllable(playerid, true);
	TuneHTimer = SetTimer("TuningHandler", 15000, false);
}

public LoadTuning(vehicleid)
{
	new idd = FindSpawnID(vehicleid); 
	for(new s = 0; s < 17; s++)
	{
	    if(CarInfo[idd][mod][s] != 0)
	    {
   			AddVehicleComponentEx(vehicleid, CarInfo[idd][mod][s]);
		}
	}
	RemoveVehiclePaintjob(vehicleid);
	if(VehicleTuning[vehicleid][pjobid] == 0)
	{
		ChangeVehiclePaintjob(vehicleid, VehicleTuning[vehicleid][pjobid] - 1);
	}
}



public ShowPaintjobCostMenu(playerid, paintjobid)
{
	ChangeVehiclePaintjob(TuneVehicle, paintjobid);
    DestroyMenu(mCost);
    mCost = CreateMenu(" ", 2, 2, 150, 100, 20);
    AddMenuItem(mCost, 0, "Malunek");
    AddMenuItem(mCost, 1, "$1000");
	AddMenuItem(mCost, 0, "Anuluj");
    ShowMenuForPlayer(mCost, playerid);
    TogglePlayerControllable(playerid, false);
    TuneComponent = paintjobid;
    IsPaintJob = true;
}

public ShowTuningCostMenu(playerid, componentid)
{
    AddVehicleComponentEx(TuneVehicle, componentid);
	DestroyMenu(mCost);
	mCost = CreateMenu(" ", 2, 2, 150, 100, 20);
	AddMenuItem(mCost, 0, Components[componentid - 1000][tuneName]);
	new s[32];
	format(s, 32, "$%d", GetComponentValue(componentid));
	AddMenuItem(mCost, 1, s);
	AddMenuItem(mCost, 0, "Anuluj");
	ShowMenuForPlayer(mCost, playerid);
	TogglePlayerControllable(playerid, false);
	TuneComponent = componentid;
	IsPaintJob = false;
}

public SaveComponent(playerid, vehicleid, componentid)
{
	VehicleTuning[vehicleid][tun][GetComponentSlot(componentid)] = componentid;
	LoadTuning(vehicleid);
}

public SavePaintjob(vehicleid, paintjobid)
{
	VehicleTuning[vehicleid][pjobid] = paintjobid + 1;
}

public GetComponent(vehicleid, slot)
{
	return VehicleTuning[vehicleid][tun][slot];
}

public RemoveVehiclePaintjob(vehicleid)
{
	new idd = FindSpawnID(vehicleid);
	if(CarInfo[vehicleid][paintjob] != 3)
	{
		ChangeVehiclePaintjob(vehicleid, CarInfo[idd][paintjob]);
		//ChangeVehiclePaintjob(vehicleid, 3);
	}
	else
	{
        ChangeVehiclePaintjob(vehicleid, 3);
	}
	CallRemoteFunction("OnVehicleRemovePaintjob", "d", vehicleid);
}

public GetComponentValue(componentid)
{
    if(componentid < 1000 || componentid > 1193) return 0;
	return Components[componentid - 1000][tuneValue];
}

public GetComponentSlot(componentid)
{
	if(componentid < 1000 || componentid > 1193) return -1;
	return Components[componentid - 1000][tuneSlot];
}