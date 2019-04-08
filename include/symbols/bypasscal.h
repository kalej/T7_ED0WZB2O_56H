#include <t7types.h>

#ifndef __BYPASSCAL_H__
#define __BYPASSCAL_H__
typedef struct BypassCalType
{
	u16 samples;
	u16 filtCoeff;
	u16 okDrops;
	i16 okHigh;
	i16 okLow;
	u16 limAmp;
	u16 intervals;
	u16 waitForSamp;
	u16 okAmp;
	i16 pAirDer;
	u32 releaseTime;
	u16 p_MinBefStart;
} BypassCal_T;
extern BypassCal_T BypassCal;
#endif
