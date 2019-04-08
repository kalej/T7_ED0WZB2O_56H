#include <t7types.h>

#ifndef __O2SENSPOSTCAL_H__
#define __O2SENSPOSTCAL_H__
typedef struct O2SensPostCalType
{
	u16 t_LambdaLim;
	u16 t_FCutFromStart;
	u16 t_FCutLim;
	u16 U_DeadLim;
	u16 t_HeatPostDeadLim;
	i16 T_EngLim;
	u32 t_LowToHeatErrorLim;
	u32 t_LowErrorLim;
	u16 n_FCutLow;
	u16 n_FCutHigh;
	u16 m_FCutLow;
	u16 m_FCutHigh;
	u16 v_FCutLow;
	u16 v_FCutHigh;
	u16 t_FCutPedRel;
	u16 LoadFiltCoef;
	i16 PosDeltaLoadLim;
	i16 NegDeltaLoadLim;
	i16 CoolTempLim;
	u16 RpmLo;
	u16 RpmHi;
	u16 LoadLo;
	u16 LoadHi;
	i16 FuelFacMin;
	i16 FuelFacMax;
	u16 stableTimerLim;
	u16 u_ShortCut;
	i16 LambdaMax;
	i16 LambdaMin;
} O2SensPostCal_T;
extern O2SensPostCal_T O2SensPostCal;
#endif
