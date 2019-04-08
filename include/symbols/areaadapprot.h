#include <t7types.h>

#ifndef __AREAADAPPROT_H__
#define __AREAADAPPROT_H__
typedef struct AreaAdapProtType
{
	u8 AreaAdaptionStatus;
	u8 ForceAdaptionCounter;
	u8 AdaptionCounter;
	u8 AdaptionAllowed;
	u8 ST_StableIPart;
	i16 m_ReqLimForceAdap;
} AreaAdapProt_T;
extern AreaAdapProt_T AreaAdapProt;
#endif
