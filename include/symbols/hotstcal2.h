#include <t7types.h>

#ifndef __HOTSTCAL2_H__
#define __HOTSTCAL2_H__
typedef struct HotStCal2Type
{
	u16 t_RestartSP[6];
	u16 RestartFacTab[6];
} HotStCal2_T;
extern HotStCal2_T HotStCal2;
#endif
