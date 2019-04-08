#include <t7types.h>

#ifndef __OBDHISTCOUNT_H__
#define __OBDHISTCOUNT_H__
typedef struct OBDHistCountType
{
	u16 nrOfHistoryExtraction;
	u16 QAirInlet;
	u16 PAirAmbient;
	u16 TEngine;
	u16 IdleSpeed;
	u16 EngineSync;
	u16 Catalyst;
	u16 O2SensFreq;
	u16 O2SensPre;
	u16 O2SensPost;
	u16 O2HeatPre;
	u16 O2HeatPost;
	u16 LambdaStartTime;
	u16 ShortTermFuelTrim;
	u16 LTAddFuelTrim;
	u16 LTMulFuelTrim;
	u16 MisfireCVS;
	u16 MisfireTemp;
	u16 Evap;
	u16 pTank;
	u16 FuelLevel;
	u16 BrakeLight;
	u16 PBefThrotHose;
	u16 TurboBypass;
	u16 BoostControl;
	u16 SAI;
	u16 TAirInlet;
	u16 TCoolingSystem;
} OBDHistCount_T;
extern OBDHistCount_T OBDHistCount;
#endif
