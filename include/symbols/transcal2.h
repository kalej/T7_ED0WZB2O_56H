#include <t7types.h>

#ifndef __TRANSCAL2_H__
#define __TRANSCAL2_H__
typedef struct TransCal2Type
{
	u8 ST_Enable;
	i16 T_EngineSP[15];
	u16 EnrFacTab[15];
	u16 DecrStep;
	u8 DecrDelayTab[15];
} TransCal2_T;
extern TransCal2_T TransCal2;
#endif
