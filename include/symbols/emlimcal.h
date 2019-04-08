#include <t7types.h>

#ifndef __EMLIMCAL_H__
#define __EMLIMCAL_H__
typedef struct EmLimCalType
{
	i16 PedDeltaXSP[4];
	i16 X_PedYSP[8];
	u16 GearXSP[6];
	u16 AutGearXSP[6];
	u16 n_EngYSP[8];
	u16 m_MaxIncrMap[48];
	u16 m_AutMaxIncrMap[48];
	u16 RampFactorMap[32];
	u16 GrShftRatioHigh;
	u16 GrShftRatioLow;
	u16 FiltFac;
	i16 t_ClutchDelay;
	u8 ClutchMode;
} EmLimCal_T;
extern EmLimCal_T EmLimCal;
#endif
