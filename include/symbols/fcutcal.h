#include <t7types.h>

#ifndef __FCUTCAL_H__
#define __FCUTCAL_H__
typedef struct FCutCalType
{
	u8 ST_Enable;
	u8 ST_CutOnLowGear;
	u16 RatioLim;
	u16 n_EngLimLow;
	u16 n_EngCSLULow;
	u16 n_EngLimHigh;
	u16 n_EngCSLUHigh;
	u16 n_CombSP[10];
	u16 FuelFactor[10];
	i16 T_EngLim;
	u16 m_AirInletLimit;
	u16 m_AirInletTime;
	u16 v_VehicleLow;
	u16 v_VehicleHigh;
	u16 m_AirInlLow;
	u16 m_AirInlHigh;
	u16 t_FCutDelay;
} FCutCal_T;
extern FCutCal_T FCutCal;
#endif
