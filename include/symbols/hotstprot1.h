#include <t7types.h>

#ifndef __HOTSTPROT1_H__
#define __HOTSTPROT1_H__
typedef struct HotStProt1Type
{
	u8 ST_Start;
	u8 ST_Finished;
	u16 EnrFac;
	u16 FirstFac;
	u32 DelayCnt;
	u8 DecrDelay;
} HotStProt1_T;
extern HotStProt1_T HotStProt1;
#endif
