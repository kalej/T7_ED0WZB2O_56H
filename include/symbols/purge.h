#include <t7types.h>

#ifndef __PURGE_H__
#define __PURGE_H__
typedef struct PurgeType
{
	u8 ST_TankDiag;
	u8 SAI_IntrStatus;
	u8 ST_StartRamp;
	u8 ValveFreqEvap;
	i8 ST_FastAdp;
	i8 Status;
	i16 Valve;
	i16 FuelFac;
	i16 Flow;
	i16 DiagFlow;
	i16 HCCont;
	i16 LambdaFiltEvap;
	i16 AdaptionEvap;
	i16 Q_AirPrg;
	i16 m_AirPrg;
	i16 m_FuelPrg;
} Purge_T;
extern Purge_T Purge;
#endif
