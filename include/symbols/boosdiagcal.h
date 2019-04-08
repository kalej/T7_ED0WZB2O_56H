#include <t7types.h>

#ifndef __BOOSDIAGCAL_H__
#define __BOOSDIAGCAL_H__
typedef struct BoosDiagCalType
{
	u16 m_FaultDiff;
	u16 m_ThrErrDiff;
	u16 APCErrTime;
	u16 ThrErrTime;
	u16 p_BefLimit;
	i16 iPartLimit;
	u16 m_OkMinReq;
	u16 p_BefOkLimit;
	u16 m_OkDiff;
	u32 APCOkTime;
	u16 n_MinEngOk;
	u16 n_MaxEngOk;
	i16 IFacMaxAPC;
	u16 ErrMaxMReq;
	i16 m_ReqDiff;
	u16 APCErrTime2;
} BoosDiagCal_T;
extern BoosDiagCal_T BoosDiagCal;
#endif
