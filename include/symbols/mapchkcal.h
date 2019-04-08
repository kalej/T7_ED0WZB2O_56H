#include <t7types.h>

#ifndef __MAPCHKCAL_H__
#define __MAPCHKCAL_H__
typedef struct MapChkCalType
{
	u8 ST_Enable;
	u32 CheckSum;
} MapChkCal_T;
extern MapChkCal_T MapChkCal;
#endif
