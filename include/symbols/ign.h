#include <t7types.h>

#ifndef __IGN_H__
#define __IGN_H__
typedef struct IgnType
{
	i16 fi_OtherOff;
	i16 fi_IgnCalcBefTrq;
	i16 fi_Average;
	i16 fi_EngOff;
	i16 fi_AirOff;
	i16 IgnMode;
	u8 IdleRampFinished;
	u8 ST_TrqIgnActive;
	u8 ActiveMap;
} Ign_T;
extern Ign_T Ign;
#endif
