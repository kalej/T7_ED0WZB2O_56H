#include <t7types.h>

#ifndef __BLOCKHEAT_H__
#define __BLOCKHEAT_H__
typedef struct BlockHeatType
{
	i16 StartFac;
	i16 AftSt2Fac;
	i16 Q_StartOffsFac;
	i16 C_PartNFac;
	i16 T_EngAirDiff;
} BlockHeat_T;
extern BlockHeat_T BlockHeat;
#endif
