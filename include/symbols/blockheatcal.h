#include <t7types.h>

#ifndef __BLOCKHEATCAL_H__
#define __BLOCKHEATCAL_H__
typedef struct BlockHeatCalType
{
	i16 T_AirInlet;
	i16 T_Engine;
	i16 T_EngAirDiff;
	i16 StartFac;
	i16 AftSt2FacTab[4];
	i16 Q_StartFacTab[4];
	i16 C_PartNFacTab[4];
	i16 T_AirInletSP[4];
	i16 C_PartDec;
	i16 T_AirInletMin;
} BlockHeatCal_T;
extern BlockHeatCal_T BlockHeatCal;
#endif
