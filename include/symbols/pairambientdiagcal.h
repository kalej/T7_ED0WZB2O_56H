#include <t7types.h>

#ifndef __PAIRAMBIENTDIAGCAL_H__
#define __PAIRAMBIENTDIAGCAL_H__
typedef struct PAirAmbientDiagCalType
{
	u16 AmbientPDevLim;
	u16 Inlet_BefThrotPDevLim;
	u16 noOfPressureReadings;
} PAirAmbientDiagCal_T;
extern PAirAmbientDiagCal_T PAirAmbientDiagCal;
#endif
