#include <t7types.h>

#ifndef __JERKPROT_H__
#define __JERKPROT_H__
typedef struct JerkProtType
{
	u16 JerkFactor;
	i16 T_AirInlet;
	i16 X_AccPedal;
} JerkProt_T;
extern JerkProt_T JerkProt;
#endif
