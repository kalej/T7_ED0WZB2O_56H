#include <t7types.h>

#ifndef __GEARADAP_H__
#define __GEARADAP_H__
typedef struct GearAdapType
{
	u8 ST_Automatic;
	u8 ST_CruiseIncluded;
	u8 ST_ACRequested;
	u8 ST_TractionControl;
	u8 ST_TCSCANBased;
	u8 ST_ESPEquiped;
} GearAdap_T;
extern GearAdap_T GearAdap;
#endif
