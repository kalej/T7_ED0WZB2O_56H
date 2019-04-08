#include <t7types.h>

#ifndef __DIAGACTIVE_H__
#define __DIAGACTIVE_H__
typedef struct DiagActiveType
{
	u8 CMD_Bypass;
	u8 CMD_SecAirPump;
	u8 CMD_CanisterCloseVlv;
	u8 PWM_SecAirValve;
	u8 CMD_MainRelay;
	u8 CMD_FuelPumpRelay;
	u8 PWM_HeatO2SensFront;
	u8 PWM_HeatO2SensRear;
	u8 CMD_ACRelay;
	u8 X_BoostMeter;
	u8 fi_Ignition;
	u8 t_Injection;
	u8 CMD_ThrLimpHome;
	u8 PWM_Purge;
	u8 PWM_BoostCntrl;
	u8 PW_X_Pedal;
	u8 PW_M_Engine;
	u8 A_Throttle;
} DiagActive_T;
extern DiagActive_T DiagActive;
#endif
