#include <t7types.h>

#ifndef __EVAPTESTCAL1_H__
#define __EVAPTESTCAL1_H__
typedef struct EvapTestCal1Type
{
	i16 MinTankPressure;
	u8 nrOfBrakeChangeLim;
	i16 PurgeloLim;
	i16 Level1PressureMeasurement;
	i16 Level2PressureMeasurement;
	i16 Level3PressureMeasurement;
	i16 LambdaIntLim;
	u16 HCContDiff;
	u16 v_loLim;
	u16 v_hiLim;
	u16 ramp0HiLim;
	u16 TimeForExtraPressureIncrease;
	u16 PurgeTimeForStabilePressure;
	u16 t_ramp2Eval;
	u16 t_Level1;
	u16 t_Level2;
	u16 t_Level3;
	u16 t_breakWaitTime;
	u16 PreconditionTime;
	i16 PurgeDiagFlow;
	u8 maxnrOfRamp2Eval;
	u16 pAirAmbientDelta;
	u16 v_Diff;
} EvapTestCal1_T;
extern EvapTestCal1_T EvapTestCal1;
#endif
