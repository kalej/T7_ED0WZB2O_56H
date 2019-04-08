#include <t7types.h>

#ifndef __VIOSCAL_H__
#define __VIOSCAL_H__
typedef struct VIOSCalType
{
	u8 t_DetWinNormal;
	u8 t_DetWinMulti;
	u16 t_BefDetWin;
	u8 ST_TAirInlet;
	i16 M_TCMOffset;
	i16 M_TCSOffset;
	i16 v_TCSOffset;
	i16 M_TCMLimphome;
} VIOSCal_T;
extern VIOSCal_T VIOSCal;
#endif
