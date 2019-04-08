#include <t7types.h>

#ifndef __AFTSTPROT2_H__
#define __AFTSTPROT2_H__
typedef struct AftStProt2Type
{
	u8 ST_Start;
	u8 ST_Finished;
	u16 EnrFac;
	u16 FirstFac;
	u32 DelayCnt;
	u8 DecrDelay;
} AftStProt2_T;
extern AftStProt2_T AftStProt2;
#endif
