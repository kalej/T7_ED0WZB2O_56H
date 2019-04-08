#include <t7types.h>

#ifndef __TENGDIAGCAL_H__
#define __TENGDIAGCAL_H__
typedef struct TEngDiagCalType
{
	i16 n_CombSP[11];
	i16 T_AirInletSP[11];
	u16 m_AirperDegManual[121];
	u16 m_AirperDegAutomatic[121];
	u16 n_CombFactTAB[8];
	i16 T_startSP[8];
	i16 m_LoadFacSP[5];
	i16 m_LoadFacTAB[5];
	u8 n_deadDiffLim;
	u16 n_deadCombLim;
	u8 QCMeanErrLim;
	u8 QCErrLim;
	u8 T_startComp;
	u8 X_AutGearFac;
	i16 T_MaxLimphome;
	i16 T_LimForMaxLimp;
} TEngDiagCal_T;
extern TEngDiagCal_T TEngDiagCal;
#endif
