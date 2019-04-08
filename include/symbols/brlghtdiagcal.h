#include <t7types.h>

#ifndef __BRLGHTDIAGCAL_H__
#define __BRLGHTDIAGCAL_H__
typedef struct BrLghtDiagCalType
{
	i16 v_LowLim;
	i16 v_HighLim;
	u32 t_LowLim;
	u32 t_HighLim;
} BrLghtDiagCal_T;
extern BrLghtDiagCal_T BrLghtDiagCal;
#endif
