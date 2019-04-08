#include <t7types.h>

#ifndef __IGNTEMPCAL_H__
#define __IGNTEMPCAL_H__
typedef struct IgnTempCalType
{
	u8 ST_Enable;
	u8 ST_ActiveAtIdle;
	i16 T_AirYSP[16];
	i16 T_EngYSP[16];
	i16 n_EngXSP[5];
	i16 AirMap[80];
	i16 EngMap[80];
	i16 T_AirLim;
	i16 T_EngLim;
	i16 AirLimIdle;
} IgnTempCal_T;
extern IgnTempCal_T IgnTempCal;
#endif
