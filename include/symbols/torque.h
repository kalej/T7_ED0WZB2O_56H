#include <t7types.h>

#ifndef __TORQUE_H__
#define __TORQUE_H__
typedef struct TorqueType
{
	u8 ST_FuelCutReq;
	u8 ST_ExtTrqLim;
	u16 M_MaxEngAndGear;
	u8 ST_NoiseReduc;
	i16 M_Nominal;
	i16 fi_IgnLim;
} Torque_T;
extern Torque_T Torque;
#endif
