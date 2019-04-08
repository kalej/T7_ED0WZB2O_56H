#include <t7types.h>

#ifndef __AIRCTRLCAL_H__
#define __AIRCTRLCAL_H__
typedef struct AirCtrlCalType
{
	u8 t_mReqDelay;
	u8 DirectionHyst;
	u16 x_axis[16];
	u16 y_axis[16];
	u16 map[256];
	u16 m_MaxAirTab[16];
	i16 p_DeltaInlet;
	u32 t_PedReceRel;
} AirCtrlCal_T;
extern AirCtrlCal_T AirCtrlCal;
#endif
