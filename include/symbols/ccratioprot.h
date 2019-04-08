#include <t7types.h>

#ifndef __CCRATIOPROT_H__
#define __CCRATIOPROT_H__
typedef struct CCRatioProtType
{
	u8 UpDirection;
	u8 DownDirection;
	u8 RatioNew;
	u8 GearRatio;
	i16 ConstDiff;
	i32 FilterOut;
	i32 FilterOutOld;
} CCRatioProt_T;
extern CCRatioProt_T CCRatioProt;
#endif
