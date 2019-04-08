#include <t7types.h>

#ifndef __TEMPLIMPOSCAL_H__
#define __TEMPLIMPOSCAL_H__
typedef struct TempLimPosCalType
{
	u16 Airmass[4];
	u16 Limit[4];
} TempLimPosCal_T;
extern TempLimPosCal_T TempLimPosCal;
#endif
