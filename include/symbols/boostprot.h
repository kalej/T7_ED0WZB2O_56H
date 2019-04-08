#include <t7types.h>

#ifndef __BOOSTPROT_H__
#define __BOOSTPROT_H__
typedef struct BoostProtType
{
	u8 ST_AdaptAllowed;
	u8 ST_IPartEnable;
	u8 ST_PPartEnable;
	u16 P_LoadLim;
	u16 I_LoadLim;
	u16 LoadRequest;
	i16 LoadDiff;
	i16 RegConValue;
	i16 PFac;
	i16 IFac;
	i16 DFac;
	i16 PConst;
	i16 IConst;
	i16 DConst;
	i32 IBuff;
	i16 PWMCalc;
	u16 GoalPercent;
	u16 ActPercent;
	u16 P_DiffILimReq;
	i16 ReqDerivata;
	i16 ReqDerivata100ms;
	u16 OldRequest;
	i16 OffsetHighAlt;
	i16 OffsetTemp;
	u8 ST_PWM2Perc;
	u16 Bypassmapvalue;
	u16 AntiHowlvalue;
	i16 NoiseReduction;
	u8 NoiseRedAllowed;
} BoostProt_T;
extern BoostProt_T BoostProt;
#endif
