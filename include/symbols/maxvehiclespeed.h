#include <t7types.h>

#ifndef __MAXVEHICLESPEED_H__
#define __MAXVEHICLESPEED_H__
typedef struct MaxVehicleSpeedType
{
	u8 Status;
	u16 m_Airmass;
} MaxVehicleSpeed_T;
extern MaxVehicleSpeed_T MaxVehicleSpeed;
#endif
