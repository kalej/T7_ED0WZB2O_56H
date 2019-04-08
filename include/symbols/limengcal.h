#include <t7types.h>

#ifndef __LIMENGCAL_H__
#define __LIMENGCAL_H__
typedef struct LimEngCalType
{
	u8 Status;
	u16 p_AirSP[8];
	u16 TurboSpeedTab[8];
	u16 n_EngSP[8];
	u16 TurboSpeedTab2[8];
} LimEngCal_T;
extern LimEngCal_T LimEngCal;
#endif
