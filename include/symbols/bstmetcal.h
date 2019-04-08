#include <t7types.h>

#ifndef __BSTMETCAL_H__
#define __BSTMETCAL_H__
typedef struct BstMetCalType
{
	u16 BoostMeter[6];
} BstMetCal_T;
extern BstMetCal_T BstMetCal;
#endif
