#include <t7types.h>

#ifndef __IGNSTARTCAL_H__
#define __IGNSTARTCAL_H__
typedef struct IgnStartCalType
{
	u8 ST_Mode;
	i16 fi_StartMap[25];
	i16 T_AirSP[5];
	u16 n_EngLowLim;
	i16 n_EngXSP[5];
} IgnStartCal_T;
extern IgnStartCal_T IgnStartCal;
#endif
