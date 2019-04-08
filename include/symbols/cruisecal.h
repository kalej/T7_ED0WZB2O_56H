#include <t7types.h>

#ifndef __CRUISECAL_H__
#define __CRUISECAL_H__
typedef struct CruiseCalType
{
	u8 v_NormalMode;
	u8 v_LimRampPos;
	u8 v_LimRampNeg;
	u8 ms_IntegrDelay;
	u8 ms_TCSTimer;
	u8 LoopAmount;
	u8 SetTimer;
	u8 TapUpTimer;
	u8 Status;
	u8 TipPercentage;
	u8 M_GradSize;
	u8 a_AccSize;
	u8 v_LimitSize;
	u8 a_DecTimeLim;
	i16 a_PosOffset;
	i16 a_NegOffset;
	i16 v_ResumeThresh;
	i16 v_BigDiff;
	i16 a_DecThreshold;
	u16 TipGrad;
	u16 VehicleConstant;
	u16 a_AccRequest[5];
	u16 a_DecRequest[5];
	u16 v_actual[5];
	u16 v_LimitPos[5];
	u16 v_LimitNeg[5];
	u16 v_LimitNormal[5];
	u16 v_LimitDefault;
	u16 v_RequestPos[5];
	u16 v_RequestNeg[5];
	u16 v_RequestNormal[5];
	i16 M_GradActual[7];
	i16 M_GradientPos[7];
	i16 M_GradientNeg[7];
	u16 v_DiffXSP[5];
	u16 v_ActualYSP[5];
	u16 a_DecReqMap[25];
} CruiseCal_T;
extern CruiseCal_T CruiseCal;
#endif
