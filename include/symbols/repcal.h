#include <t7types.h>

#ifndef __REPCAL_H__
#define __REPCAL_H__
typedef struct REPCalType
{
	i16 T_AirInletSP[4];
	i16 T_AirInletTab[4];
	i16 p_AirAmbientHyst;
	i16 P_EngineMinLimit;
	i16 P_EngineHyst;
	u16 t_InhibitMin;
	i16 ST_GearShiftInhibit;
} REPCal_T;
extern REPCal_T REPCal;
#endif
