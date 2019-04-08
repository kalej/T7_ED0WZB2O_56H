#include <t7types.h>

#ifndef __LOADCOCAL_H__
#define __LOADCOCAL_H__
typedef struct LoadCoCalType
{
	u16 n_EngACShtHigh;
	u16 n_EngACShtLow;
	u16 X_AccPACShtOff;
	u16 t_ACShutOff;
	u16 t_ElLoadDelay;
	u16 n_EngSP[2];
	u16 t_ElLoadRampTab[2];
	u16 p_ACSP[8];
	u16 n_EngineSP[8];
	u16 Q_ACCompAirMap[64];
	u16 Q_ACExDynAir;
	u16 t_ACRamp;
	u16 t_ACOnDlyTab[8];
	u16 t_ACOffDlyTab[8];
	u16 I_LoadSP[8];
	u16 Q_ElLoadCoTab[8];
	u8 ST_Loop;
	u8 T_ACExDynAir;
	u16 v_VehSer;
	u16 t_SerStep;
	u16 Q_NomIdleSP[8];
	u16 n_NomIdleTab[8];
	u16 Q_LimIdleAdap;
	i16 T_SerIdleSpd;
	u8 ST_PowerSteer;
	i16 n_EngXSP[4];
	i16 T_EngYSP[8];
	i16 Q_ColdFricMap[32];
	u16 Q_ACDynamicMap[64];
	u16 n_CombACCrank;
	u16 m_WCleanAir;
	u16 t_WCleanTimer;
	i16 m_WCleanMinLd;
	i16 n_WCleanMinRpm;
} LoadCoCal_T;
extern LoadCoCal_T LoadCoCal;
#endif
