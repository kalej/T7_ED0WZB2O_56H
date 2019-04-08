#include <t7types.h>

#ifndef __IGNCAL_H__
#define __IGNCAL_H__
typedef struct IgnCalType
{
	i16 MinMap[64];
	i16 n_EngYSP[8];
	i16 m_AirXSP[8];
	u16 fi_RampInc;
	u16 fi_RampDecMan;
	u16 fi_RampDecAut;
	i16 fi_Max;
	i16 fi_MinLOffDrv;
} IgnCal_T;
extern IgnCal_T IgnCal;
#endif
