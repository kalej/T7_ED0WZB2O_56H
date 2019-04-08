#include <t7types.h>

#ifndef __SYNCPROT_H__
#define __SYNCPROT_H__
typedef struct SyncProtType
{
	u8 DetectOkCnt;
	u16 lastCyl;
} SyncProt_T;
extern SyncProt_T SyncProt;
#endif
