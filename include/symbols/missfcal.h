#include <t7types.h>

#ifndef __MISSFCAL_H__
#define __MISSFCAL_H__
typedef struct MissfCalType
{
	u16 n_CombAvDetect;
	u16 DetectLoadLevel[80];
	u16 CatOverheatFactor[288];
	u16 CVSErrorLim;
	u16 m_AirXSP[18];
	u16 n_EngYSP[16];
	i16 T_EngSP[4];
	u16 startDelayTAB[4];
	u16 p_AirAmbOutOfLimSP[4];
	i16 T_EngOutOfLimSP[4];
	u16 outOfLimDelayMAT[16];
	u16 n_EngRPMDiffYSP[6];
	u16 LoadRPMDiffXSP[6];
	i16 RPMDiffLimMAP[36];
	u16 RPMLimRPMDiff;
	u16 LoadLimRPMDiff;
	u16 LowFuelVolFuelLim;
	u8 ACFilterON;
	u8 PurgeDiagFilterON;
	u8 TransientFilterON;
	u8 pAirInletDiffFilterON;
	u16 nrOfACFilterCombust;
	u16 nrOfPurgeDiagFilterCombust;
	u16 nrOfTransientFilterCombust[15];
	u16 nrOfFuelCutFilterCombust;
	i16 EngTempSP[15];
	u16 transientSizeLim;
	u16 pAirInletDiffSizeLim;
	u16 LoadAfterFCutLim;
	u8 M_nrOfOKTempBlockLim;
	u8 L_nrOfOKTempBlockLim;
	u16 nrOfMisfLambda;
	u16 n_EngineSP[8];
	u16 M_LimTab[8];
	i8 TorqueLowLim;
	u32 n_CombAftSync;
	u16 m_AirLimLambdaOff[16];
	u16 m_AirHiLimFTP;
	u16 n_EngHiLimFTP;
	u8 ST_PedalTriggFiltActive;
	u16 t_DelayMisfStart;
	i16 T_EngXSP[5];
	u16 CVSErrorLimStart;
	u8 O2AdjMFErrLim;
	u8 O2AdjBlockErrLim;
	u8 O2AdjMFOKLim;
	u8 O2AdjBlockOKLim;
	u16 U_AdapMinLim;
	u16 U_AdapMaxLim;
	i16 LeanStep[8];
	i16 RichStep[8];
	i16 T_EngOffLim;
	i16 T_hotStartLim;
	i16 T_hotAirLim;
	i16 CVSErrorLimHotStart;
} MissfCal_T;
extern MissfCal_T MissfCal;
#endif