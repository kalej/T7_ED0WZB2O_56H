#include <t7types.h>

#ifndef __CATMODCAL_H__
#define __CATMODCAL_H__
typedef struct CatModCalType
{
	u16 IncFiltCoef;
	u16 DecFiltCoef;
	u16 LambdaOffsetCoef;
	u16 HighLoadFiltCoef;
	u16 MedLoadFiltCoef;
	u16 LowLoadFiltCoef;
	u16 AirInletCoef;
	i16 m_AirInletHigh;
	i16 m_AirInletLow;
	i16 T_SteadyState[64];
	i16 m_SP[8];
	i16 n_SP[8];
	i16 T_LambdaOffset[8];
	i16 LambdaSP[8];
	u16 n_CombStart[8];
	i16 T_SPCombStart[8];
	i16 m_CombFacLim;
} CatModCal_T;
extern CatModCal_T CatModCal;
#endif
