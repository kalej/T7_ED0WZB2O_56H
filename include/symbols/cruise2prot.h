#include <t7types.h>

#ifndef __CRUISE2PROT_H__
#define __CRUISE2PROT_H__
typedef struct Cruise2ProtType
{
	u8 t_592Debounc;
	u8 a_Timer;
	u8 TCSActive;
	u8 ms_TCSTimer;
} Cruise2Prot_T;
extern Cruise2Prot_T Cruise2Prot;
#endif
