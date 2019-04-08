#include <t7types.h>

#ifndef __INJCORRCAL_H__
#define __INJCORRCAL_H__
typedef struct InjCorrCalType
{
	u16 InjectorConst;
	u16 BattCorrTab[11];
	u16 BattCorrSP[11];
} InjCorrCal_T;
extern InjCorrCal_T InjCorrCal;
#endif
