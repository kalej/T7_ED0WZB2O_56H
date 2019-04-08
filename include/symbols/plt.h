#include <t7types.h>

#ifndef __PLT_H__
#define __PLT_H__
typedef struct PLTType
{
	u16 Plott2_enabled;
	u8 PlottPosition;
} PLT_T;
extern PLT_T PLT;
#endif
