#include <t7types.h>

#ifndef __KNKADAPT2PROT_H__
#define __KNKADAPT2PROT_H__
typedef struct KnkAdapt2ProtType
{
	u16 ActualWindow;
	u16 IgnReduceCounter;
	u16 lastCyl;
} KnkAdapt2Prot_T;
extern KnkAdapt2Prot_T KnkAdapt2Prot;
#endif
