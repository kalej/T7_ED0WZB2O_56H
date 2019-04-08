#include <t7types.h>

#ifndef __SPEEDDIAGCAL_H__
#define __SPEEDDIAGCAL_H__
typedef struct SpeedDiagCalType
{
	u16 accumPeriod;
	u16 loadLim;
	u16 RPMLim;
	i16 T_EngLim;
} SpeedDiagCal_T;
extern SpeedDiagCal_T SpeedDiagCal;
#endif
