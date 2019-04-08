#include <t7types.h>

#ifndef __RAMPPROT_H__
#define __RAMPPROT_H__
typedef struct RampProtType
{
	u8 StatusOld;
	i32 Difference;
} RampProt_T;
extern RampProt_T RampProt;
#endif
