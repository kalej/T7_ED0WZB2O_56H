#include <t7types.h>

#ifndef __BSTKNKCAL_H__
#define __BSTKNKCAL_H__
typedef struct BstKnkCalType
{
	u16 DivFacHighLoad;
	u16 DivFacLowLoad;
	u16 DivFacDelTimer;
	i16 OffsetXSP[16];
	i16 n_EngYSP[16];
	u16 MaxAirmass[256];
	u16 MaxAirmassAu[256];
	u16 NegStep;
} BstKnkCal_T;
extern BstKnkCal_T BstKnkCal;
#endif
