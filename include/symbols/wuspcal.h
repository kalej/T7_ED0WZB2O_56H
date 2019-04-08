#include <t7types.h>

#ifndef __WUSPCAL_H__
#define __WUSPCAL_H__
typedef struct WUSPCalType
{
	i16 MaxTemp;
	i16 MinTemp;
	u32 Time;
} WUSPCal_T;
extern WUSPCal_T WUSPCal;
#endif
