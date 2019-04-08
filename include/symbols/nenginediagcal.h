#include <t7types.h>

#ifndef __NENGINEDIAGCAL_H__
#define __NENGINEDIAGCAL_H__
typedef struct nEngineDiagCalType
{
	u16 U_BattLim;
	u16 p_AirInletLim;
} nEngineDiagCal_T;
extern nEngineDiagCal_T nEngineDiagCal;
#endif
