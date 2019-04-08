#include <t7types.h>

#ifndef __SAI_H__
#define __SAI_H__
typedef struct SAIType
{
	i32 IntegratorArea;
	i16 m_FuelFac;
	u8 ST_IntrusiveTest;
	u8 ST_ReqLeanClamp;
	u8 ST_SAIRequest;
	u8 ST_SAIActive;
	u8 AllowLClamp;
	u8 ST_WorkShopResu;
	u8 ST_WorkShopTest;
	u8 ST_NoTempOpenLoop;
	u8 ST_SAIPumpState;
} SAI_T;
extern SAI_T SAI;
#endif
