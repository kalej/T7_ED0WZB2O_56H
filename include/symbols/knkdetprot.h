#include <t7types.h>

#ifndef __KNKDETPROT_H__
#define __KNKDETPROT_H__
typedef struct KnkDetProtType
{
	u8 X_Average;
	u16 Constant;
	u16 U_LevelActual;
	u16 U_KnockCyl[4];
	u16 U_RefLevelActual;
	u16 KnockWinOffs;
	u16 KnockWinAngle;
	u8 RefFactor;
	u16 U_RefLev2;
	u8 NrOfRefAdapt1;
	u8 NrOfRefAdapt2;
	u8 ST_EngTEnableKnk;
	u32 Time;
	u32 Time2;
	i16 T_EngKnkCntrlLim;
} KnkDetProt_T;
extern KnkDetProt_T KnkDetProt;
#endif
