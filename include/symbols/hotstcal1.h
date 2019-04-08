#include <t7types.h>

#ifndef __HOTSTCAL1_H__
#define __HOTSTCAL1_H__
typedef struct HotStCal1Type
{
	u8 ST_Enable;
	i16 T_EngineSP[15];
	u16 EnrFacTab[15];
	u16 DecrStep;
	u8 DecrDelayTab[15];
} HotStCal1_T;
extern HotStCal1_T HotStCal1;
#endif
