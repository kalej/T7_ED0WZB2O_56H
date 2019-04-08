#include <t7types.h>

#ifndef __SWITCH1_H__
#define __SWITCH1_H__
typedef struct Switch1Type
{
	u8 ST_LimActive;
	u8 ST_ErrorActive;
	u8 ST_Error;
	i16 A_Demand;
} Switch1_T;
extern Switch1_T Switch1;
#endif
