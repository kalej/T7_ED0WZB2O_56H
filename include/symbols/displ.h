#include <t7types.h>

#ifndef __DISPL_H__
#define __DISPL_H__
typedef struct DisplType
{
	u8 ST_PassengerInSeat;
	u8 ST_DriverBeltOn;
	u8 ST_PassangerBeltOn;
	u8 ST_SIDButtons;
} Displ_T;
extern Displ_T Displ;
#endif
