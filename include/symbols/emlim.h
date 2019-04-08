#include <t7types.h>

#ifndef __EMLIM_H__
#define __EMLIM_H__
typedef struct EmLimType
{
	u8 ST_Active;
	u8 ST_GearShifting;
	i16 RatioDelta;
} EmLim_T;
extern EmLim_T EmLim;
#endif
