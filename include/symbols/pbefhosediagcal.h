#include <t7types.h>

#ifndef __PBEFHOSEDIAGCAL_H__
#define __PBEFHOSEDIAGCAL_H__
typedef struct PBefHoseDiagCalType
{
	u16 n_EngLim;
	u16 P_DiffInletLim;
	u16 P_DiffBefLim;
	u16 errorTimeLim;
} PBefHoseDiagCal_T;
extern PBefHoseDiagCal_T PBefHoseDiagCal;
#endif
