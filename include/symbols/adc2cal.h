#include <t7types.h>

#ifndef __ADC2CAL_H__
#define __ADC2CAL_H__
typedef struct ADC2CalType
{
	u8 FilterConst;
	u16 MaxDiff;
	u16 MaxTime[2];
} ADC2Cal_T;
extern ADC2Cal_T ADC2Cal;
#endif
