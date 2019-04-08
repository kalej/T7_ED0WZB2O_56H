#include <t7types.h>

#ifndef __QADAPTCAL_H__
#define __QADAPTCAL_H__
typedef struct QAdaptCalType
{
	u16 n_MaxLim;
	u16 m_MinLim;
	u8 BlockSize;
	u8 FilterVal;
	u8 X_MultFact;
	i8 Offs;
} QAdaptCal_T;
extern QAdaptCal_T QAdaptCal;
#endif
