#include <t7types.h>

#ifndef __JERKCAL_H__
#define __JERKCAL_H__
typedef struct JerkCalType
{
	u16 T_AirInletTab[5];
	i16 T_AirInletSP[5];
	u16 p_AirAmbientTab[3];
	i16 p_AirAmbientSP[3];
	u16 n_EngineTab[6];
	i16 n_EngineSP[6];
	u32 t_JerkAbove;
	u32 t_JerkBelow;
	u16 CruiseFactor;
	u16 JerkFilter;
	u16 X_JerkTempRed;
	u16 X_OffSteadyThr;
	u16 X_AccPedalLim;
	u16 X_AccPedalDiff;
	u16 X_AccPedal4Diff;
	u16 X_AccPedal3Diff;
	u16 X_3GearFac;
	u16 X_4GearFac;
	i16 T_AirInletMin;
} JerkCal_T;
extern JerkCal_T JerkCal;
#endif
