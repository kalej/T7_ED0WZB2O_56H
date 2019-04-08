#include <t7types.h>

#ifndef __IGNKNKCAL_H__
#define __IGNKNKCAL_H__
typedef struct IgnKnkCalType
{
	u8 ST_Enable;
	i16 fi_Offset[8];
	u16 m_AirXSP[18];
	u16 n_EngYSP[16];
	i16 fi_Map1MaxOffset[16];
	i16 fi_Ramp;
	u16 ReduceTime[16];
	u16 RampTime;
	u16 AdapTimer;
	i16 IndexMap[288];
	u16 n_EngHyst;
	u16 AdpHighLimTab[16];
	u16 AdpLowLimTab[16];
	i16 MaxDiff;
	i16 MaxDiff2;
	u16 LoadLimTimer;
	i16 fi_OffsRelMax;
	i16 X_FalseDetReduce;
	u16 X_FalseDetRamp;
} IgnKnkCal_T;
extern IgnKnkCal_T IgnKnkCal;
#endif
