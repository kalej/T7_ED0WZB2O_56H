#include <t7types.h>

#ifndef __LOADCOPROT_H__
#define __LOADCOPROT_H__
typedef struct LoadCoProtType
{
	u8 ST_ACReq;
	u8 ST_ACRamping;
	u8 ST_ElLoadRamp;
	u8 ST_ACExAirDem;
	u16 t_ElLoadRamp;
	u16 Q_ElLoadCoAir;
	u16 Q_ACCompAir;
	u16 Q_ACAirReq;
	u16 Q_DynamicAir;
	u16 m_WCleanAir;
	u32 t_ACOnOff;
	u16 m_TotCompAir;
	u8 ST_ACCrankDone;
} LoadCoProt_T;
extern LoadCoProt_T LoadCoProt;
#endif
