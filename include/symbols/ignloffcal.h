#include <t7types.h>

#ifndef __IGNLOFFCAL_H__
#define __IGNLOFFCAL_H__
typedef struct IgnLOffCalType
{
	u8 ST_Enable;
	i16 TempLim;
	i16 T_EngineSP[12];
	u16 CombTab[12];
	u16 m_AirXSP[18];
	u16 n_EngYSP[16];
	i16 fi_MapOffset[288];
	u16 p_AirAmbLow;
	u16 p_AirAmbHigh;
	u32 n_CombAftSt;
	i16 PosRampStep;
	i16 NegRampStep;
	i16 PosDeltaLim;
	i16 NegDeltaLim;
	u8 No10msDelay;
	u8 ST_AllowRestart;
	i16 T_AirInletSP[12];
	u16 N_AirTab[12];
} IgnLOffCal_T;
extern IgnLOffCal_T IgnLOffCal;
#endif
