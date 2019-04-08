#include <t7types.h>

#ifndef __DNCOMPPROT_H__
#define __DNCOMPPROT_H__
typedef struct DNCompProtType
{
	i16 C_Part[2];
	u8 State;
	u32 RampStart;
	u16 RampTimer;
	u8 RampFinished;
	u32 ActiveAirRampTimer;
	i16 I_PartStart;
	u8 VSpeedIn2;
	u8 GearActivatedIn2;
} DNCompProt_T;
extern DNCompProt_T DNCompProt;
#endif
