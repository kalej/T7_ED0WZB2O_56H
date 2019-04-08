#include <t7types.h>

#ifndef __EXHAUST_H__
#define __EXHAUST_H__
typedef struct ExhaustType
{
	u32 SumNorm;
	u32 SumAlg;
	i16 RampValue;
	i16 RampValue2;
	u16 FuelNormFac;
	u16 ActualFac;
	u16 Lambda1Fac;
	i16 Status;
	i16 T_Calc;
	i8 ST_Enable;
} Exhaust_T;
extern Exhaust_T Exhaust;
#endif
