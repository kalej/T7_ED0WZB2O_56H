#include <t7types.h>

#ifndef __AIRCOMP_H__
#define __AIRCOMP_H__
typedef struct AirCompType
{
	u16 TempComp;
	u16 P1;
	i16 RatioP1P2;
	u16 PresComp;
	u16 Comp;
	u16 LimTempComp;
	u16 LimPresComp;
	u16 LimComp;
} AirComp_T;
extern AirComp_T AirComp;
#endif
