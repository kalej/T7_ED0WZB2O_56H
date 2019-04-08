#include <t7types.h>

#ifndef __F_KNKDETADAP_H__
#define __F_KNKDETADAP_H__
typedef struct F_KnkDetAdapType
{
	i16 FalseDetCnt;
	u16 RKnkCntMap[256];
	u16 RKnkCntCyl[4];
	u16 FKnkCntMap[256];
	u16 FKnkCntCyl[4];
} F_KnkDetAdap_T;
extern F_KnkDetAdap_T F_KnkDetAdap;
#endif
