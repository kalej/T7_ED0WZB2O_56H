#include <t7types.h>

#ifndef __AIRMINLIMPROT_H__
#define __AIRMINLIMPROT_H__
typedef struct AirMinLimProtType
{
	u16 Q_MinLoad;
	i16 Q_ActualDashPot;
	u16 Q_DashPot;
	u16 Q_DashPotOffset;
} AirMinLimProt_T;
extern AirMinLimProt_T AirMinLimProt;
#endif
