#include <t7types.h>

#ifndef __SAICAL_H__
#define __SAICAL_H__
typedef struct SAICalType
{
	u16 m_AirXSP[8];
	u16 n_EngineYSP[8];
	i16 FuellingMap[64];
	i16 T_EngineSP[10];
	u16 m_AirInletLimit;
	u16 N_PumpStart[10];
	u16 N_PumpStop;
	u16 N_FuellingStart[10];
	u16 N_ClosedLoopDelay[10];
	u8 Testmode;
	u16 t_RampTimePos;
	u16 t_RampTimeNeg;
	u16 p_AltCompSP[5];
	i16 AltComp[5];
	i16 T_MinAirInlet;
	i16 T_MaxAirInlet;
	u16 m_AirSAIMAP[40];
	u16 m_AirInjReq[10];
	u16 N_SAIPumpDelay;
	u16 m_AirLimLeanClamp;
} SAICal_T;
extern SAICal_T SAICal;
#endif
