#include <t7types.h>

#ifndef __OBDPTANKADAP_H__
#define __OBDPTANKADAP_H__
typedef struct obdpTankAdapType
{
	u8 ST_AdapDone;
	u8 ST_FirstTimeAfterPowerUp;
	i16 p_NewAdap;
	u16 Status;
} obdpTankAdap_T;
extern obdpTankAdap_T obdpTankAdap;
#endif
