#include <t7types.h>

#ifndef __SAIPROT_H__
#define __SAIPROT_H__
typedef struct SAIProtType
{
	u8 ST_SAIReq;
	u8 SAI_Status;
	u8 ST_SAILoadLimit;
	u8 ST_FuelActive;
	u8 RampTiInit;
	u8 pump_ready;
	u8 SAI_has_been_stoped;
	u8 buff_init;
	u8 BuffPoint;
	u8 ST_SAIPumpPh1;
	u8 ST_SAIPumpPh2;
	u8 got_stamp;
	u8 SAI_has_act;
	u8 ST_LeanClampLoadLim;
	u8 ST_ReCalcBefSt;
	u8 SAI_ActThisCycl;
	u16 N_PumpStart;
	u16 N_PumpStop;
	u16 RampFac;
	i16 m_FuelFac;
	u16 N_FuellingStart;
	u16 RampOffset;
	u16 n_CombCount;
	u16 m_loadave;
	u16 m_AirInjSAI;
	u16 LoadBuff[5];
	u16 m_AirInjReq;
	u16 N_combstamp;
	i16 ST_TOutOfRange;
	u32 t_timestamp;
	u32 t_Ramp_time;
} SAIProt_T;
extern SAIProt_T SAIProt;
#endif
