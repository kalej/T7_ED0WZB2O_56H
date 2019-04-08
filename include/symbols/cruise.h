#include <t7types.h>

#ifndef __CRUISE_H__
#define __CRUISE_H__
typedef struct CruiseType
{
	u8 CruiseStatus;
	u8 Set;
	u8 DecLimitActiv;
	u8 CC_Valid;
	u8 CC_Allowed339;
	u8 CC_Allowed339Old;
	u8 CC_Allowed592;
	u8 CC_592Valid;
	u8 VMinStatus1;
	u8 VMinStatus2;
	u8 GearRatio;
	i32 M_RoadLoad1;
	u8 ST_ResumeMode;
	i16 a_Actual;
} Cruise_T;
extern Cruise_T Cruise;
#endif
