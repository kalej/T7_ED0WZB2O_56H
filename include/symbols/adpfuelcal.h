#include <t7types.h>

#ifndef __ADPFUELCAL_H__
#define __ADPFUELCAL_H__
typedef struct AdpFuelCalType
{
	u16 GadptNr;
	u16 IadptNr;
	i16 T_AdaptLim;
	u16 WMulMaxRpm;
	u16 WMulMinRpm;
	u16 WMulMaxLoad;
	u16 WMulMinLoad;
	u16 WAddMaxRpm;
	u16 WAddMinRpm;
	u16 WAddMaxLoad;
	u16 WAddMinLoad;
	u32 t_AfterCloop;
} AdpFuelCal_T;
extern AdpFuelCal_T AdpFuelCal;
#endif
