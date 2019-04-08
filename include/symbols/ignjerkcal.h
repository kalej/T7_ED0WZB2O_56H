#include <t7types.h>

#ifndef __IGNJERKCAL_H__
#define __IGNJERKCAL_H__
typedef struct IgnJerkCalType
{
	i16 fi_Basic;
	i16 n_DiffXSP[9];
	i16 fi_Tab[9];
	u16 n_LimTabSP[6];
	i16 n_LimTab[6];
	u16 N_CombPart1;
	u16 N_CombPart2;
	i16 fi_RampStep;
	i16 n_EnDelta;
	u16 X_PedalLim;
	u16 n_Comb;
	i16 T_EngLim;
} IgnJerkCal_T;
extern IgnJerkCal_T IgnJerkCal;
#endif
