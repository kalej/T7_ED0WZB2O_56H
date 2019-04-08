#include <t7types.h>

#ifndef __BLOCK_H__
#define __BLOCK_H__
typedef struct BlockType
{
	u8 Timer;
	u8 Timer1;
	u8 Timer2;
	u16 AD_ThrottleDemand;
	u16 AD_ThrottleSum;
	u16 New;
	u16 Min;
	u16 Max;
	u32 ms_Counter;
	u16 AD_TmpThrBlock;
} Block_T;
extern Block_T Block;
#endif
