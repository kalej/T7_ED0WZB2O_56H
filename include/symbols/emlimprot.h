#include <t7types.h>

#ifndef __EMLIMPROT_H__
#define __EMLIMPROT_H__
typedef struct EmLimProtType
{
	u16 m_MaxPosDelta;
	i16 PedDelta;
	u16 Ratio;
	u16 RatioFilt;
	u16 RatioHigh;
	u16 RatioLow;
} EmLimProt_T;
extern EmLimProt_T EmLimProt;
#endif
