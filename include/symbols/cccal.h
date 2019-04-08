#include <t7types.h>

#ifndef __CCCAL_H__
#define __CCCAL_H__
typedef struct CCCalType
{
	u16 M_DeltaWheelMin;
	u16 v_Threshold;
	u16 v_USDOffset;
	u16 v_USDMin;
} CCCal_T;
extern CCCal_T CCCal;
#endif
