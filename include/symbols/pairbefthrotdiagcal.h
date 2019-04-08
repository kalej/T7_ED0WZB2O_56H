#include <t7types.h>

#ifndef __PAIRBEFTHROTDIAGCAL_H__
#define __PAIRBEFTHROTDIAGCAL_H__
typedef struct PAirBefThrotDiagCalType
{
	u16 BefThrot_AmbientPDevLim;
	u16 Ambient_InletPDevLim;
	u16 noOfPressureReadings;
} PAirBefThrotDiagCal_T;
extern PAirBefThrotDiagCal_T PAirBefThrotDiagCal;
#endif
