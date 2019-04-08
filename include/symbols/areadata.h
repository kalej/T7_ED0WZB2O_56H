#include <t7types.h>

#ifndef __AREADATA_H__
#define __AREADATA_H__
typedef struct AreaDataType
{
	u16 A_Controller;
	u16 A_Emission;
	u16 A_Start;
	u16 A_ThrottleDemand;
	i16 Q_Venturi;
	i16 m_Venturi;
} AreaData_T;
extern AreaData_T AreaData;
#endif
