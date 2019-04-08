#include <t7types.h>

#ifndef __OBDSAI_H__
#define __OBDSAI_H__
typedef struct obdSAIType
{
	u8 DiagState;
	u8 ST_IntBreakPreCond;
	u8 ST_BreakCondDurTest;
	u8 ST_MainBreakPreCond;
	u8 ST_WSBreakPreCond;
	u8 n_IntAborted;
	u8 ST_MainTestComplete;
	u8 ST_IntrTestComplete;
	u16 Status;
	u16 m_AirAverage;
	u16 TabValue;
	i16 LambdaDiff;
	i16 t_IntTest;
	i16 n_RPMDiff;
	i16 m_LoadDiff;
	u16 m_PreCondition;
	i16 n_PreCondition;
	i16 Lambdastart;
	i16 Lambdamax;
	i16 WSDiffNoFunc;
	i16 WSDiffRedFunc;
	u32 n_AreaCombCnt;
	u32 n_AreaLastCombCnt;
	u8 ST_AreaCalcDone;
} obdSAI_T;
extern obdSAI_T obdSAI;
#endif
