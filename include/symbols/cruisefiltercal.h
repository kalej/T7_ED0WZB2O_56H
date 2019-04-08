#include <t7types.h>

#ifndef __CRUISEFILTERCAL_H__
#define __CRUISEFILTERCAL_H__
typedef struct CruiseFilterCalType
{
	u8 t_592Deb;
	u8 m_CCFilt;
	u16 M_Filter;
	u16 a_Filter;
	u16 v_Filter;
} CruiseFilterCal_T;
extern CruiseFilterCal_T CruiseFilterCal;
#endif
