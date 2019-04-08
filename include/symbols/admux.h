#include <t7types.h>

#ifndef __ADMUX_H__
#define __ADMUX_H__
typedef struct ADMuxType
{
	u16 T_Engine;
	u16 T_AirInlet;
	u16 p_Fueltank;
	u16 U_Batt;
	u16 p_PowerSteer;
	u16 I_Egas;
	u16 T_Exhaust;
	u16 p_Air;
} ADMux_T;
extern ADMux_T ADMux;
#endif
