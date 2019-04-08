#include <t7types.h>

#ifndef __LAMBDAPROT_H__
#define __LAMBDAPROT_H__
typedef struct LambdaProtType
{
	u16 ST_Restart;
	u16 MinLoad;
	u16 MaxLoadTime;
	u16 MaxLoadNorm;
	u32 RestartCnt;
	u32 MinCombCounter;
	i16 MinTempCthr;
	i16 MinTempOthr;
	u16 SwitchLimit;
	u16 N_TransDelay;
	u16 N_BeforeHW;
	u16 NrComb2;
	u16 N_SAIDelay;
	u16 HeatLoadLim;
	u32 TimeCnt;
	u16 LoadPointer;
	u16 RpmPointer;
	u16 ST_SwitchAllowed;
	u16 ST_Rich;
	u16 ST_StepDone;
	u16 NrConstI;
	i16 LambdaInt;
	u16 DecStep;
	i16 DecRamp;
	u16 DecComb;
	u16 IncStep;
	u16 IncRamp;
	u16 IncComb;
	u16 U_LamCatFilt;
	i16 LeanStep;
	i16 RichStep;
	u32 t_AdapDelay;
	u8 ST_DataInit;
	u32 LastCombNr;
	u32 N_HwCheckStamp;
	u16 NoComb;
	u16 NoCombMax;
	u32 t_HeatFront;
	u32 t_HeatRear;
	u8 HeatStateFront;
	u8 HeatStateRear;
	u32 t_FCutDelay;
	u8 ST_RampOutInt;
	u8 ST_NoEnlean;
	u32 N_BefHWStamp;
} LambdaProt_T;
extern LambdaProt_T LambdaProt;
#endif
