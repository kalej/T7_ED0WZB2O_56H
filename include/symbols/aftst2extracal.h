#include <t7types.h>

#ifndef __AFTST2EXTRACAL_H__
#define __AFTST2EXTRACAL_H__
typedef struct AftSt2ExtraCalType
{
	i16 p_AirAmbSP[4];
	u8 EnrFacMap[60];
} AftSt2ExtraCal_T;
extern AftSt2ExtraCal_T AftSt2ExtraCal;
#endif
