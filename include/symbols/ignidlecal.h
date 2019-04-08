#include <t7types.h>

#ifndef __IGNIDLECAL_H__
#define __IGNIDLECAL_H__
typedef struct IgnIdleCalType
{
	u8 ST_Enable;
	i16 Tab[11];
	i16 fi_Idle[2];
	u16 m_AirXSP[8];
	u16 n_EngYSP[8];
	i16 fi_IdleMap[64];
	i16 n_EngDiffSP[11];
	i16 fi_MinTab[8];
	u16 n_EngMinSP[8];
	u16 TimeBefAct;
	i16 v_VehicleLim;
} IgnIdleCal_T;
extern IgnIdleCal_T IgnIdleCal;
#endif
