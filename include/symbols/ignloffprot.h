#include <t7types.h>

#ifndef __IGNLOFFPROT_H__
#define __IGNLOFFPROT_H__
typedef struct IgnLOffProtType
{
	u8 ST_FirstTime;
	i16 fi_Offset;
	i16 TempOffset;
	u16 NrCombustion;
	u8 no_10ms;
	u16 m_requestbuf[16];
	u16 m_requestLO;
	u8 ST_LOStAftPowUp;
} IgnLOffProt_T;
extern IgnLOffProt_T IgnLOffProt;
#endif
