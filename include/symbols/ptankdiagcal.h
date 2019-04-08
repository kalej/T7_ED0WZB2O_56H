#include <t7types.h>

#ifndef __PTANKDIAGCAL_H__
#define __PTANKDIAGCAL_H__
typedef struct pTankDiagCalType
{
	u16 measurementTime;
	u16 maxNrOfFlankShifts;
	i16 maxPressureDiff;
	i16 V_FuelMax;
	i16 V_FuelMin;
	i16 compLim;
} pTankDiagCal_T;
extern pTankDiagCal_T pTankDiagCal;
#endif
