#include <t7types.h>

#ifndef __O2HEATPOSTCAL_H__
#define __O2HEATPOSTCAL_H__
typedef struct O2HeatPostCalType
{
	u16 I_LowLim;
	u16 I_HighLim;
} O2HeatPostCal_T;
extern O2HeatPostCal_T O2HeatPostCal;
#endif
