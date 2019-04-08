#include <t7types.h>

#ifndef __ADPPRGCAL_H__
#define __ADPPRGCAL_H__
typedef struct AdpPrgCalType
{
	u32 PurgeTime;
	u32 AdaptTime;
	u32 TimeFirstAdap;
} AdpPrgCal_T;
extern AdpPrgCal_T AdpPrgCal;
#endif
