#include <t7types.h>

#ifndef __TRANSPROT_H__
#define __TRANSPROT_H__
typedef struct TransProtType
{
	i16 ActualFactor;
	i16 m_ReqDelta;
	i16 AccTriggLim;
	i16 DecTriggLim;
	u16 m_RequestBuff[10];
	u16 m_ReqFilt;
} TransProt_T;
extern TransProt_T TransProt;
#endif
