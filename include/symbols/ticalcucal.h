#include <t7types.h>

#ifndef __TICALCUCAL_H__
#define __TICALCUCAL_H__
typedef struct TiCalcuCalType
{
	u8 ms_InletUpdate;
	u16 TiNoPressure;
	i16 p_DiffMin;
	i16 p_DiffHysteresis;
} TiCalcuCal_T;
extern TiCalcuCal_T TiCalcuCal;
#endif
