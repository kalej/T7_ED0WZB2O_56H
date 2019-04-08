#include <t7types.h>

#ifndef __RAMPCAL_H__
#define __RAMPCAL_H__
typedef struct RampCalType
{
	u16 Gradient;
} RampCal_T;
extern RampCal_T RampCal;
#endif
