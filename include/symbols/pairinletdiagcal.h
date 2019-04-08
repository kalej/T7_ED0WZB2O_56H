#include <t7types.h>

#ifndef __PAIRINLETDIAGCAL_H__
#define __PAIRINLETDIAGCAL_H__
typedef struct PAirInletDiagCalType
{
	u16 fuelCutPressureLimit;
	u16 rpmLim;
	u16 loadLim;
	u16 Inlet_AmbientPDevLim;
	u16 Ambient_BefThrotPDevLim;
	u16 noOfPressureReadings;
	u16 noOfFuelCutPressureReadings;
} PAirInletDiagCal_T;
extern PAirInletDiagCal_T PAirInletDiagCal;
#endif
