#include <t7types.h>

#ifndef __CURRTOHICAL_H__
#define __CURRTOHICAL_H__
typedef struct CurrToHiCalType
{
	u16 I_limit;
	u16 Time[2];
} CurrToHiCal_T;
extern CurrToHiCal_T CurrToHiCal;
#endif
