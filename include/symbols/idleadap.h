#include <t7types.h>

#ifndef __IDLEADAP_H__
#define __IDLEADAP_H__
typedef struct IdleAdapType
{
	i16 Q_AirNeutral;
	i16 Q_AirDrive;
} IdleAdap_T;
extern IdleAdap_T IdleAdap;
#endif
