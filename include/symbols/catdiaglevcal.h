#include <t7types.h>

#ifndef __CATDIAGLEVCAL_H__
#define __CATDIAGLEVCAL_H__
typedef struct CatDiagLevCalType
{
	i16 FirstFuelFac;
	i16 SecondFuelFac;
	i16 FirstFacTime;
	i16 Ox2LowLim;
	i16 Ox2HiLim;
	i16 OKTimeLim;
	i16 EvalFiltCoef;
	u16 ErrorLim[64];
	u16 T_CatSP[8];
	u16 m_SP[8];
	i16 T_EngLim;
	u16 m_HiLim;
	u16 m_LoLim;
	u16 n_HiLim;
	u16 n_LoLim;
	u16 t_ThrotClosed;
	u16 t_FromStartLim;
	u8 nrOfLambdaSwitches;
	u16 T_CatLim;
	u8 v_VehicleLim;
	u16 Ox2LowStartLim;
	u8 loadDec;
	u8 loadInc;
} CatDiagLevCal_T;
extern CatDiagLevCal_T CatDiagLevCal;
#endif
