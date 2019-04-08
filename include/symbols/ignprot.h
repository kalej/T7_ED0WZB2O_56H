#include <t7types.h>

#ifndef __IGNPROT_H__
#define __IGNPROT_H__
typedef struct IgnProtType
{
	i16 fi_Min;
	i16 fi_IgnExlLOff;
	i16 fi_ABS;
	i16 fi_IgnCalc;
	i16 fi_Offset;
	i32 fi_Ramp;
	u8 RampDir;
	u8 LastActiveMap;
	i16 fi_Ignition;
} IgnProt_T;
extern IgnProt_T IgnProt;
#endif
