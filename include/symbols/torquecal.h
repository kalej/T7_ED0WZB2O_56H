#include <t7types.h>

#ifndef __TORQUECAL_H__
#define __TORQUECAL_H__
typedef struct TorqueCalType
{
	u8 ST_IgnOffsEnable;
	u8 ST_Loop;
	u8 X_CoolFactor;
	u8 M_OffsFCOStart;
	i8 M_OffsFCOStop;
	u8 M_HysIgnRedOff;
	u8 M_HysIgnRedOn;
	u16 t_DebFuelCut;
	u16 t_MaxIgnReduc;
	u16 t_ThrReaction;
	u16 t_ThrOverTime;
	i16 M_LDA1Lim;
	i16 M_LDA2Lim;
	u16 M_StallLimit;
	i16 fi_IgnMinTab[8];
	i16 T_EngSP[2];
	u16 m_FrictionAir;
	u16 M_ManGearLim[6];
	u16 M_CabGearLim[6];
	u16 m_AirXSP[18];
	u16 m_PedYSP[16];
	u16 n_EngYSP[16];
	i16 M_EngXSP[16];
	i16 fi_IgnLimMap[288];
	u8 M_IgnInflTorqMap[288];
	i16 M_NominalMap[288];
	u16 X_AccPedalMap[256];
	u16 m_AirTorqMap[256];
	u16 M_EngMaxTab[16];
	u16 M_EngMaxAutTab[16];
	u16 M_NoiseRedLim;
	u16 M_AutNoiseRedLim;
	u16 X_NoiseRedAccP;
	u16 t_NoiseRAt50km;
	u16 t_NoiseRedConst;
	u16 t_NoiseRedRamp;
	u16 v_NoiseRedMax;
	u16 v_NoiseRedMin;
	u16 n_EngSP[3];
	u16 M_ReverseTab[3];
	i16 n_EngMinSP[4];
	u16 M_BrakeLimit;
	u16 n_Eng5GearSP[16];
	u16 M_5GearLimTab[16];
	u32 ms_ShUpDelay;
	u32 ms_ShDoDelay;
	u8 ST_XAccLimRes;
	u16 X_Step;
	u16 X_MaxOffset;
	u16 X_OffsetStep;
	u16 X_OffsetStep2;
	u16 nosample;
	u32 t_gearShAct;
	u16 M_OverBoostTab[16];
	u16 M_OverBoostOffset;
	u16 M_OverBoostRamp;
	u16 m_OverBoostLevel;
	u16 t_OverBoost;
	u16 t_Cooling;
	u8 EnableOverBoost;
	u8 ST_EnableInertia;
	i16 J_InertiaMan;
	i16 J_InertiaAut;
	i16 n_Eng1GearSP[4];
	i16 M_1GearTab[4];
	i16 T_NoIgnRet;
	i16 T_NoIgnHyst;
	i16 v_TorqueCalcSP[14];
	i16 a_FreeRollingTab[14];
	i16 m_CarWeight;
} TorqueCal_T;
extern TorqueCal_T TorqueCal;
#endif
