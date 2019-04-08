#include <t7types.h>

#ifndef __O2HEATPRECAL_H__
#define __O2HEATPRECAL_H__
typedef struct O2HeatPreCalType
{
	u16 I_LowLim;
	u16 I_HighLim;
} O2HeatPreCal_T;
extern O2HeatPreCal_T O2HeatPreCal;
#endif
