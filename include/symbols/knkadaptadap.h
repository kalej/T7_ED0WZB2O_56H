#include <t7types.h>

#ifndef __KNKADAPTADAP_H__
#define __KNKADAPTADAP_H__
typedef struct KnkAdaptAdapType
{
	u16 RefValueWind[2];
	u16 RefValueLowWind;
	u16 RefValueHighWind;
	u16 RefValueWRaw[2];
} KnkAdaptAdap_T;
extern KnkAdaptAdap_T KnkAdaptAdap;
#endif
