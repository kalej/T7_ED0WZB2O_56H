#include <t7types.h>

#ifndef __ADPFUEL_H__
#define __ADPFUEL_H__
typedef struct AdpFuelType
{
	u8 ST_DoneMul;
	u8 ST_DoneAdd;
	u8 ST_PurgeAllow;
	u8 ST_DiagDoneMul;
	u8 ST_DiagDoneAdd;
	u8 MulFAdapRampDone;
	u8 AddFAdapRampDone;
	u8 ST_FuelAdpAct;
} AdpFuel_T;
extern AdpFuel_T AdpFuel;
#endif
