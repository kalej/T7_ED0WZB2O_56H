#include <t7types.h>

#ifndef __COMDATA_H__
#define __COMDATA_H__
typedef struct ComDataType
{
	u8 Fr592StatusCCL;
	u8 Fr592MonStim;
	u8 Fr592MonAnsw;
	u8 Fr592Failure[3];
	u8 To592MonStim;
	u8 To592MonAnsw;
	u8 To592Reaction;
	u8 Fr592RamData1;
	u8 Fr592RamData2;
	u16 Fr592RamWord;
	u16 To592RamAdr1;
	u16 To592RamAdr2;
} ComData_T;
extern ComData_T ComData;
#endif
