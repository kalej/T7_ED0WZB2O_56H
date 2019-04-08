#include <t7types.h>

#ifndef __BLOCK2_H__
#define __BLOCK2_H__
typedef struct Block2Type
{
	u8 FCOActive;
	u8 ThrottleON;
} Block2_T;
extern Block2_T Block2;
#endif
