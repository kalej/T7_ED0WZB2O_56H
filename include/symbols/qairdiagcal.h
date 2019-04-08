#include <t7types.h>

#ifndef __QAIRDIAGCAL_H__
#define __QAIRDIAGCAL_H__
typedef struct QAirDiagCalType
{
	u8 SampleInterval;
	u16 QuickChangeLim;
	u16 hiWindowLim;
	i16 errorLimB;
	i16 errorLimD;
	i16 errorLimE;
	i16 errorLimF;
	i16 adapLimA;
	i16 adapLimC;
	u16 devPInlet;
	u16 devAThrottle;
	u16 maxLoad;
	u16 minLoad;
	u16 firstSteady;
	u16 bypassSteady;
	u16 minRPM;
	u16 maxRPM;
	i16 T_MinForTest;
	i16 T_MaxForTest;
	u16 maxPDiff;
	u16 minPDiff;
	u16 maxArea;
	u16 minArea;
	u32 timeToStart;
	u16 speedToStart;
	u16 devRPMmin;
	u16 devRPMtime;
	u16 devFaultTime;
	u16 n_samplesForEval;
	i16 AdapLimLambdaOLoop;
	i16 AdapLimUseFAdap;
	i16 HFMOffSimSP[8];
	u16 HFMOffSim[8];
	u8 EnableHFMOffset;
} QAirDiagCal_T;
extern QAirDiagCal_T QAirDiagCal;
#endif
