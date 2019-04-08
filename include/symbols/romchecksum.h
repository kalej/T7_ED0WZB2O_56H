#include <t7types.h>

#ifndef __ROMCHECKSUM_H__
#define __ROMCHECKSUM_H__
typedef struct ROMChecksumType
{
	u32 BottomOffFlash;
	u32 TopOffFlash;
	u32 TopOffProgram;
	u32 ActualChecksum;
	u16 UsedStackSize;
	u8 StackError;
	u8 Error;
	u8 EOLProgOK;
} ROMChecksum_T;
extern ROMChecksum_T ROMChecksum;
#endif
