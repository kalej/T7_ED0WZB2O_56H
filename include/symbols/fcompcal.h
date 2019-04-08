#include <t7types.h>

#ifndef __FCOMPCAL_H__
#define __FCOMPCAL_H__
typedef struct FCompCalType
{
	u16 FuelCompCyl[4];
} FCompCal_T;
extern FCompCal_T FCompCal;
#endif
