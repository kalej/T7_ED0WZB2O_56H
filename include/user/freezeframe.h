#include <t7types.h>

#ifndef FREEZEFRAME_H_
#define FREEZEFRAME_H_

typedef struct FreezeFrameType
{
	u16 errCode;
	u32 obdRunTime;
	u32 obdTotalRunTime;
	u16 obdNoOfRuns;
	u32 n_Combustion;
	i16 v_Vehicle;
	i16 n_Engine;
	i16 Q_AirInlet;
	u16 m_Request;
	u16 m_AirInlet;
	i16 V_FuelTank;
	i16 p_AirInlet;
	u16 p_AirBefThrottle;
	u16 p_AirAmbient;
	u16 p_TestInlet;
	u16 p_TestBefThrottle;
	u16 p_TestAir;
	u16 p_FuelTank;
	i16 T_Engine;
	i16 LimpIn_T_Engine;
	u16 obdStartTemp;
	u16 obdInletStartTemp;
	i16 T_AirInlet;
	u16 obdLambdaStartTimer;
	u16 LambdaInt;
	u16 MulFuelAdapt;
	u32 AddFuelAdapt;
	u16 I_HeatO2SensRear;
	i16 I_HeatO2SensFront;
	i16 U_O2SensRear;
	i16 U_O2SensFront;
	i32 O2SensFreqCombustCnt;
	i16 O2SensFreqFlankShiftCnt;
	i16 obdMeanAirmCompEval;
	i16 obdMeanAirmCompHiEval;
	i16 U_Knock;
	i16 U_KnockDiag;
	u16 MissfTotCntCat;
	u16 MissfTotCntEmis;
	u16 MissfCntCyl1Temp;
	u16 MissfCntCyl2Temp;
	u16 MissfCntCyl3Temp;
	u16 MissfCntCyl4Temp;
	u16 MissfCntCyl5Temp;
	u16 MissfCntCyl6Temp;
	u16 MissfCntCyl1Emis;
	u16 MissfCntCyl2Emis;
	u16 MissfCntCyl3Emis;
	u16 MissfCntCyl4Emis;
	u16 MissfCntCyl5Emis;
	u16 MissfCntCyl6Emis;
	i16 Purge_HCCont;
	i32 t_Injection;
	i16 A_Throttle;
	i16 In_AD_ThrottlePot1;
	u16 p_AirInletComp;
	u16 p_AirBefThrottleComp;
	i16 CatDevDiffFilt;
	i16 Out_PWM_BoostCntrl;
	i16 T_AirAmbient;
	i16 iPartN1;
	i16 Boost_SetValue;
	i16 BoostProt_IFac;
	u16 n_EngineNominal;
	i16 IdleProt_I_Part;
	u16 m_nHigh;
	i16 T_Catalyst;
	u16 CatDiagLevProt_m_Av;
	i16 LevResult;
	i16 LevEvalValue;
	i16 AD_PedalPot1;
	i16 AD_SlavePedalPot1;
	i16 AD_PedalPot2;
	i16 AD_ThrottlePot1;
	i16 AD_ThrottlePot2;
	i16 AD_Throttle;
	i32 SAIIntegratorArea;
	i32 SAIIntrm_air;
	i16 SAIIntrIntDiff;
	i16 fi_Ignition;
	u8 SAIIntrResult;
	u8 obdQuickChangeError;
	u8 ST_BrakeLight;
	u8 Out_CMD_Bypass;
	u8 LambdaStatus;
	u8 LambdaRichConst;
	u8 LambdaLeanConst;
	u8 ST_EngineSynced;
	u8 ST_FuelCut;
	u8 FCutStatus;
	u8 U_Batt;
	u8 field_BB;
	u8 obdWarmUpCycle;
	u8 ImmoKillInjection;
	u8 Idle_ST_Enable;
	u8 obdDrivingCycleDone;
	u8 obdOutOfLimits;
	u8 In_ST_IgnitionKey;
	u8 field_C2;
	u8 align_C3;
} FreezeFrame_T;

#endif /* FREEZEFRAME_H_ */
