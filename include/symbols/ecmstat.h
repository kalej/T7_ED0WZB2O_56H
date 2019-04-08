#include <t7types.h>

#ifndef __ECMSTAT_H__
#define __ECMSTAT_H__
typedef struct ECMStatType
{
	u8 ST_ACRequested;
	u8 ST_CruiseIncluded;
	u8 ST_EngineStarted;
	u8 ST_Automatic;
	u8 ST_DICE_Node;
	u8 ST_MIU_Node;
	u8 ST_SID_Node;
	u8 ST_AutNeutral;
	u8 ST_EngineSynced;
	u8 ST_PedalReleased;
	u8 ST_EngineMoving;
	u8 ST_EngNotMoving;
	u8 ST_ThrottleLimpHome;
	u8 ST_TCSCANBased;
	u8 ST_BlkHeatStart;
	u8 ST_ESPEquiped;
	u8 ST_hotFuelStart;
	u8 ManualGear;
	u8 ST_ActiveAirDem;
	u32 n_CombWhenSync;
	u32 msCounter;
	u32 n_Combustion;
	u32 n_CombustionSync;
	i16 p_Diff;
	u16 n_Engine10ms;
	i16 p_DiffThrot;
	u16 t_Soak;
	u16 FuelBe;
	u32 FuelFlow;
	u16 AirFuelRatio;
	u16 t_StartTime;
	i16 P_Engine;
	i16 T_Catalyst;
	i16 n_EngineDelta2;
	i16 n_EngineDelta2Max;
	i16 JerkFactor;
} ECMStat_T;
extern ECMStat_T ECMStat;
#endif
