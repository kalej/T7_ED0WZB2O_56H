#include <t7types.h>

#ifndef __F_KNKDETCAL_H__
#define __F_KNKDETCAL_H__
typedef struct F_KnkDetCalType
{
	i16 fi_SCEnabLim;
	i16 fi_KnkOffsLim;
	i16 p_SteadySLim;
	u16 n_SCMaxRPM;
	u16 t_IgnDetectLim;
	u16 MaxNrofNoDD;
	u16 m_AirDDMinLim;
	u16 m_AirMin;
	i8 FDCntMin;
	i8 FDCntInit;
	u8 SteadySPeriod;
	u8 SteadySPerShort;
	u8 KnkFilterVal;
	u8 EvalDelay;
	u8 X_KnkDecay;
	u8 X_AirMass;
	u8 FDCntMax;
	u8 fi_SCEnable;
} F_KnkDetCal_T;
extern F_KnkDetCal_T F_KnkDetCal;
#endif
