#include <t7types.h>

#ifndef __PEDALPROT_H__
#define __PEDALPROT_H__
typedef struct PedalProtType
{
	u8 PedalNotInIdle;
	u16 AD_PedalPot1;
	u16 AD_FilteredPos;
	u16 AD_CapturedPos;
	u16 AD_EstimatePos;
	u16 ms_DebounceTimer;
} PedalProt_T;
extern PedalProt_T PedalProt;
#endif
