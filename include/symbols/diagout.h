#include <t7types.h>

#ifndef __DIAGOUT_H__
#define __DIAGOUT_H__
typedef struct DiagOutType
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
	i16 PWM_Purge;
	i16 PWM_BoostCntrl;
	i16 PW_X_Pedal;
	i16 PW_M_Engine;
	i16 A_Throttle;
} DiagOut_T;
extern DiagOut_T DiagOut;
#endif
