#include <t7types.h>

#ifndef __FUELCONSCAL_H__
#define __FUELCONSCAL_H__
typedef struct FuelConsCalType
{
	u8 ST_WithPurge;
	u16 AirSP[8];
	u16 Tab[8];
	u16 BeConst;
	u16 m_AirInlXSP[22];
	u16 n_EngineYSP[23];
} FuelConsCal_T;
extern FuelConsCal_T FuelConsCal;
#endif
