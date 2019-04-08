#include <t7types.h>

#ifndef __BFUELPROT_H__
#define __BFUELPROT_H__
typedef struct BFuelProtType
{
	u32 combCounter;
	u16 onCrankFuel;
	u32 m_FuelConsAdd;
	u16 m_FuelBasic;
	u16 m_FuelActual;
	u32 t_InjBasic;
	u32 t_InjActual;
	u8 FuelAdjFac;
	u32 lastStartCombustion;
	i16 CurrentFuelCons;
} BFuelProt_T;
extern BFuelProt_T BFuelProt;
#endif
