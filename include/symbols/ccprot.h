#include <t7types.h>

#ifndef __CCPROT_H__
#define __CCPROT_H__
typedef struct CCProtType
{
	u8 NormalMode;
	u8 UnderSchedEnable;
	u8 USDFunctionActive;
	u16 v_USD;
	u16 M_DelWheelUnsig;
} CCProt_T;
extern CCProt_T CCProt;
#endif
