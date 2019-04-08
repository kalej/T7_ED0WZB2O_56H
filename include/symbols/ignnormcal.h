#include <t7types.h>

#ifndef __IGNNORMCAL_H__
#define __IGNNORMCAL_H__
typedef struct IgnNormCalType
{
	u8 ST_Enable;
	i16 Map[288];
	u16 m_AirXSP[18];
	u16 n_EngYSP[16];
	i16 fi_Step;
	i16 GasMap[288];
} IgnNormCal_T;
extern IgnNormCal_T IgnNormCal;
#endif
