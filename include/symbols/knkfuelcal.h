#include <t7types.h>

#ifndef __KNKFUELCAL_H__
#define __KNKFUELCAL_H__
typedef struct KnkFuelCalType
{
	u16 EnrichmentMap[288];
	i16 fi_MapMaxOffset[288];
	i16 fi_MapMaxOff[256];
	i16 m_AirXSP[16];
	u16 WeightXSP[8];
	u16 WeightYSP[8];
	u16 WeightTab[64];
	u16 LambLim;
	u8 ST_RampCalc;
} KnkFuelCal_T;
extern KnkFuelCal_T KnkFuelCal;
#endif
