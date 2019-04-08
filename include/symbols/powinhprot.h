#include <t7types.h>

#ifndef __POWINHPROT_H__
#define __POWINHPROT_H__
typedef struct PowInhProtType
{
	u16 ST_NewTest;
	u16 N_Readings;
	u16 N_Readings2;
	u32 I_Sum;
	u32 I_Sum2;
	u32 I_Average;
	u32 I_Average2;
} PowInhProt_T;
extern PowInhProt_T PowInhProt;
#endif
