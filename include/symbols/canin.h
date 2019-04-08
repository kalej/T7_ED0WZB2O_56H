#include <t7types.h>

#ifndef __CANIN_H__
#define __CANIN_H__
typedef struct CanInType
{
	i16 v_VehicleLeftFront;
	i16 v_VehicleRightFront;
	i16 v_VehicleLeftRear;
	i16 v_VehicleRightRear;
	i8 p_Brake;
	i8 a_Lateral;
	i8 fi_SteeringAngle;
	i8 fi_YawVelocity;
	i8 ST_EngineInterv;
	i8 ST_BrakeInterv;
} CanIn_T;
extern CanIn_T CanIn;
#endif
