#include <t7types.h>

#ifndef __KNKDET_H__
#define __KNKDET_H__
typedef struct KnkDetType
{
	u8 ST_Knock;
	u8 ST_ClearIgnOff;
	u8 KnockCyl[4];
	u16 RefValueActual;
} KnkDet_T;
extern KnkDet_T KnkDet;
#endif
