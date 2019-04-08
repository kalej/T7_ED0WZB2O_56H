#include <misc.h>
#include <t7types.h>
//#include <stddef.h>

#ifndef HFMCAL_H_
#define HFMCAL_H_

typedef struct HFMCalType
{
	u16 Q_Tab[18];
	u16 t_SP[18];
} HFMCal_T;

extern HFMCal_T HFMCal;

#endif /* HFMCAL_H_ */
