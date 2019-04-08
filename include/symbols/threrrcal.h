#include <t7types.h>

#ifndef __THRERRCAL_H__
#define __THRERRCAL_H__
typedef struct ThrErrCalType
{
	i16 PedalDeltaLimit;
	i16 ThrDeltaLimit;
	u16 PedSensLim[2];
	u16 Ped2SensLim;
	u16 PedSensSum[2];
	u16 AdapSumErr[2];
	u16 PedMutAff[2];
	u16 P2SwitchErr;
	u16 DkSensLim[2];
	u16 DkSens2Lim;
	u16 ThrSensSum[2];
	u16 FullPWMClose;
	u16 FullPWMOpen;
	u16 StackOver;
	u16 ROMCheck;
	u16 SerCom;
	u16 SwMon339;
	u16 SpringForce;
	u16 I_Lim100PerOpen;
	u16 n_FCutAtLH;
	u16 n_NoFCutAtLH;
	u16 t_FullPWMNoI;
	u32 t_HBShortCut;
	u16 AD_ThrotDiff;
	u16 t_ThrSumLimp;
	u16 t_ThrSumInfo;
	i8 ThrPotSumDiff;
	i16 m_AirDeltaLim;
	i16 AD_ThrP1MaxLimit;
	i16 n_EngineLim;
	u16 t_Steady;
	i16 m_AirDiff;
	i16 OutAD_ThrMaxD;
	i16 ErrorCntLim;
} ThrErrCal_T;
extern ThrErrCal_T ThrErrCal;
#endif
