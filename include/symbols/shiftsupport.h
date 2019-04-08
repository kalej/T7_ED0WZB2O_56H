#include <t7types.h>

#ifndef __SHIFTSUPPORT_H__
#define __SHIFTSUPPORT_H__
typedef struct ShiftSupportType
{
	u8 ST_LimActi;
	u32 ms_TapUp;
	i16 M_LoadHyst;
} ShiftSupport_T;
extern ShiftSupport_T ShiftSupport;
#endif
