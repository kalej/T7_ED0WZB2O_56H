#include <t7types.h>

#ifndef __TRANS_H__
#define __TRANS_H__
typedef struct TransType
{
	u8 ST_Active;
	i16 m_ReqDelCopy;
} Trans_T;
extern Trans_T Trans;
#endif
