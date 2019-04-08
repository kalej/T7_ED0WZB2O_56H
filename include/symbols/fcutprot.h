#include <t7types.h>

#ifndef __FCUTPROT_H__
#define __FCUTPROT_H__
typedef struct FCutProtType
{
	u16 FuelFactor;
	u16 n_Comb;
	u8 ST_AirmassGuard;
} FCutProt_T;
extern FCutProt_T FCutProt;
#endif
