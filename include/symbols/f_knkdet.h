#include <t7types.h>

#ifndef __F_KNKDET_H__
#define __F_KNKDET_H__
typedef struct F_KnkDetType
{
	i16 fi_SootOffs;
	u16 NoDDCnt;
	u16 U_AveKnk[4];
	u16 CycleCnt[4];
	u16 m_HighLim;
	u16 NoDDLast;
	u8 ST_SteadyState;
	u8 ST_DoubleDetect;
	u8 ST_Active;
} F_KnkDet_T;
extern F_KnkDet_T F_KnkDet;
#endif
