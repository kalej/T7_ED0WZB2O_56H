#include <t7types.h>

#ifndef __TCOMPCAL_H__
#define __TCOMPCAL_H__
typedef struct TCompCalType
{
	u8 ST_Enable;
	u16 EnrFacXSP[8];
	u16 EnrFacYSP[8];
	u8 EnrFacMap[64];
	u16 EnrFacAutXSP[8];
	u16 EnrFacAutYSP[8];
	u8 EnrFacAutMap[64];
	i16 T_EngineSP[15];
	u16 EnrFacTab[15];
	i16 T_EngineAutSP[15];
	u16 EnrFacAutTab[15];
	i16 T_EnrFacAutLim;
} TCompCal_T;
extern TCompCal_T TCompCal;
#endif
