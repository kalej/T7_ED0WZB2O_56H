#include <t7types.h>

#ifndef __CATMODPROT_H__
#define __CATMODPROT_H__
typedef struct CatModProtType
{
	i16 T_Catalyst;
	i16 T_LambdaOffset;
	i16 T_LambdaOffsetFilt;
	i16 T_CatalystFilt;
	u16 n_LoadCnt;
	u16 n_HighLoad;
	u16 m_AirInletFilt;
} CatModProt_T;
extern CatModProt_T CatModProt;
#endif
