#include <t7types.h>

#ifndef __BFUEL_H__
#define __BFUEL_H__
typedef struct BFuelType
{
	u32 CatModel;
	u16 ST_FuelFactor;
	u16 m_FuelActual;
	u8 StartMapActive;
} BFuel_T;
extern BFuel_T BFuel;
#endif
