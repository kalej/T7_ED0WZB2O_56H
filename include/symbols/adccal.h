#include <t7types.h>

#ifndef __ADCCAL_H__
#define __ADCCAL_H__
typedef struct ADCCalType
{
	u8 FilterConst;
	u16 MaxDiff;
	u16 MaxTime[2];
} ADCCal_T;
extern ADCCal_T ADCCal;
#endif
