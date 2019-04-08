#include <t7types.h>

#ifndef __CRUISEADAP_H__
#define __CRUISEADAP_H__
typedef struct CruiseAdapType
{
	u16 SwitchOffCond;
	u16 MissingCond;
} CruiseAdap_T;
extern CruiseAdap_T CruiseAdap;
#endif
