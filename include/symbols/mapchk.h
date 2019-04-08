#include <t7types.h>

#ifndef __MAPCHK_H__
#define __MAPCHK_H__
typedef struct MapChkType
{
	u8 ST_Error;
	u32 CheckSum;
} MapChk_T;
extern MapChk_T MapChk;
#endif
