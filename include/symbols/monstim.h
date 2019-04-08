#include <t7types.h>

#ifndef __MONSTIM_H__
#define __MONSTIM_H__
typedef struct MonStimType
{
	u16 ST_Error;
	u8 Carry;
	u8 State;
	u8 Calc;
	u8 EndResult;
	u8 Stimulation;
	u8 S[30];
} MonStim_T;
extern MonStim_T MonStim;
#endif
