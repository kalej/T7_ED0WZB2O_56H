#include <t7types.h>

#ifndef __TQTOHICAL_H__
#define __TQTOHICAL_H__
typedef struct TqToHiCalType
{
	i16 T_AirInletXSP[8];
	u16 X_AccPedYSP[6];
	u16 Q_AirInletMap[48];
	u16 Time;
} TqToHiCal_T;
extern TqToHiCal_T TqToHiCal;
#endif
