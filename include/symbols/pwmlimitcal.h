#include <t7types.h>

#ifndef __PWMLIMITCAL_H__
#define __PWMLIMITCAL_H__
typedef struct PwmLimitCalType
{
	u16 Size;
	u16 U_Batt[4];
	u8 PwmLimit[4];
	u16 ms_Time;
	u8 ms_Decrement;
} PwmLimitCal_T;
extern PwmLimitCal_T PwmLimitCal;
#endif
