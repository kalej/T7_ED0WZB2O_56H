#include <t7types.h>

#ifndef __CRANK_H__
#define __CRANK_H__
typedef struct CrankType
{
	u8 ST_EnginePosFound;
	i16 t_TDC_TDC_Delta;
	u16 ActiveDeltaCyl;
	u16 Cylinder;
} Crank_T;
extern Crank_T Crank;
#endif
