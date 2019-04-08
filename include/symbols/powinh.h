#include <t7types.h>

#ifndef __POWINH_H__
#define __POWINH_H__
typedef struct PowInhType
{
	u16 ST_HBridgeOff;
	u8 ST_TestPhase;
} PowInh_T;
extern PowInh_T PowInh;
#endif
