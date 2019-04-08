#include <t7types.h>

#ifndef __TICALCUPROT_H__
#define __TICALCUPROT_H__
typedef struct TiCalcuProtType
{
	i16 p_DeltaIn50ms;
	i16 p_InletOld;
} TiCalcuProt_T;
extern TiCalcuProt_T TiCalcuProt;
#endif
