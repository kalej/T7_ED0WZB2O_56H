#include <t7types.h>

#ifndef __MISSFPROT_H__
#define __MISSFPROT_H__
typedef struct MissfProtType
{
	u32 n_Comb1;
	u32 n_Comb2;
	u32 t_FilterActive[13];
	u16 EmissionAdditive;
	u16 OverheatAdditive;
	u16 XPos;
	u16 YPos;
	u8 lastCyl;
	u16 DetectLevelCyl[4];
	u16 DetectAvLevelCyl[4];
} MissfProt_T;
extern MissfProt_T MissfProt;
#endif
