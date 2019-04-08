#include <t7types.h>

#ifndef __KNKFUELPROT_H__
#define __KNKFUELPROT_H__
typedef struct KnkFuelProtType
{
	u16 FuelAdjust[4];
	u16 FuelTab;
	i16 fi_MaxOffset;
	u16 WeightFac1;
	u16 WeightFac2;
} KnkFuelProt_T;
extern KnkFuelProt_T KnkFuelProt;
#endif
