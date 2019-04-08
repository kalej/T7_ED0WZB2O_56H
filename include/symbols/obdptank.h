#include <t7types.h>

#ifndef __OBDPTANK_H__
#define __OBDPTANK_H__
typedef struct obdpTankType
{
	u8 ST_preCondRatOK;
	u8 ST_preCondElOK;
	u8 n_BrakeChanges;
	u8 ST_ReportedError;
	u8 ST_TestDone;
	u8 p_MeasurementResult;
	u16 Status;
	i32 p_FuelTankFilt;
	i32 p_FuelTankDiff;
	u16 n_FlankShift;
	i16 p_MaxTank;
	i16 p_MinTank;
} obdpTank_T;
extern obdpTank_T obdpTank;
#endif
