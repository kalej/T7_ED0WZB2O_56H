#include <t7types.h>

#ifndef __CRUISECOMCAL_H__
#define __CRUISECOMCAL_H__
typedef struct CruiseComCalType
{
	u8 M_DefOffset;
	u8 v_FCOEnable;
	u8 v_FCODisable;
	i16 a_DeadRange;
	i16 NegMRange;
	i16 InitFac_4_1;
	i16 InitFac_4_2;
	i16 InitFac_5_2;
	i16 InitFac_5_3;
	i16 InitFac_5_4;
	i16 InitFac_6_1;
	i16 InitFac_6_2;
	i16 InitFac_6_3;
	i16 InitFac_7_1;
	i8 MaxInit;
	u8 ComFac_4;
	u8 ComFac_5;
	u8 ComFac_6;
	u8 ComFac_7;
	i16 InitTapUp;
	i16 InitTapUp54;
	i16 InitAcc;
	i16 InitTapDown;
	u8 M_RoadSize;
	u16 v_Actual[11];
	u16 M_RoadTorque[11];
	u8 TimerLimit;
	u16 M_DeltaRamp;
	u8 M_MinSize;
	u16 v_Delta[4];
	u16 M_Offset[4];
	u16 M_Minimum;
} CruiseComCal_T;
extern CruiseComCal_T CruiseComCal;
#endif
