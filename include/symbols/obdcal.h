#include <t7types.h>

#ifndef __OBDCAL_H__
#define __OBDCAL_H__
typedef struct OBDCalType
{
	u8 MILEnabled;
	u8 prelFaultCountDown;
	u8 evapEquipmentExist;
	u32 evapTestTimeLim;
	u8 StopPlotWhenFault;
	u32 StopPlotDelayTime;
	u32 EnableOBD2Limit;
	i16 T_AirLoOBDLim;
	i16 T_EngLoOBDLim;
	u16 p_AirLoOBDLim;
	i16 T_AirHiOBDLim;
	i16 T_EngHiOBDLim;
	u16 p_AirHiOBDLim;
	u8 LOBDEnabled;
	u8 EOBDEnabled;
} OBDCal_T;
extern OBDCal_T OBDCal;
#endif
