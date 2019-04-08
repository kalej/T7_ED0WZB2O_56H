#include <t7types.h>

#ifndef __STARTAIRCAL_H__
#define __STARTAIRCAL_H__
typedef struct StartAirCalType
{
	u16 PedalLimit;
	u16 A_EngineStill;
} StartAirCal_T;
extern StartAirCal_T StartAirCal;
#endif
