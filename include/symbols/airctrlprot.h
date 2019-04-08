#include <t7types.h>

#ifndef __AIRCTRLPROT_H__
#define __AIRCTRLPROT_H__
typedef struct AirCtrlProtType
{
	i16 m_ReqFilt;
	u16 m_ReqBuff[21];
} AirCtrlProt_T;
extern AirCtrlProt_T AirCtrlProt;
#endif
