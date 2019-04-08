#include <t7types.h>

#ifndef __PURGEPROT_H__
#define __PURGEPROT_H__
typedef struct PurgeProtType
{
	i16 AdpFreezeIndex;
	i16 FuelFacMaxFlow;
	i16 LocalMaxFlow;
	i16 PdiffMaxFlow;
	i16 RefFlow;
	i16 ReqFlow;
	i16 SetPurgePercent;
	u16 AdpFreezeTime;
	i16 m_AirDer;
	i32 TotalPurged;
	i32 FuelPurged;
	i16 LambdaFilt;
	i16 P_Fac;
	i16 I_Fac;
	i8 AdpFreeze;
	i8 RampRestart;
	i8 LocalMaxFuelFac;
	i16 PurgePercent;
	i16 FlowFac;
	i16 FlowOffsetFac;
	u8 ValveFreq;
	i16 HCContFiltFac;
	i16 ValveOffset;
	i16 BoostI_Fac;
	i16 BoostP_Fac;
} PurgeProt_T;
extern PurgeProt_T PurgeProt;
#endif
