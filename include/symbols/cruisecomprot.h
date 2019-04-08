#include <t7types.h>

#ifndef __CRUISECOMPROT_H__
#define __CRUISECOMPROT_H__
typedef struct CruiseComProtType
{
	u8 Status;
	u8 StatusInit;
	u8 RoadTimer;
} CruiseComProt_T;
extern CruiseComProt_T CruiseComProt;
#endif
