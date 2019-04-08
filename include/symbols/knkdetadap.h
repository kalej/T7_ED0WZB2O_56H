#include <t7types.h>

#ifndef __KNKDETADAP_H__
#define __KNKDETADAP_H__
typedef struct KnkDetAdapType
{
	u16 KnkCntMap[256];
	u16 KnkCntCyl[4];
} KnkDetAdap_T;
extern KnkDetAdap_T KnkDetAdap;
#endif
