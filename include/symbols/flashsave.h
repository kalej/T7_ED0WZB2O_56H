#include <t7types.h>

#ifndef __FLASHSAVE_H__
#define __FLASHSAVE_H__
typedef struct FlashSaveType
{
	u8 ST_GasHybridAct;
	u8 KnkSoundRedFac;
	u8 ST_ShiftUpLamp;
	i16 Tech2IdleOffset;
	i16 RpmMaxFreeze[7];
} FlashSave_T;
extern FlashSave_T FlashSave;
#endif
