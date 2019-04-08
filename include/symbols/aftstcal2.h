#include <t7types.h>

#ifndef __AFTSTCAL2_H__
#define __AFTSTCAL2_H__
typedef struct AftStCal2Type
{
	u8 ST_Enable;
	i16 T_EngineSP[15];
	u16 EnrFacTab[15];
	u16 DecrStep;
	u8 DecrDelayTab[15];
} AftStCal2_T;
extern AftStCal2_T AftStCal2;
#endif
