#include <t7types.h>

#ifndef __DNCOMP_H__
#define __DNCOMP_H__
typedef struct DNCompType
{
	i16 Q_AirExtra;
	i16 fi_OffsetPnt;
	i16 fi_Offset;
	i16 fi_NCOffset;
	u8 ST_NeutralControl;
	i16 C_Part[2];
	u8 IgnRampType;
	u32 IgnRampStart;
	u16 IgnRampTimer;
	u8 IgnRampFinished;
	u8 ActiveIgnRamp;
	i16 NeutralAirPart;
	u8 n_GearBoxMissing;
	u8 n_GearBoxIncreasing;
} DNComp_T;
extern DNComp_T DNComp;
#endif
