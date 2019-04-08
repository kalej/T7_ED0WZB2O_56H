#include <t7types.h>

#ifndef __TRANSCAL_H__
#define __TRANSCAL_H__
typedef struct TransCalType
{
	u8 ST_Enable;
	u8 ST_DecNoLim;
	i16 AccRampFac[8];
	i16 DecRampFac[8];
	i16 AccFacMap[64];
	i16 DecFacMap[64];
	i16 RpmSP[8];
	i16 AccSP[8];
	i16 DecSP[8];
	i16 AccTriggLim[8];
	i16 DecTriggLim[8];
	i16 AccTriggSP[8];
	i16 DecTriggSP[8];
	i16 AccTempFacTab[16];
	i16 DecTempFacTab[16];
	i16 T_EngineSP[16];
	u16 m_TriggMaxTab[14];
	u16 RetMul;
	u16 AccMul;
	u16 RetMulConst;
	u16 AccMulConst;
	u8 Delay1;
	u8 Delay2;
	u16 FilterConstAir[4];
	u16 n_FilterSP[3];
	i16 T_DelayLim;
	u16 n_DelayLim;
	u16 m_diffoffset;
} TransCal_T;
extern TransCal_T TransCal;
#endif
