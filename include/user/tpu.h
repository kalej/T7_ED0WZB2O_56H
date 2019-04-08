#include <t7types.h>

#ifndef TPU_H_
#define TPU_H_

typedef struct TpuChannelParamType
{
	volatile u16 p0;
	volatile u16 p1;
	volatile u16 p2;
	volatile u16 p3;
	volatile u16 p4;
	volatile u16 p5;
	volatile u16 p6;
	volatile u16 p7;
} TpuChannelParam_T;

typedef struct TpuParamsType
{
	TpuChannelParam_T ch0;
	TpuChannelParam_T ch1;
	TpuChannelParam_T ch2;
	TpuChannelParam_T ch3;
	TpuChannelParam_T ch4;
	TpuChannelParam_T ch5;
	TpuChannelParam_T ch6;
	TpuChannelParam_T ch7;
	TpuChannelParam_T ch8;
	TpuChannelParam_T ch9;
	TpuChannelParam_T ch10;
	TpuChannelParam_T ch11;
	TpuChannelParam_T ch12;
	TpuChannelParam_T ch13;
	TpuChannelParam_T ch14;
	TpuChannelParam_T ch15;
} TpuParams_T;

extern TpuParams_T* pTpuParams;

#endif /* TPU_H_ */
