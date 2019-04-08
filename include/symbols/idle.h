#include <t7types.h>

#ifndef __IDLE_H__
#define __IDLE_H__
typedef struct IdleType
{
	u8 ST_Enable;
	u8 ST_AdapAllowed;
	u8 StartAirMode;
	i16 Q_Air;
	u16 n_EngineNominal;
	i16 Q_FirstDrvComp;
	i16 Q_AirFriction;
	i16 Q_LOffIgnPart;
	u8 ST_IdleRpmInAreaMap;
	i8 I_PartLimited;
	u16 DNCompIgnWeightFac;
	u16 n_EngQuote;
} Idle_T;
extern Idle_T Idle;
#endif
