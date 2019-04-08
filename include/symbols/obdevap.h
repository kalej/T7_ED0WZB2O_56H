#include <t7types.h>

#ifndef __OBDEVAP_H__
#define __OBDEVAP_H__
typedef struct obdEvapType
{
	u16 ST_IsRunning;
	u16 Status;
	u8 DiagState;
	u8 ActiveTest;
	i16 LeakageFactor;
	i8 LeakageResult;
	u8 BreakPreCondition;
	u8 BreakCondDurTest;
	i16 Ramp0;
	i32 t_Ramp1_Level1;
	i32 t_Ramp1_Level2;
	i32 t_Ramp1_Level3;
	u8 n_BrakeChanges;
	u8 n_TooMuchVapour;
	i16 p_FuelTankFilt;
	u8 n_BigLeakErrorCnt;
	u16 v_VehicleSpeedPrecondition;
	i16 HCContPrecondition;
	i16 PurgePrecondition;
	i16 LambdaPrecondition;
	i16 TotTabRamp2;
	i16 DiffR2Result[4];
	u16 p_AirAmbientDelta;
	i16 p_AirAmbStack[10];
	i16 p_PreviousPressure;
	i16 m_DeltaMax;
	i16 LambdaMaxNegDiff;
	i16 HCContDiff;
	u16 v_DiffPosMax;
	u16 v_DiffNegMax;
	i16 p_MaxPosRamp0;
	i16 p_MaxNegRamp0;
	i16 p_MaxPosRamp1;
	i16 p_MaxNegRamp1;
	i16 p_MaxPosRamp2;
	i16 p_MaxNegRamp2;
	i16 p_SwitchPoint;
} obdEvap_T;
extern obdEvap_T obdEvap;
#endif
