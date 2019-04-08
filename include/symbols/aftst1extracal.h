#include <t7types.h>

#ifndef __AFTST1EXTRACAL_H__
#define __AFTST1EXTRACAL_H__
typedef struct AftSt1ExtraCalType
{
	i16 p_AirAmbSP[4];
	u8 EnrFacMap[60];
} AftSt1ExtraCal_T;
extern AftSt1ExtraCal_T AftSt1ExtraCal;
#endif
