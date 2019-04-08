#include <t7types.h>

#ifndef __DISPLADAP_H__
#define __DISPLADAP_H__
typedef struct DisplAdapType
{
	u16 v_Factor;
	i8 AmosPos;
	i8 AmosPos2;
	i8 FreezePos;
	i8 IndexPos;
	i8 Index[6];
	u8 ST_Enable;
	u8 ScannerSelect;
	i16 AD_ScannerSP[7];
	i16 LamScannerTab1[7];
	i16 LamScannerTab2[7];
	i16 LamScannerTab3[7];
} DisplAdap_T;
extern DisplAdap_T DisplAdap;
#endif
