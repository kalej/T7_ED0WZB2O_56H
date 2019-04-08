#include <t7types.h>

#ifndef __ANGLE_H__
#define __ANGLE_H__
typedef struct AngleType
{
	u16 AD_ThrottleDemand;
	u16 ThrottleOut;
	u16 ThrottleFilterIn;
	u32 ThrottleFilterOld;
	u32 ThrottleFilterOut;
} Angle_T;
extern Angle_T Angle;
#endif
