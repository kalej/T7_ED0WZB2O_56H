#include <t7types.h>

#ifndef __DIFFPSPROT_H__
#define __DIFFPSPROT_H__
typedef struct DiffPSProtType
{
	i16 v_GearBoxOut;
	i16 v_Diff;
	i16 M_Limit;
	u32 t_StartTimer;
	u32 t_Delay;
	u8 ST_LimActive;
} DiffPSProt_T;
extern DiffPSProt_T DiffPSProt;
#endif
