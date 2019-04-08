#include <t7types.h>

#ifndef __KNKDETCAL_H__
#define __KNKDETCAL_H__
typedef struct KnkDetCalType
{
	i16 T_InletAirXSP[2];
	i16 T_EngKnkCntrl[2];
	u16 m_AirXSP[16];
	u16 n_EngYSP[16];
	u16 LoadLimit;
	u8 RefFactorMap[256];
	u16 KnockWinOffs[256];
	u16 KnockWinAngle[14];
	u16 KnockWinAngleNS[14];
	u16 X_AverageTab[4];
	u16 MulFacRef2;
	u16 n_LimWinOff;
	u16 U_BattSP[6];
	u16 KnkWinOffTab[6];
	u8 RefShiftFactor;
	i16 X_FalseDetRef;
	u8 NrofMaxRefAdap;
} KnkDetCal_T;
extern KnkDetCal_T KnkDetCal;
#endif
