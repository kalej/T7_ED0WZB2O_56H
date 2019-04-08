#include <t7types.h>

#ifndef __FCUT_H__
#define __FCUT_H__
typedef struct FCutType
{
	u8 ST_FuelCut;
	u8 CutStatus;
	u8 FuelCutCyl[4];
} FCut_T;
extern FCut_T FCut;
#endif
