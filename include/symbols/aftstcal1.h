#include <t7types.h>

#ifndef __AFTSTCAL1_H__
#define __AFTSTCAL1_H__
typedef struct AftStCal1Type
{
	u8 ST_Enable;
	i16 T_EngineSP[15];
	u16 EnrFacTab[15];
	u16 DecrStep;
	u8 DecrDelayTab[15];
} AftStCal1_T;
extern AftStCal1_T AftStCal1;
#endif
