#include <t7types.h>

#ifndef __AREACAL_H__
#define __AREACAL_H__
typedef struct AreaCalType
{
	u8 Size;
	u16 Area[16];
	u16 Table[16];
	i16 iPartMax;
	i16 m_ReqDiff;
	i16 A_MinAdap;
	i16 A_MaxAdap;
	i16 n_EngOffs;
	i16 N_Stable;
	i16 N_StableForce;
	i16 m_ReqFacForceAdap;
	i16 p_InlBefQuote;
	i16 Q_AirInlet;
	i16 MaxDelta;
	i16 Enable_Venturi;
	i16 Q_VenturiSP[16];
	i16 Q_VenturiTab[16];
} AreaCal_T;
extern AreaCal_T AreaCal;
#endif
