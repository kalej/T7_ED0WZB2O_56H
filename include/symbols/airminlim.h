#include <t7types.h>

#ifndef __AIRMINLIM_H__
#define __AIRMINLIM_H__
typedef struct AirMinLimType
{
	u8 ST_FCutAllowed;
	u8 ST_MinLimAct;
	u16 m_LDAReq;
} AirMinLim_T;
extern AirMinLim_T AirMinLim;
#endif
