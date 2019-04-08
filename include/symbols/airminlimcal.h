#include <t7types.h>

#ifndef __AIRMINLIMCAL_H__
#define __AIRMINLIMCAL_H__
typedef struct AirMinLimCalType
{
	u8 ST_Loop;
	u8 X_GearFastD;
	u16 t_DashPot;
	u16 t_DPNoGear;
	u16 Q_MinLoadTab[16];
	u16 n_EngineSP[16];
	u16 m_AirXSP[8];
	u16 n_EngYSP[8];
	u16 Q_DashPotMap[64];
	i16 Q_RampStep;
	i16 n_EngUseOffset;
	u16 p_AirAmbSP[6];
	i16 p_AirAmbTab[6];
	u16 v_VehicleSP[6];
	i16 v_VehicleTab[6];
} AirMinLimCal_T;
extern AirMinLimCal_T AirMinLimCal;
#endif
