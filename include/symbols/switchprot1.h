#include <t7types.h>

#ifndef __SWITCHPROT1_H__
#define __SWITCHPROT1_H__
typedef struct SwitchProt1Type
{
	u8 ST_ThrottleIdle;
	u8 ST_PedalIdle;
	u8 ST_PedalIdleOld;
	u8 ST_PedalIdleNew;
	u8 ST_Transition_0_1;
	u8 PedalDebounce;
	u32 t_SwitchErr;
	i16 A_AmbPresOff;
	i16 A_Throttle1;
	i16 A_EngTempSpeed;
	i16 A_SwitchPoint;
	u32 t_EngStartOff;
} SwitchProt1_T;
extern SwitchProt1_T SwitchProt1;
#endif
