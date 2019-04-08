#include <t7types.h>

#ifndef __IDLEPROT_H__
#define __IDLEPROT_H__
typedef struct IdleProtType
{
	i16 C_A_Part;
	i16 P_Part;
	i16 I_Part;
	i16 Q_StartOffs;
	i16 n_EngineDiff;
	i16 n_EngineDelta;
	i16 Q_StartOffsAdd;
	i16 Q_LOffRpmOffs;
	u16 n_EngLOffOffset;
	i16 n_IdleMovAutOff;
	u8 ST_DriveActive;
	i16 T_Part;
	i16 p_ambcomp;
	u8 ST_AfterNC;
	i16 n_ElevIdleGoal;
	i16 n_ElevIdleOff;
	i16 Q_ElevIdle;
	u8 ST_Do_ElevIdle;
	u8 X_mLOffFactor;
	u8 ST_DAdapDone;
} IdleProt_T;
extern IdleProt_T IdleProt;
#endif
