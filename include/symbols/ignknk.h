#include <t7types.h>

#ifndef __IGNKNK_H__
#define __IGNKNK_H__
typedef struct IgnKnkType
{
	i16 fi_MeanKnock;
	i16 fi_Offset[4];
	i16 fi_OffNorm[4];
	i16 fi_MaxOffset;
	i16 Index;
	u16 AdpHighLim;
} IgnKnk_T;
extern IgnKnk_T IgnKnk;
#endif
