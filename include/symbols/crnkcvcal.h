#include <t7types.h>

#ifndef __CRNKCVCAL_H__
#define __CRNKCVCAL_H__
typedef struct CrnkCVCalType
{
	u8 ST_Enable;
	u8 p_DiffLimit;
	u8 p_DiffLimitHys;
	u16 Q_AirLimit;
	u16 Q_AirLimitHys;
} CrnkCVCal_T;
extern CrnkCVCal_T CrnkCVCal;
#endif
