#include <t7types.h>

#ifndef __VIOSADAP_H__
#define __VIOSADAP_H__
typedef struct VIOSAdapType
{
	u8 ST_ThrottleBlock;
	i16 AD_ThrottleBlock;
	i16 AD_ThrottleBlock2;
	i16 AD_PedalBlock;
} VIOSAdap_T;
extern VIOSAdap_T VIOSAdap;
#endif
