#include <t7types.h>

#ifndef __AIRCOMPCAL_H__
#define __AIRCOMPCAL_H__
typedef struct AirCompCalType
{
	i16 T_AirSP[14];
	u16 AirTab[14];
	u16 Hysteres;
	u16 PressMap[256];
	i16 p_PresSP[11];
	u16 PresTab[11];
	i16 T_AirLimSP[14];
	u16 AirLimTab[14];
} AirCompCal_T;
extern AirCompCal_T AirCompCal;
#endif
