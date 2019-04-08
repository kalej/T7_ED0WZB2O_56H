#include <t7types.h>

#ifndef __OBDPURGE_H__
#define __OBDPURGE_H__
typedef struct obdPurgeType
{
	u16 ST_NeedForSpeed;
	u8 BreakPreCondition;
	i16 Ramp0;
} obdPurge_T;
extern obdPurge_T obdPurge;
#endif
