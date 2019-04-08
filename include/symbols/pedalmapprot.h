#include <t7types.h>

#ifndef __PEDALMAPPROT_H__
#define __PEDALMAPPROT_H__
typedef struct PedalMapProtType
{
	u16 X_Fac;
	u16 X_AccPedal;
	i16 AD_AccPedal;
	u8 SportMode;
} PedalMapProt_T;
extern PedalMapProt_T PedalMapProt;
#endif
