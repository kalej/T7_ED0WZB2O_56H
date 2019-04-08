#include <t7types.h>

#ifndef __NENGCAL_H__
#define __NENGCAL_H__
typedef struct nEngCalType
{
	u16 WaitTeeth;
	u16 RatioStart;
	u16 RatioRunning;
} nEngCal_T;
extern nEngCal_T nEngCal;
#endif
