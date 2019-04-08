#include <t7types.h>

#ifndef __MONSTIMCAL_H__
#define __MONSTIMCAL_H__
typedef struct MonStimCalType
{
	u16 Time;
	u8 TabAns[8];
	u8 TabSta[8];
	u8 Tab2[8];
} MonStimCal_T;
extern MonStimCal_T MonStimCal;
#endif
