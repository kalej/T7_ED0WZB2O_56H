#include <t7types.h>

#ifndef __MAF_H__
#define __MAF_H__
typedef struct MAFType
{
	u16 Q_AirInletFilt;
	u16 m_AirInlet;
	u16 m_AirInletBoost;
	u16 m_AirInletFuel;
	u16 m_AirInletIgn;
	u16 m_AirInletAir;
	u16 m_AirInletTorq;
	u16 m_AirFromp_AirInlet;
	u16 Q_AirFromp_AirInlet;
	u16 Q_AirFromArea;
	u16 p_InlBefQuote;
} MAF_T;
extern MAF_T MAF;
#endif
