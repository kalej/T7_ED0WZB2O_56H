#include <t7types.h>

#ifndef __SHIFTSUPCAL_H__
#define __SHIFTSUPCAL_H__
typedef struct ShiftSupCalType
{
	i16 M_RLoadSP[5];
	i16 M_HystTab[5];
	u16 X_AccLim;
	i16 a_Offset;
} ShiftSupCal_T;
extern ShiftSupCal_T ShiftSupCal;
#endif
