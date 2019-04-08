#include <t7types.h>

#ifndef __SYNC_H__
#define __SYNC_H__
typedef struct SyncType
{
	u8 EngineCycleMode;
	u8 detect1OK;
	u8 detect2OK;
} Sync_T;
extern Sync_T Sync;
#endif
