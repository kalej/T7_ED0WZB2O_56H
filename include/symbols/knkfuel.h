#include <t7types.h>

#ifndef __KNKFUEL_H__
#define __KNKFUEL_H__
typedef struct KnkFuelType
{
	i16 fi_MaxOff;
	u8 ST_EnableLam;
} KnkFuel_T;
extern KnkFuel_T KnkFuel;
#endif
