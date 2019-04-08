#include <t7types.h>

#ifndef __GEARCAL_H__
#define __GEARCAL_H__
typedef struct GearCalType
{
	u16 Ratio[5];
	u16 Range[5];
	i8 T_ActivateSUL;
	u8 m_SULHyst;
	u16 n_SULHyst;
	u16 n_ActivateSUL;
	u16 t_SULTurnOnDly;
	u16 t_SULTurnOffDly;
	u16 m_SULAtGear[4];
	u16 n_SULAtGear[4];
	u8 ST_SULEnable;
} GearCal_T;
extern GearCal_T GearCal;
#endif
