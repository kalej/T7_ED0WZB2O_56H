#include <t7types.h>

#ifndef __TCOOLDIAGCAL_H__
#define __TCOOLDIAGCAL_H__
typedef struct TCoolDiagCalType
{
	u16 T_WarmStart;
	u16 T_hiLim;
	u16 T_negDiff;
	u16 T_posDiff;
} TCoolDiagCal_T;
extern TCoolDiagCal_T TCoolDiagCal;
#endif
