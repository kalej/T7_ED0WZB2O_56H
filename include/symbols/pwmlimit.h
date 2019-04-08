#include <t7types.h>

#ifndef __PWMLIMIT_H__
#define __PWMLIMIT_H__
typedef struct PwmLimitType
{
	u8 BlockAdapActive;
	u8 BlockAdapLimit;
	u8 Status;
	u8 To592LimitValue;
	u16 ms_Timer;
} PwmLimit_T;
extern PwmLimit_T PwmLimit;
#endif
