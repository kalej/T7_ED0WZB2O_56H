#include <t7types.h>

#ifndef __TRANSPROT2_H__
#define __TRANSPROT2_H__
typedef struct TransProt2Type
{
	u8 ST_Start;
	u8 ST_Finished;
	u16 EnrFac;
	u16 FirstFac;
	u32 DelayCnt;
	u8 DecrDelay;
} TransProt2_T;
extern TransProt2_T TransProt2;
#endif
