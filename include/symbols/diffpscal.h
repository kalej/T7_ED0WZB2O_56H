#include <t7types.h>

#ifndef __DIFFPSCAL_H__
#define __DIFFPSCAL_H__
typedef struct DiffPSCalType
{
	i16 SpeedDivFac;
	i16 v_DiffSP[6];
	i16 M_LimitTab[6];
	i16 M_PosRampMax;
	i16 M_NegRampMax;
	i16 M_EngineSP[6];
	u16 t_LimDelayTab[6];
	u16 v_MaxActive;
} DiffPSCal_T;
extern DiffPSCal_T DiffPSCal;
#endif
