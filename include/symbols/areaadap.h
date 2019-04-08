#include <t7types.h>

#ifndef __AREAADAP_H__
#define __AREAADAP_H__
typedef struct AreaAdapType
{
	u8 BlockStatus;
	u8 Pot2BlockStatus;
	u8 ST_AdapDone;
	u8 ST_ForceAdapDone;
	u8 ST_AreaAdapLim;
	u8 ST_ForceAdapAct;
	i16 A_Throttle;
} AreaAdap_T;
extern AreaAdap_T AreaAdap;
#endif
