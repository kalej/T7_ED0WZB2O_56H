#include <t7types.h>

#ifndef __EXECCNTRLOPTION_H__
#define __EXECCNTRLOPTION_H__
typedef struct ExecCntrlOptionType
{
	u8 CMD_FuelPumpRelay;
	u8 ThrPWM;
	u8 ThrPWMActive;
	u8 EvapColdStart;
	u8 SecAirPumpDiag;
} ExecCntrlOption_T;
extern ExecCntrlOption_T ExecCntrlOption;
#endif
