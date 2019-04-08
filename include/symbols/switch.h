#include <t7types.h>

#ifndef __SWITCH_H__
#define __SWITCH_H__
typedef struct SwitchType
{
	u8 ST_LimActive;
	u8 ST_ErrorActive;
	u8 ST_Error;
	i16 A_Demand;
	u16 A_SwitchPoti1;
	u16 A_SwitchPoti2;
} Switch_T;
extern Switch_T Switch;
#endif
