#include <t7types.h>

#ifndef __KNOCKDIAGCAL_H__
#define __KNOCKDIAGCAL_H__
typedef struct KnockDiagCalType
{
	u8 nrOfCombust;
	u16 errorLevel;
} KnockDiagCal_T;
extern KnockDiagCal_T KnockDiagCal;
#endif
