#include <t7types.h>

#ifndef __SYSTEMCAL_H__
#define __SYSTEMCAL_H__
typedef struct SystemCalType
{
	u16 ShutOffTime;
	u8 EngineType;
} SystemCal_T;
extern SystemCal_T SystemCal;
#endif
