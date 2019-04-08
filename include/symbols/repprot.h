#include <t7types.h>

#ifndef __REPPROT_H__
#define __REPPROT_H__
typedef struct REPProtType
{
	i16 ST_Active;
	i16 p_AirAmbient;
	i16 ST_GSIState;
	i16 P_Saved;
	i16 X_LastPedal;
} REPProt_T;
extern REPProt_T REPProt;
#endif
