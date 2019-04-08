#include <t7types.h>

#ifndef __OBDCCV_H__
#define __OBDCCV_H__
typedef struct obdCCVType
{
	u16 ST_CMD_CCV;
	u8 n_CleanCounter;
} obdCCV_T;
extern obdCCV_T obdCCV;
#endif
