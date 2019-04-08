#include <t7types.h>

#ifndef __INJANGLCAL_H__
#define __INJANGLCAL_H__
typedef struct InjAnglCalType
{
	u8 ST_FixedAngle;
	i16 T_LimitFix;
	u16 fi_InjNoSync;
	u16 fi_InjFixed;
	u16 AirXSP[16];
	u16 RpmYSP[16];
	u16 Map[256];
} InjAnglCal_T;
extern InjAnglCal_T InjAnglCal;
#endif
