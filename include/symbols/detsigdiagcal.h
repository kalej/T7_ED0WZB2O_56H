#include <t7types.h>

#ifndef __DETSIGDIAGCAL_H__
#define __DETSIGDIAGCAL_H__
typedef struct DetSigDiagCalType
{
	u16 n_CombHi;
	u16 n_LowOkLim;
	u16 n_HighOkLim;
	u16 n_CombDetBlock;
} DetSigDiagCal_T;
extern DetSigDiagCal_T DetSigDiagCal;
#endif
