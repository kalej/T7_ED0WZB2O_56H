#include <t7types.h>

#ifndef __EXHAUSTPROT_H__
#define __EXHAUSTPROT_H__
typedef struct ExhaustProtType
{
	i16 T_Exhaust;
	i16 T_CalcDly;
	i16 T_AirMapVal;
	i16 T_RealAirVal;
	i16 T_IgnMapVal;
	i16 T_TotMapVal;
	i16 fi_Offset;
	i16 T_Limit;
	i32 T_Tau1;
	i32 T_Tau2;
	i32 T_Tau3;
	i32 T_Tau4;
} ExhaustProt_T;
extern ExhaustProt_T ExhaustProt;
#endif
