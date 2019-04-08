#include <t7types.h>

#ifndef __OBDADAPEVAP_H__
#define __OBDADAPEVAP_H__
typedef struct OBDAdapEvapType
{
	i16 EvapStack[8];
	u8 Evap2BigResDiff;
	i8 StackResult;
	i16 LeakageResult;
	u8 N_OutOfLimTemp;
} OBDAdapEvap_T;
extern OBDAdapEvap_T OBDAdapEvap;
#endif
