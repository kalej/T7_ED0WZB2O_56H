#include <t7types.h>

#ifndef __THRLIMPADAP_H__
#define __THRLIMPADAP_H__
typedef struct ThrLimpAdapType
{
	u8 ST_ThrottleLimpHome;
	u8 ST_PWMClose30;
	u8 ST_PWMClose40;
	u8 ST_PWMClose50;
	u8 ST_PWMClose60;
	u8 ST_PWMClose70;
	u16 n_ThrPotClean;
	u16 n_ThrPot1Fault;
} ThrLimpAdap_T;
extern ThrLimpAdap_T ThrLimpAdap;
#endif
