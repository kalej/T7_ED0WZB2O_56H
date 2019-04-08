#include <t7types.h>

#ifndef __CATDIAGLEVPROT_H__
#define __CATDIAGLEVPROT_H__
typedef struct CatDiagLevProtType
{
	u16 actualFuelFac;
	u16 actualFirstTime;
	u16 actualSecondTime;
	u8 preConditionOK;
	u32 closedThrotTimer;
	u8 nrOfLambdaSwitches;
	u16 m_Av;
} CatDiagLevProt_T;
extern CatDiagLevProt_T CatDiagLevProt;
#endif
