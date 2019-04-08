#include <t7types.h>

#ifndef __THRERR_H__
#define __THRERR_H__
typedef struct ThrErrType
{
	u8 DemandStatus;
	u8 ST_PwmLimOrdered;
	u8 ST_FuelCutOrdered;
	u8 ST_CCNotAllowed;
	i8 ST_WiperCleaner;
} ThrErr_T;
extern ThrErr_T ThrErr;
#endif
