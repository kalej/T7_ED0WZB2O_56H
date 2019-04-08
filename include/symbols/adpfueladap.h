#include <t7types.h>

#ifndef __ADPFUELADAP_H__
#define __ADPFUELADAP_H__
typedef struct AdpFuelAdapType
{
	i16 MulFuelAdapt;
	i32 AddFuelAdapt;
} AdpFuelAdap_T;
extern AdpFuelAdap_T AdpFuelAdap;
#endif
