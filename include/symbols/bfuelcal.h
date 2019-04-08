#include <t7types.h>

#ifndef __BFUELCAL_H__
#define __BFUELCAL_H__
typedef struct BFuelCalType
{
	u16 crankFuelDelay;
	u16 AirXSP[18];
	u16 RpmYSP[16];
	u8 Map[288];
	u8 StartMap[288];
	u8 StartMapActive;
	i16 T_EngStartLowLim;
	i16 T_EngStartHighLim;
	u8 rampFac;
} BFuelCal_T;
extern BFuelCal_T BFuelCal;
#endif
