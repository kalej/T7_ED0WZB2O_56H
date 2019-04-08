#include <t7types.h>

#ifndef __TORQUEPROT_H__
#define __TORQUEPROT_H__
typedef struct TorqueProtType
{
	i16 fi_IgnReq;
	i16 fi_IgnMin;
	i16 m_Friction;
	u16 M_NoiseReduc;
	i16 M_LowLim;
	i16 M_LimForIgnRed;
	u16 m_AirTMasLim;
	u32 t_AccumIgnRed;
	u32 t_NoiseRedTrig;
	u32 t_NoiseRedConst;
	u32 t_NoiseRedRamp;
	u32 ms_ShUp;
	u32 ms_ShDown;
	u16 X_OutAccPed;
	u16 X_OutAccPed1;
	u16 X_OutAccPed2;
	u16 X_OOutAccPed;
	u16 X_Offset;
	u16 nosample;
	u16 n_engbuf[51];
	u16 n_engfilt;
	u32 t_gearShift;
	u16 t_OverBoostTimer;
	u16 t_CoolingTimer;
	i16 M_LowInternal;
	i16 M_Rotation;
	i16 M_Total;
	i16 a_FreeRolling;
	i16 M_EngineByAcc;
	i16 M_OffsetIgn;
	i16 M_OffAirEng;
	u8 ST_TorqMastAct;
	u8 ST_LimWheelAct;
	u8 M_IgnInflTorq;
	u8 X_NewActGear;
	u8 X_OldActGear;
	u8 ST_filter_n_Eng;
	u8 manualgear;
	u8 OverBoostMode;
	u8 ST_NoIgnitionRetard;
} TorqueProt_T;
extern TorqueProt_T TorqueProt;
#endif
