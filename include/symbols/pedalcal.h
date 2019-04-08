#include <t7types.h>

#ifndef __PEDALCAL_H__
#define __PEDALCAL_H__
typedef struct PedalCalType
{
	u8 AD_Decrement;
	u8 AD_Increment;
	u8 AD_CaptureHyst;
	u8 ms_UpDebounce;
	u8 ms_DownDebounce;
} PedalCal_T;
extern PedalCal_T PedalCal;
#endif
