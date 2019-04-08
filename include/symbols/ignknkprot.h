#include <t7types.h>

#ifndef __IGNKNKPROT_H__
#define __IGNKNKPROT_H__
typedef struct IgnKnkProtType
{
	u16 KnockNumber[4];
	u16 n_Engine[4];
	u16 AdpLowLim;
	i16 fi_PartAdap;
} IgnKnkProt_T;
extern IgnKnkProt_T IgnKnkProt;
#endif
