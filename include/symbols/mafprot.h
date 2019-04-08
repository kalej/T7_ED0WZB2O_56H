#include <t7types.h>

#ifndef __MAFPROT_H__
#define __MAFPROT_H__
typedef struct MAFProtType
{
	u8 ST_NegTrans;
	u8 ST_PosTrans;
	u8 ST_NegFuelTrans;
	u8 ST_PosFuelTrans;
	u8 ST_Transient;
	u16 LoadPointer;
	u8 ConstT_Engine;
	u8 ConstT_AirInlet;
	u16 X_DecreaseStep;
	u16 X_IncreaseStep;
	u16 t_NegTransFreez;
	u16 t_PosTransFreez;
	u16 HFMWeightCoef;
	i16 p_DeltaInlet;
	u32 t_TDC_TDC_Filt;
	i16 Q_AltitudeComp;
	i16 AltCompPercent;
} MAFProt_T;
extern MAFProt_T MAFProt;
#endif
