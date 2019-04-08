#include <t7types.h>

#ifndef __ECUID_H__
#define __ECUID_H__
typedef struct ECUIDType
{
	u8 ScaleTable[34];
	u8 VehicleIdNr[17];
	u8 PartNrAlphaCode[9];
	u8 ECUHardwNr[15];
	u8 ECUHardwVersNr[7];
	u8 ECUSoftwNr[16];
	u8 ECUSoftwVersNr[12];
	u8 TesterSerialNr[13];
	u8 SoftwareDate[6];
	u8 ECUDiagDataID[4];
} ECUID_T;
extern ECUID_T ECUID;
#endif
