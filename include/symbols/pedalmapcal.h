#include <t7types.h>

#ifndef __PEDALMAPCAL_H__
#define __PEDALMAPCAL_H__
typedef struct PedalMapCalType
{
	i16 AD_KDLimitHigh;
	i16 AD_KDLimitLow;
	u8 ST_NoiseRed;
	u8 ST_Function;
	u16 v_VehAutSP[6];
	u16 X_AutFacTab[6];
	u16 v_VehManSP[6];
	u16 X_ManFacTab[6];
	u16 X_CabFacTab[6];
	u16 n_EngineMap[16];
	u16 X_PedalMap[16];
	u16 m_RequestMap[256];
	u16 X_PedHighLim;
	u16 X_PedLowLim;
	i16 X_PedDeltLim;
	u16 SportFactor;
} PedalMapCal_T;
extern PedalMapCal_T PedalMapCal;
#endif
