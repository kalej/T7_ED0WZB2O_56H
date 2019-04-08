#include <t7types.h>

#ifndef __O2SPRECAL_H__
#define __O2SPRECAL_H__
typedef struct O2SPreCalType
{
	i16 T_O2SFrontTemp[4];
	i16 t_O2SFrontTime[4];
	u16 u_ShortCut;
	u32 t_LowToHeatErrorLim;
} O2SPreCal_T;
extern O2SPreCal_T O2SPreCal;
#endif
