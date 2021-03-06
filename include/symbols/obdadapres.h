#include <t7types.h>

#ifndef __OBDADAPRES_H__
#define __OBDADAPRES_H__
typedef struct OBDAdapResType
{
	i16 mulfueladap[5];
	i16 addfueladap[5];
	i16 knkadaphiwin[5];
	i16 knkadaplowin[5];
	i16 idleneutraladap[5];
	i16 idledriveadap[5];
	i16 boostadap[5];
	i16 starttime[5];
	i16 misfatstart[5];
	i16 airmTEng[5];
	i16 airmTAir[5];
	i16 qairCompThr[5];
	i16 qairCompHiThr[5];
	u16 qairAmbAir[5];
	u16 amp_Bypass[5];
	u16 m_boostActAir[5];
	i16 BoostAdap[5];
	i16 m_boostSet[5];
	u16 t_LambdaStart[5];
	u16 t_StartTempState[5];
	u16 n_IdleSpeed[5];
	u16 n_IdleNom[5];
	u16 BlockAdaption[5];
	u16 U_HiSensPost[5];
	u16 U_DeadSensPost[5];
	u16 t_LowSensPost[5];
	u16 U_SensPre[5];
	u16 Flank_pTank[5];
	i16 Flank_SensFrq[5];
	u16 Comb_SensFrq[5];
	i16 T_EngStart[5];
	i16 T_EngActual[5];
	u16 evapLeakFact[5];
	i16 evapAirStartTemp[5];
	i16 evapEngStartTemp[5];
	i16 catEvalValue[5];
	i16 catv6loadAv[5];
	i16 catv6catTemp[5];
	i16 catv6Result[5];
	u16 missfCnt[5];
	u16 missf1000[5];
	u16 lambdaAtMaxTime[5];
	i16 mulFuelAdap[5];
	i16 addFuelAdap[5];
	u16 p_AmbAirAmb[5];
	u16 p_AmbAirInl[5];
	u16 p_AmbAirBef[5];
	i16 adap_mul[5];
	i16 adap_add[5];
	u16 n_CombSync[5];
	u16 T_Sync[5];
	u16 I_HeatPre[5];
	u16 I_HeatPost[5];
	i16 p_AirInlDiff[5];
	i16 p_AirBefDiff[5];
	u8 lambAdapRich[5];
	u8 lambAdapLean[5];
	i16 SAIMainIntArea[5];
	i16 SAIIntrIntDiff[5];
	i16 SAILoadAv[5];
	u16 TAirAtMaxTime[5];
	i16 A_Throttle[5];
	i16 T_AtTempChange[5];
	u32 n_TEngDeadComb[5];
	u16 T_CoolRuntime[5];
	i16 T_CoolCombust[5];
	i16 T_CoolAirActual[5];
	i16 T_CoolEngActual[5];
} OBDAdapRes_T;
extern OBDAdapRes_T OBDAdapRes;
#endif
