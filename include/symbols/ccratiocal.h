#include <t7types.h>

#ifndef __CCRATIOCAL_H__
#define __CCRATIOCAL_H__
typedef struct CCRatioCalType
{
	u8 Hysteresis;
	u8 FilterRamp;
	u16 NotLockFactDy;
	u16 LockUpFact;
	u16 NotLockFactSt;
	u16 NotCruiseFact;
} CCRatioCal_T;
extern CCRatioCal_T CCRatioCal;
#endif
