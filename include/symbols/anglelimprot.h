#include <t7types.h>

#ifndef __ANGLELIMPROT_H__
#define __ANGLELIMPROT_H__
typedef struct AngleLimProtType
{
	u8 RampActHigh;
	u8 RampActLow;
	u8 OpenDirection;
	i16 AD_Difference;
	u16 AD_ThrotOld;
	u16 AD_ThrotDem;
} AngleLimProt_T;
extern AngleLimProt_T AngleLimProt;
#endif
