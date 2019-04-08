#include <t7types.h>

#ifndef __LAMBDA_H__
#define __LAMBDA_H__
typedef struct LambdaType
{
	u16 m_LimitEngine;
	u8 ST_Enable;
	u8 ST_AdaptInc;
	u8 ST_AdaptionAllowed;
	u8 ST_ProbeTime;
	i16 LambdaInt;
	u16 TimeLean;
	u16 TimeRich;
	u32 n_NumberOfSwitch;
	u8 Status;
	i16 IntegratorBuf[4];
	u8 ST_HWDone;
	u8 ST_GasActive;
} Lambda_T;
extern Lambda_T Lambda;
#endif
