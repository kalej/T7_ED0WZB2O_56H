#include <t7types.h>

#ifndef __TRANSCAL3_H__
#define __TRANSCAL3_H__
typedef struct TransCal3Type
{
	u8 ST_Enable;
	i16 T_EngineSP[15];
	u16 EnrFacTab[15];
	u16 DecrStep;
	u8 DecrDelayTab[15];
} TransCal3_T;
extern TransCal3_T TransCal3;
#endif
