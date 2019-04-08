#include <t7types.h>

#ifndef __TEMPTICAL_H__
#define __TEMPTICAL_H__
typedef struct TempTiCalType
{
	i16 x_axis[8];
	i16 y_axis[8];
	i16 map[64];
} TempTiCal_T;
extern TempTiCal_T TempTiCal;
#endif
