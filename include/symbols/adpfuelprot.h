#include <t7types.h>

#ifndef __ADPFUELPROT_H__
#define __ADPFUELPROT_H__
typedef struct AdpFuelProtType
{
	u8 ST_Window;
	u8 ST_FirstAdapt;
	u16 Counter250;
	u16 Counter250_2;
	u16 AdpCounter;
	u16 AdpCounter2;
	i32 LambAdd;
	i32 LambAdd2;
	i16 MulFuelAdapt;
	i32 AddFuelAdapt;
} AdpFuelProt_T;
extern AdpFuelProt_T AdpFuelProt;
#endif
