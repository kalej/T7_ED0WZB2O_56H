#include <t7types.h>

#ifndef __MAFCAL_H__
#define __MAFCAL_H__
typedef struct MAFCalType
{
	u8 X_DecrStepLim;
	u8 X_IncrStepLim;
	u16 WeightCoefFConst;
	u16 FilterCFuelSteady;
	u16 FilterCFuelTrans;
	u16 FilterCIgnSteady;
	u16 FilterCIgnTrans;
	u16 FilterCTorqSteady;
	u16 FilterCTorqTrans;
	u16 FilterConstAir;
	u16 FilterConstBoost;
	u16 t_FreezeNegTrans;
	u16 t_FreezePosTrans;
	i16 p_DeltaTransLim;
	i16 p_DeltaFuelTrans;
	i16 n_EngineXSP[8];
	i16 p_InletGradYSP[14];
	u16 t_NegTransFreezTab[8];
	u16 t_PosTransFreezTab[8];
	u16 WeightConstFuelMap[112];
	u16 X_RpmFiltConst;
	i16 T_EngineSP[8];
	u8 ConstT_EngineTab[8];
	i16 T_AirInlSP[8];
	u8 ConstT_AirInlTab[8];
	u16 n_EngXSP[16];
	u16 LoadYSP[16];
	u16 m_RedundantAirMap[256];
	u16 AreaXSP[9];
	u16 PQuoteYSP[11];
	u16 cd_ThrottleMap[99];
	u16 PDiffSP[12];
	u16 p_DiffCoeffTab[12];
	i16 TCompSP[6];
	u16 T_TempCoeffTab[6];
	u16 Diagn_EngXSP[16];
	u16 DiagLoadYSP[16];
	u16 corr_AirFromp[256];
	i16 cd_Level;
	i16 AltitudeMulFac;
} MAFCal_T;
extern MAFCal_T MAFCal;
#endif
