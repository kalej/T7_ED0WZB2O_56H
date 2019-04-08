#include <t7types.h>

#ifndef __STARTCAL_H__
#define __STARTCAL_H__
typedef struct StartCalType
{
	i16 T_EngineXSP[8];
	i16 n_EngineYSP[6];
	u16 ScaleFacRpmMap[48];
	u16 m_FuelBasic;
	i16 T_EngineSP[15];
	u16 EnrFacTab[15];
	u16 t_RestartSP[5];
	u16 RestartFacTab[5];
	i16 RestTempLim;
	u16 RpmStartLim;
	u16 CombStartLim;
	u16 n_CombSP[10];
	u16 CombFacTab[10];
	u16 m_FuelBefStart[15];
	u16 t_BefStRunCold;
	u16 t_BefStRunWarm;
	i16 T_BefStEngine;
	u16 TransEnrTime;
	u16 m_ReStBefFuel[15];
	u8 HighAltFacMap[60];
	i16 p_HighAltSP[4];
} StartCal_T;
extern StartCal_T StartCal;
#endif
