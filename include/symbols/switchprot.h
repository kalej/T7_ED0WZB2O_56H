#include <t7types.h>

#ifndef __SWITCHPROT_H__
#define __SWITCHPROT_H__
typedef struct SwitchProtType
{
	u8 ST_ThrottleIdle;
	u8 ST_PedalIdle;
	u8 ST_PedalIdleOld;
	u8 ST_PedalIdleNew;
	u8 ST_Transition_0_1;
	u8 PedalDebounce;
	u32 t_SwitchErr;
	i16 A_AmbPresOff;
	i16 A_EngTempSpeed;
	i16 A_SwitchPoint;
	i16 A_ACOffset;
	i16 A_DPOffset;
	i16 A_LDAOffset;
	u32 t_EngStartOff;
	i16 A_StartOffset;
	i16 A_LOffOffset;
	i16 A_ACStartOffs;
} SwitchProt_T;
extern SwitchProt_T SwitchProt;
#endif
