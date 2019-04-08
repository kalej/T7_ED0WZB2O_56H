#include <t7types.h>

#ifndef __THRERR2PROT_H__
#define __THRERR2PROT_H__
typedef struct ThrErr2ProtType
{
	u16 Dummy2;
	u8 RomErrCounter;
	u8 StackErrCounter;
	u8 ST_LimpHome;
} ThrErr2Prot_T;
extern ThrErr2Prot_T ThrErr2Prot;
#endif
