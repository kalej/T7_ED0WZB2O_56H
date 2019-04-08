#include <t7types.h>

#ifndef __POWINHCAL_H__
#define __POWINHCAL_H__
typedef struct PowInhCalType
{
	u8 Number;
	u16 I_AbsLimit;
	u16 I_RelLimit;
	u16 t_TestPhase1;
	u16 t_TestPhase2;
	u16 t_TestPhase3;
	u16 t_TestPhase4;
	u16 t_TestPhase5;
} PowInhCal_T;
extern PowInhCal_T PowInhCal;
#endif
