#include <t7types.h>

#ifndef __BLOCKPOTI2_H__
#define __BLOCKPOTI2_H__
typedef struct BlockPoti2Type
{
	u8 Timer;
	u8 Timer1;
	u16 AD_ThrottleSum;
	u16 New;
	u16 Min;
	u16 Max;
	u32 ms_Counter;
	u16 AD_TmpThrBlock;
} BlockPoti2_T;
extern BlockPoti2_T BlockPoti2;
#endif
