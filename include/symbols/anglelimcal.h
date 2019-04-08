#include <t7types.h>

#ifndef __ANGLELIMCAL_H__
#define __ANGLELIMCAL_H__
typedef struct AngleLimCalType
{
	u8 AD_GradHigh;
	u8 AD_GradLow;
	u16 AD_StartHigh;
	u16 AD_StartLow;
	u16 AD_AngleMax;
	u16 AD_AngleMin;
	u16 ThrottFilter;
} AngleLimCal_T;
extern AngleLimCal_T AngleLimCal;
#endif
