#include <t7types.h>

#ifndef __IDLEDIAGCAL_H__
#define __IDLEDIAGCAL_H__
typedef struct IdleDiagCalType
{
	i16 maxLowOffset;
	i16 maxHighOffset;
	u16 errTime;
	u16 m_MaxAtLow;
	i16 n_EngDiff;
} IdleDiagCal_T;
extern IdleDiagCal_T IdleDiagCal;
#endif
