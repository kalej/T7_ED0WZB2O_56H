#include <t7types.h>

#ifndef __THRERRPROT_H__
#define __THRERRPROT_H__
typedef struct ThrErrProtType
{
	u16 FullPWMOpen;
	u16 SpringForce;
	u8 RomErrCounter;
	u8 StackErrCounter;
	u8 ST_ThrStartup;
	u8 ST_LimpHome;
	u16 TimerDetLimp;
	u8 ST_LimSpr;
	u8 PedAdapStored;
	u16 AD_OldAccPed;
	u8 ST_DKShortCut;
	i16 AD_ThrotDiff;
	u32 t_PWMClose70;
	u32 t_PWMClose60;
	u32 t_PWMClose50;
	u32 t_PWMClose40;
	u32 t_PWMClose30;
	i16 m_AirFreeze;
	i16 m_AirMaxDelta;
	i16 m_AirMinDelta;
	i16 AD_ThrP1Fr;
	i16 AD_ThrP1MaxDelta;
	i16 AD_ThrP1MinDelta;
	i16 OutAD_ThrFr;
	i16 Pot1DiagCnt;
	u32 t_msFreeze;
} ThrErrProt_T;
extern ThrErrProt_T ThrErrProt;
#endif
