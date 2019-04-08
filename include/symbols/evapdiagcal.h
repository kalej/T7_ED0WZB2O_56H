#include <t7types.h>

#ifndef __EVAPDIAGCAL_H__
#define __EVAPDIAGCAL_H__
typedef struct EvapDiagCalType
{
	i16 ramp0LoPurgeLim;
	u16 Ramp1allFuelLevelRipple;
	u16 p_Ramp1MaxDiff;
	u16 purgeDiagAllowedRipple;
	u16 purgeDiagMaxPDiff;
	i16 T_HiLim;
	i16 T_LoLim;
	i16 T_Diff;
	i16 Test1Ramp2ResSP[7];
	i16 V_Test1FuelSP[7];
	i16 LeakFacTest1MAT[49];
	i16 Test2Ramp2ResSP[7];
	i16 V_Test2FuelSP[7];
	i16 LeakFacTest2MAT[49];
	u8 Ramp0allFuelLevelRipple;
	u8 p_Ramp0MaxDiff;
	u8 Ramp2allFuelLevelRipple;
	u8 p_Ramp2MaxDiff;
	u8 n_TooMuchVapourLim;
	u8 T_StartExecCtrl;
	u16 m_Delta;
	i16 maxPosR2Diff;
	i16 maxNegR2Diff;
	i16 MaxTankPressure;
	u16 m_loLim;
	u16 m_hiLim;
	i16 ramp0LoLim;
	i8 HCContFiltFac;
	i16 RampTimeUp;
	i16 V_FuelMax;
	i16 V_FuelMin;
} EvapDiagCal_T;
extern EvapDiagCal_T EvapDiagCal;
#endif
