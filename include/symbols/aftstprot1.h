#include <t7types.h>

#ifndef __AFTSTPROT1_H__
#define __AFTSTPROT1_H__
typedef struct AftStProt1Type
{
	u8 ST_Start;
	u8 ST_Finished;
	u16 EnrFac;
	u16 FirstFac;
	u32 DelayCnt;
	u8 DecrDelay;
} AftStProt1_T;
extern AftStProt1_T AftStProt1;
#endif
