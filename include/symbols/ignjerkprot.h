#include <t7types.h>

#ifndef __IGNJERKPROT_H__
#define __IGNJERKPROT_H__
typedef struct IgnJerkProtType
{
	u8 ST_NewAllowed;
	u8 ST_Activated;
	u8 ST_PedalCond;
	i16 n_Delta;
	i16 n_DeltaLim;
	i16 fi_Offset;
} IgnJerkProt_T;
extern IgnJerkProt_T IgnJerkProt;
#endif
