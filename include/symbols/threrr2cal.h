#include <t7types.h>

#ifndef __THRERR2CAL_H__
#define __THRERR2CAL_H__
typedef struct ThrErr2CalType
{
	i16 PedalDeltaLimit;
	i16 ThrDeltaLimit;
	u16 PedSensSum[2];
	u16 AdapSumErr[2];
	u16 PedMutAff[2];
	u16 ThrSensSum[2];
	u16 StackOver;
	u16 ROMCheck;
	u16 t_ThrSumLimp;
	u16 t_ThrSumInfo;
	i8 ThrPotSumDiff;
} ThrErr2Cal_T;
extern ThrErr2Cal_T ThrErr2Cal;
#endif
