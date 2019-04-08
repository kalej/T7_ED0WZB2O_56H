#include <t7types.h>

#ifndef __MAXVEHICCAL_H__
#define __MAXVEHICCAL_H__
typedef struct MaxVehicCalType
{
	u8 Status;
	u16 v_Hysteresis;
	u16 v_MaxSpeed;
} MaxVehicCal_T;
extern MaxVehicCal_T MaxVehicCal;
#endif
