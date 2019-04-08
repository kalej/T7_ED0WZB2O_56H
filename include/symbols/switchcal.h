#include <t7types.h>

#ifndef __SWITCHCAL_H__
#define __SWITCHCAL_H__
typedef struct SwitchCalType
{
	u32 t_SwitchErr;
	u8 PedDebouncing;
	i8 A_OffsetPoti2;
	i16 A_SwitchErrHyst;
	i16 A_Tolerance;
	i16 A_ACOffset;
	i16 A_DPOffset;
	i16 A_LDAOffset;
	i16 n_EngStartOff;
	u32 t_EngStartOff;
	i16 A_StartOffset;
	i16 A_LOffOffset;
	i16 A_ACStartOffs;
	i16 p_AmbientYSP[5];
	i16 n_EngXSP[2];
	i16 A_AmbPresMap[10];
	i16 T_Engine[8];
	i16 n_Engine[8];
	i16 A_SwitchPoint[64];
} SwitchCal_T;
extern SwitchCal_T SwitchCal;
#endif
