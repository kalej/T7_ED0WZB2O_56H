#include <t7types.h>

#ifndef __OUT_H__
#define __OUT_H__
typedef struct OutType
{
	u8 CMD_ThrLimpHome;
	i16 PW_X_Pedal;
	i16 PWM_BoostCntrl;
	i16 PW_M_Engine;
	u8 ST_EGasOff;
	u8 ST_Automatic;
	u8 ST_LimpHome;
	i16 PWM_Purge;
	i16 PWM_Egr;
	u8 CMD_SecAirPump;
	u8 CMD_ACRelay;
	u8 CMD_Bypass;
	u8 CMD_HeatO2SensFront;
	u8 PWM_HeatO2SensFront;
	u8 CMD_HeatO2SensRear;
	u8 PWM_HeatO2SensRear;
	u8 CMD_MainRelay;
	u8 CMD_FuelPumpRelay;
	u8 CMD_CanisterCloseVlv;
	i16 A_Throttle;
	i16 PWM_SecAirValve;
	u8 CMD_WarmUpSP;
	u8 CMD_KickDown;
	u8 CMD_CheckEngine;
	u8 CMD_ShiftUp;
	u8 CMD_CruiseLamp;
	u8 ST_CruiseActive;
	u8 CMD_CheckFillerCap;
	u8 ST_EngineStarted;
	u8 ST_ClutchBrake;
	u16 V_FuelConsumed;
	i16 X_AccPedal;
	i16 n_Engine;
	i16 n_EngineNomIdle;
	i16 M_Engine;
	i16 M_MaxAtActualRPM;
	i16 M_DTI;
	i16 T_Engine;
	i16 v_Vehicle;
	i16 p_AirBarometric;
	u8 X_BoostMeter;
	u8 X_ActualGear;
	u8 X_EngineType;
	u8 ImmoCode[6];
	i16 X_AccPedalGradient;
	i16 fi_Ignition;
	i16 fi_Injection;
	i32 t_Injection;
	i16 AD_Throttle;
	u8 CMD_WarmUpCycle;
	u8 ST_BrakeLight;
	u8 CMD_Jerk;
	u8 CMD_REP;
	u8 CMD_GearShiftInhibit;
	u8 ST_NoIgnitionRetard;
	u8 CMD_NCInhibit;
	u8 CMD_CoastLUInhibit;
} Out_T;
extern Out_T Out;
#endif
