#include <t7types.h>

#ifndef __APP7CAL_H__
#define __APP7CAL_H__
typedef struct App7CalType
{
	u8 ST_DubbelInjection;
	u16 m_FuelActual;
	i16 X_AccPedReq;
	i16 X_AccPedReqHigh;
	i16 X_AccPedReqLow;
	i32 t_Ramp;
	i16 t_HighLevel;
	i16 t_LowLevel;
	u8 ST_PedalLoop;
	u8 X_StepCycles;
	u8 AirMode;
	i16 m_Request;
	i16 fi_Ignition;
	i16 A_Throttle;
	i16 PWM_BoostCntrl;
	u8 FuelMode;
	u8 IgnMode;
	u16 FuelFactor;
} App7Cal_T;
extern App7Cal_T App7Cal;
#endif
