#include <t7types.h>

#ifndef __AIRCTLDATA_H__
#define __AIRCTLDATA_H__
typedef struct AirctlDataType
{
	u8 FreezeIPart;
	i16 m_CtrlOutput;
	u16 Actual;
	u16 Request;
	u16 MaxAirmass;
	u16 ControllerOut;
	i16 DeltaN0;
	i16 DeltaN1;
	i16 iPartN0;
	i16 iPartN1;
	i32 iPartRest;
	i16 Ti;
} AirctlData_T;
extern AirctlData_T AirctlData;
#endif
