#include <t7types.h>

#ifndef __BFUELADAP_H__
#define __BFUELADAP_H__
typedef struct BFuelAdapType
{
	u32 V_FuelConsumed;
	u16 V_FuelConsMap[506];
} BFuelAdap_T;
extern BFuelAdap_T BFuelAdap;
#endif
