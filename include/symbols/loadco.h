#include <t7types.h>

#ifndef __LOADCO_H__
#define __LOADCO_H__
typedef struct LoadCoType
{
	u8 ST_ACStartAir;
	u8 ST_ACCompAir;
	u8 ST_IdleAdapt;
	u16 Q_TotCompAir;
	u16 n_NomIdleOff;
	i16 Q_ColdFricAir;
} LoadCo_T;
extern LoadCo_T LoadCo;
#endif
