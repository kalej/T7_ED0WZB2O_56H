#include <t7types.h>

#ifndef __FUELLEVELCAL_H__
#define __FUELLEVELCAL_H__
typedef struct FuelLevelCalType
{
	u16 distance;
	i16 decrease;
	u32 VolFuelTankFiltCoef;
	u16 StartVolFuelTankFiltCoef;
	u16 SpeedLimStartFiltCoef;
	u16 LoadLoLimStartFiltCoef;
	u16 LoadHiLimStartFiltCoef;
	u16 TimeLimStartFiltCoef;
	u16 FuelLevelRippleLim;
	u16 maxFuel;
	u8 V_ActivityCheck;
	u16 v_diff;
} FuelLevelCal_T;
extern FuelLevelCal_T FuelLevelCal;
#endif
