#include <t7types.h>

#ifndef __IGNOFFSCAL_H__
#define __IGNOFFSCAL_H__
typedef struct IgnOffsCalType
{
	i16 v_RampUpLim;
	i16 NCIgnNegRampStep;
	i16 NCIgnPosRampStep;
	i16 NCMaxNegRampTAB[5];
	i16 NCMaxNegRampSP[5];
	i16 n_NCIgnNegRamp;
	i16 fiRampStep1;
	i16 fiRampStep2;
	i16 DNCompSlow[48];
	i16 DNCompFast[48];
	i16 Q_ExtraSP[6];
	i16 fi_Offs;
	i16 fi_OffsCyl[4];
} IgnOffsCal_T;
extern IgnOffsCal_T IgnOffsCal;
#endif
