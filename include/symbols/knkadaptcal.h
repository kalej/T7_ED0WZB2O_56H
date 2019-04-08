#include <t7types.h>

#ifndef __KNKADAPTCAL_H__
#define __KNKADAPTCAL_H__
typedef struct KnkAdaptCalType
{
	u32 AdaptPeriod;
	u32 AdaptStartDelay;
	u16 X_RefValueFilt;
	u8 ST_Qadapt;
	u8 ST_SmartGuess;
	u16 MaxRef[11];
	i16 IgnOffset;
	u16 RpmHyst;
	u16 LoadHyst;
	u16 RpmHigh;
	u16 RpmLow;
	u16 LoadHigh;
	u16 LoadLow;
	u16 ConstantTab[4];
	u16 RpmHigh2;
	u16 RpmLow2;
	u16 LoadHigh2;
	u16 LoadLow2;
	u16 RpmRefSP[2];
	u16 v_VehicleLim;
	u16 RefValueMin[2];
	i16 fi_OffsetSP[4];
	u16 FacMinHigh;
	u16 FacMaxHigh;
	u16 RefValueWind[2];
	u16 Max2Filt[2];
	u16 n_EngYSP1[4];
	u16 m_AirXSP1[4];
	u16 WeightMap1[16];
	u16 n_EngYSP2[4];
	u16 m_AirXSP2[4];
	u16 WeightMap2[16];
} KnkAdaptCal_T;
extern KnkAdaptCal_T KnkAdaptCal;
#endif
