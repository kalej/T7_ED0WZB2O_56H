#include <t7types.h>

#ifndef __KNKADAPT1PROT_H__
#define __KNKADAPT1PROT_H__
typedef struct KnkAdapt1ProtType
{
	u8 BufferFilled;
	u8 Finished;
	u16 MaxLevel;
	u16 FirstTimeCounter;
	u16 Counter;
	u16 Buffer[100];
	u16 RpmHyst;
	u16 LoadHyst;
	u16 RefValue;
	u8 Temp[200];
	u16 AdapFac;
} KnkAdapt1Prot_T;
extern KnkAdapt1Prot_T KnkAdapt1Prot;
#endif
