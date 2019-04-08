#include <t7types.h>

#ifndef __OBDFUELLEVEL_H__
#define __OBDFUELLEVEL_H__
typedef struct obdFuelLevelType
{
	u8 StartFilt;
	u8 ST_TestDone;
	u8 ST_ActivityCheckOK;
	u8 ST_CheckDone;
	u16 Distance;
	i16 Decrease;
	u16 V_FuelTankFilt;
	u16 V_FuelTankRef;
	i16 V_Diff;
	u16 V_Max;
	u16 V_Prev;
	u32 DistanceFromStart;
	u32 DistanceFromFault;
} obdFuelLevel_T;
extern obdFuelLevel_T obdFuelLevel;
#endif
