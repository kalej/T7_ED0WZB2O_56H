#include <t7types.h>

#ifndef __BOOST_H__
#define __BOOST_H__
typedef struct BoostType
{
	u16 AreaComp;
	u8 AirMasterStatus;
	u8 APCError;
	u16 AirLimPos;
	i16 AirLimNeg;
	i16 SetValue;
} Boost_T;
extern Boost_T Boost;
#endif
