#include <t7types.h>

#ifndef __KNKSOUNDREDCAL_H__
#define __KNKSOUNDREDCAL_H__
typedef struct KnkSoundRedCalType
{
	i16 fi_OffsMap[288];
	i16 T_LowLim;
	i16 T_HighLim;
	u8 ST_Enable;
} KnkSoundRedCal_T;
extern KnkSoundRedCal_T KnkSoundRedCal;
#endif
