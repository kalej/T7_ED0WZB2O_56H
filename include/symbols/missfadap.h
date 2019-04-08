#include <t7types.h>

#ifndef __MISSFADAP_H__
#define __MISSFADAP_H__
typedef struct MissfAdapType
{
	u8 MissfCntMap[288];
	u16 MissfCntCyl[6];
	u16 MissfTotCntCat;
	u16 MissfTotCntEmis;
	u16 AvDetect1Level;
	u16 AvDetect2Level;
	i16 T_EngOff;
} MissfAdap_T;
extern MissfAdap_T MissfAdap;
#endif
