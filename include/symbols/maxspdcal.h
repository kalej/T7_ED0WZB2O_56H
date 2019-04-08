#include <t7types.h>

#ifndef __MAXSPDCAL_H__
#define __MAXSPDCAL_H__
typedef struct MaxSpdCalType
{
	i16 T_EngineSP[5];
	u16 n_EngLimAir[5];
	i16 AirOffset;
	i16 RampFac;
	u16 MaxOffset1;
	u16 MaxOffset2;
	u16 n_EngMin;
	u16 n_FuelCutOffset;
} MaxSpdCal_T;
extern MaxSpdCal_T MaxSpdCal;
#endif
