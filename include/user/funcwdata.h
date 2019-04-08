#include <t7types.h>

#ifndef FUNCWDATA_H_
#define FUNCWDATA_H_

typedef struct FuncWDataType
{
	void (*pproc)(u16);
	i32 field_4;
	i32 field_8;
} FuncWData_T;

extern FuncWData_T FuncsWData[14];
#endif /* FUNCWDATA_H_ */
