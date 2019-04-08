#include <t7types.h>

#ifndef __EXHAUSTCAL_H__
#define __EXHAUSTCAL_H__
typedef struct ExhaustCalType
{
	i8 ST_Enable;
	i8 ST_JerkEnable;
	u16 t_FCutDelay;
	i16 RampFactor;
	i16 RampFactor2;
	i16 T_FCut;
	i16 t_Tau1FCut;
	i16 t_Tau2FCut;
	i16 t_Tau3FCut;
	i16 t_Tau4FCut;
	i16 t_Tau1Still;
	i16 t_Tau2Still;
	i16 T_Max;
	i16 Tau3;
	i16 Tau4;
	i16 X_WeightFac;
	i16 W_FacIgn;
	i16 n_EngineLim;
	u16 t_ShiftDelay;
	i16 Tau2_Shift;
	i16 t_Tau1Start;
	i16 t_Tau2Start;
	u16 t_StartDelay;
	i16 X_Delay;
	i16 T_LimitTab[4];
	i16 T_LimitSP[4];
	i16 m_AirSP[10];
	i16 m_AirTau1Tab[10];
	i16 m_AirTau2Tab[10];
	i16 fi_IgnSP[10];
	i16 fi_IgnMap[100];
	i16 T_ExhaustSP[20];
	i16 T_ExhaustTab[20];
	i16 T_Lambda1Map[288];
	i16 X_PedJerkLim;
	u16 m_AirJerkLim;
	i16 n_EngJerkHigh;
	i16 n_EngJerkLow;
	i16 T_Engine;
	i16 v_JerkSpdLim;
} ExhaustCal_T;
extern ExhaustCal_T ExhaustCal;
#endif
