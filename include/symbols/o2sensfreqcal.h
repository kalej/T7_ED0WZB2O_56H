#include <t7types.h>

#ifndef __O2SENSFREQCAL_H__
#define __O2SENSFREQCAL_H__
typedef struct O2SensFreqCalType
{
	u16 PreNoComb1;
	u16 PreNoComb2;
	u8 PreMinFlanks;
	u32 TimeToStartTest;
	i16 lambdaLim;
	i16 n_EngineMin;
	i16 n_EngineMax;
	u32 t_CondTrueTimer;
	u16 m_AirLowLimit;
	u16 m_AirHighLimit;
	i16 PosDeltaLoadLim;
	i16 NegDeltaLoadLim;
	u16 m_CntUpAut;
	u16 m_CntDwAut;
	u16 m_CntUpMan;
	u16 m_CntDwMan;
	u8 LoadCntDown;
	u16 LoadCntLim;
	u16 FreqFltCo;
	i16 MaxLeanConstAdap;
	i16 MaxRichConstAdap;
} O2SensFreqCal_T;
extern O2SensFreqCal_T O2SensFreqCal;
#endif
