#include <t7types.h>

#ifndef __TRANSPROT3_H__
#define __TRANSPROT3_H__
typedef struct TransProt3Type
{
	u8 ST_Start;
	u8 ST_Finished;
	u16 EnrFac;
	u16 FirstFac;
	u32 DelayCnt;
	u8 DecrDelay;
} TransProt3_T;
extern TransProt3_T TransProt3;
#endif
