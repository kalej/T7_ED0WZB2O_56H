#include <t7types.h>

#ifndef __STARTPROT_H__
#define __STARTPROT_H__
typedef struct StartProtType
{
	u16 m_FuelActOut;
	u8 ST_Started;
	u16 CombCnt;
	u16 m_FuelActual;
	u16 t_EngineStop;
	u16 t_BefStart;
	u16 HighAltFactor;
} StartProt_T;
extern StartProt_T StartProt;
#endif
