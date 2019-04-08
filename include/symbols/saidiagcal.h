#include <t7types.h>

#ifndef __SAIDIAGCAL_H__
#define __SAIDIAGCAL_H__
typedef struct SAIDiagCalType
{
	i32 IntLim;
	i16 n_EngLow;
	i16 n_EngHigh;
	i16 m_AirLow;
	i16 m_AirHigh;
	i16 t_PreCondOK;
	i16 t_IntTestDura;
	i16 IntrIntLimit;
	i16 n_EngLowMain;
	i16 n_EngHighMain;
	i16 m_AirLowMain;
	i16 m_AirHighMain;
	i16 LambdaHigh;
	i16 LambdaLow;
	i16 v_Vehicle;
	i16 T_Eng;
	u16 N_CombStart;
	u16 N_CombDuration;
	u16 m_AirSP[4];
	u16 m_AirTab[4];
	u8 CheckPedal;
	i16 WSHLambdaHigh;
	i16 WSHLambdaLow;
	i16 T_WSHEng;
	i16 n_WSHEngLow;
	i16 n_WSHEngHigh;
	i16 m_WSHAirLow;
	i16 m_WSHAirHigh;
	i16 t_WSPreCondOK;
	i16 t_WSTestDura;
	u16 m_WSHAirTab1[4];
	u16 m_WSHAirTab2[4];
	u16 m_WSHAirSP[4];
	i16 t_IntRepeat;
	u8 n_IntAborted;
	u16 m_PosDiff;
	u16 m_NegDiff;
	i16 n_PosDiff;
	i16 n_NegDiff;
	i16 v_MainHasFailed;
} SAIDiagCal_T;
extern SAIDiagCal_T SAIDiagCal;
#endif
