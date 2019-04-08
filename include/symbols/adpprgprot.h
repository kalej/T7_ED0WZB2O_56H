#include <t7types.h>

#ifndef __ADPPRGPROT_H__
#define __ADPPRGPROT_H__
typedef struct AdpPrgProtType
{
	u8 ST_AdaptAllow;
	u8 State;
} AdpPrgProt_T;
extern AdpPrgProt_T AdpPrgProt;
#endif
