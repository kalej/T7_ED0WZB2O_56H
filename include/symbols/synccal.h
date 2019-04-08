#include <t7types.h>

#ifndef __SYNCCAL_H__
#define __SYNCCAL_H__
typedef struct SyncCalType
{
	u16 n_LimMultiIgn;
	u16 t_DetectLimit;
	u8 n_CombLimit;
	u16 n_CombMultiIgnTab[5];
	i16 T_EngMultiIgnSP[5];
} SyncCal_T;
extern SyncCal_T SyncCal;
#endif
