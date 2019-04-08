#include <t7types.h>

#ifndef __VARS_HEADER__
#define __VARS_HEADER__
extern u8 ROM_WriteProtectedECU[4];
extern u16 ROM_LocalID[256];
extern u8 ROM_SymbolNames[26800];
extern u16 RAM_overrun_obj;
extern u32 RAM_VBUSOperationalReptime;
extern u8 RAM_VBUSDebugID;
extern u8 RAM_ManActivInjection;
extern u8 RAM_VBUS_W_Rptrdiff;
extern u8 RAM_VBUSOperationalMode;
extern u16 RAM_CANOverrunCnt;
extern u16 RAM_Length[60];
extern u8 RAM_throtDiaAdapErrorBuf[5];
extern u8 RAM_AdaptionData592[3];
extern u8 RAM_CalibrationData592[10];
extern u16 RAM_EnableThrError;
extern u32 RAM_Da_0;
extern u32 RAM_Da_1;
extern u32 RAM_Da_2;
extern u32 RAM_Da_3;
extern u32 RAM_Da_4;
extern u32 RAM_Da_5;
extern u32 RAM_Da_6;
extern u32 RAM_Da_7;
extern u8 RAM_AmosCal[430];
extern u32 RAM_TimerCheckMax[8];
extern u16 RAM_n_LostFuelMasterCalls;
extern u8 RAM_LastModifiedBy[15];
extern u16 RAM_I_EgasZeroAdaption;
extern i8 RAM_Data_name[13];
extern u8 RAM_Immobilizer_Enable;
extern u16 RAM_X_AccPedalAutTAB[6];
extern u16 RAM_X_AccPedalAutSP[6];
extern u16 RAM_X_AccPedalManTAB[6];
extern u16 RAM_X_AccPedalManSP[6];
extern u32 RAM_v_VehicleConstant;
extern u16 RAM_deviation_filter_factor;
extern u16 RAM_AirctlRequest;
extern i16 RAM_limit_pos;
extern i16 RAM_limit_neg;
extern u8 RAM_AirmassMaster_Status;
extern u16 RAM_m_Driver;
extern u16 RAM_m_CC;
extern u16 RAM_m_DriveMaster;
extern u16 RAM_m_Wheel;
extern u16 RAM_m_LoadComp;
extern u16 RAM_m_Idle;
extern u16 RAM_m_nLow;
extern u16 RAM_m_nHigh;
extern u16 RAM_m_Master;
extern u16 RAM_m_Request;
extern u8 RAM_m_DriverStatus;
extern u8 RAM_m_CCStatus;
extern u8 RAM_m_WheelStatus;
extern u8 RAM_m_LoadCompStatus;
extern u8 RAM_m_IdleStatus;
extern u8 RAM_m_nLowStatus;
extern u8 RAM_m_nHighStatus;
extern u8 RAM_m_MasterStatus;
extern u8 RAM_m_RequestStatus;
extern u8 RAM_a601_status;
extern u8 RAM_a201_Status;
extern u8 RAM_a202_Status;
extern u8 RAM_a203_Status;
extern u8 RAM_a204_Status;
extern u8 RAM_a205_Status;
extern i32 RAM_v_delta_help;
extern i32 RAM_wheel_torque_actual;
extern i32 RAM_wheel_torque_max;
extern i32 RAM_wheel_torque_negative;
extern u16 RAM_TapUpStep;
extern u16 RAM_TapDownStep;
extern i16 RAM_tip_help;
extern i16 RAM_Init_puls;
extern i16 RAM_a_help;
extern i32 RAM_init_help;
extern i32 RAM_init_help1;
extern i16 RAM_Max_Init;
extern i16 RAM_Init_puls_unlimited;
extern i16 RAM_Init_Torque_Pos;
extern i16 RAM_Init_Torque_Neg;
extern u16 RAM_tmp_cd;
extern u16 RAM_tmp_pdiff;
extern u16 RAM_tmp_temp;
extern u8 RAM_ST_SignalFault;
extern u16 RAM_CatOx2ABSBuf[20];
extern u8 RAM_obdMilCount[6];
extern u16 RAM_obdFaults[6];
extern u16 RAM_obdFFs[12];
extern u8 RAM_O2SensPreTest2Cond;
extern u8 RAM_obdNoOfDiagFunk;
extern u16 RAM_U_lambda_probe;
extern u8 RAM_BeforeStartState;
extern i16 RAM_adjust_max_fi_offset;
extern u32 RAM_resetLimitTimer;
extern u32 RAM_killTimer;
extern u32 RAM_lockTimer;
extern u8 RAM_resetLimitTimerStatus;
extern u16 RAM_v_Immo;
extern u8 RAM_ImmoCode[6];
extern u16 RAM_ControlWord;
extern u8 RAM_PLT_buffer[10000];
extern u16 RAM_PLT_bufferpos;
extern u32 RAM_PLT_pointer[14];
extern u8 RAM_PLT_variablesize[14];
extern u8 RAM_PLT_timebase;
extern u8 RAM_PLT_delay;
extern u32 RAM_PLT_TriggVar[2];
extern i32 RAM_PLT_TriggValue[2];
extern u16 RAM_PLT_TriggDelay[2];
extern u8 RAM_Trigger_state;
extern u32 RAM_TimerCheck[8];
extern u16 RAM_Time_1_3;
extern u16 RAM_Time_2_3;
extern u16 RAM_Time_3_4;
extern u16 RAM_HighTime1;
extern u16 RAM_WinTime1;
extern u16 RAM_HighTime2;
extern u16 RAM_WinTime2;
extern i16 RAM_tmpqair;
extern u16 RAM_hfmOffsetSimFac;
extern u8 RAM_linkstatus;
extern u32 RAM_VIOS_ExceptionAddress;
extern u8 RAM_VIOS_ExceptionReason;
extern u8 RAM_VIOS_ResetType;
extern u8 RAM_WorkShopSnapshotBuffer[108];
extern u16 RAM_localprescomp;
extern u8 RAM_prescompflag;
extern u8 RAM_closed_loop_test;
extern u8 RAM_help_m_master_status;
extern u16 RAM_t_delta_help;
extern i16 RAM_Fahr_Widerstand;
extern u16 RAM_speed_old;
extern u16 RAM_speed;
extern u8 RAM_table_pointer;
extern u8 RAM_table_pointer_old;
extern i16 RAM_v_limit_diff;
extern u16 RAM_v_limit_old;
extern i16 RAM_airmass_integrator;
extern u16 RAM_airmass_help1;
extern u16 RAM_ratio_filter_const;
extern u16 RAM_ratio_filter_const_old;
extern i32 RAM_offset;
extern i32 RAM_wheel_torque_help;
extern i32 RAM_wheel_torque_min;
extern u8 RAM_only_init_no_50ms_add;
extern u8 RAM_TestLimit;
extern u16 RAM_obdPAirInletStatus;
extern u16 RAM_obdInletAirPErrorAt;
extern u8 RAM_InletcompareResult;
extern u8 RAM_fCutResult;
extern u8 RAM_fCutPressureOK;
extern u8 RAM_noOfFuelCutOKReadings;
extern u8 RAM_noOfFuelCutErrorReadings;
extern u16 RAM_obdPAirBefThrottleStatus;
extern u16 RAM_obdBefThrottleAirPErrorAt;
extern u8 RAM_BefThrotcompareResult;
extern u16 RAM_obdPBefThrotHoseStatus;
extern u16 RAM_obdPAirAmbientStatus;
extern u16 RAM_obdAmbientAirPErrorAt;
extern u8 RAM_AmbientcompareResult;
extern u16 RAM_obdQAirInletStatus;
extern u8 RAM_obdAirmCompNoSteadyState;
extern u8 RAM_obdAirmCompNoBypassSteadyState;
extern i32 RAM_obdAirmCompThrottlePercent;
extern i32 RAM_obdAirmCompThrottleHiPercent;
extern i32 RAM_obdAirmCompThrottleCount;
extern i32 RAM_obdAirmCompThrottleHiCount;
extern i32 RAM_obdMeanAirmCompEval;
extern i32 RAM_obdMeanAirmCompHiEval;
extern i32 RAM_obdAirmCompLastHiMeanVal;
extern i32 RAM_obdAirmCompLastMeanVal;
extern i32 RAM_obdLatestHiMeanAirmCompEval;
extern i32 RAM_obdLatestMeanAirmCompEval;
extern u8 RAM_obdQuickChangeError;
extern u8 RAM_obdAirmThrottleAreaAdpCondOK;
extern u8 RAM_obdAirmTempfilterOK;
extern u8 RAM_obdAirmRPMfilterOK;
extern u8 RAM_obdAirmLoadfilterOK;
extern u8 RAM_obdAirmPDiffFilterOK;
extern u8 RAM_obdAirmThrottleAreafilterOK;
extern u8 RAM_obdAirmHiSpeedTimerFilterOK;
extern i16 RAM_obdPlottThrottlePercent;
extern u8 RAM_obdAirmPreConditionOK;
extern u8 RAM_obdAirmThrottleTestOK;
extern u16 RAM_obdBoostControlStatus;
extern u16 RAM_obdBoostControlDiff;
extern u8 RAM_adapBoostControlPtr;
extern u16 RAM_obdTurboBypassStatus;
extern u16 RAM_obd_amplitudePressure;
extern u16 RAM_obdBypassOkCounter;
extern u16 RAM_obd_BypassWorstAmp;
extern u16 RAM_obd_BypassLeastAmp;
extern u16 RAM_obd_pBefSampleBufPointer;
extern u8 RAM_obd_pBefPerformDiag;
extern u32 RAM_obdBypassReleaseTimer;
extern i32 RAM_obdBypassDrop;
extern u16 RAM_obdCatalystStatus;
extern u8 RAM_catStatusDeltaLoadOk;
extern u8 RAM_catStatusCoolTempOk;
extern u8 RAM_catStatusClosedLoopOk;
extern u8 RAM_catStatusLoadOk;
extern u8 RAM_catStatusRpmOk;
extern u8 RAM_catStatusReadyTimerOk;
extern u8 RAM_catStatusPeriodOk;
extern u8 RAM_catStatusDutyCycleOk;
extern u8 RAM_catStatusStartTimerOk;
extern u8 RAM_catStatusThrottleOpenOk;
extern u8 RAM_catStatusSensorOk;
extern i16 RAM_CatDeltaLoad;
extern i16 RAM_AdapDeltaLoad;
extern u16 RAM_CatLoadFilt;
extern i16 RAM_AdapLoadFiltRest;
extern i16 RAM_AdapLoadFilt;
extern u32 RAM_AdapStableTimer;
extern u16 RAM_CatOx1Filt;
extern u16 RAM_CatOx2Filt;
extern i16 RAM_CatDevDiffFiltMax;
extern i16 RAM_CatOx1Dev;
extern u16 RAM_CatOx1ABS;
extern u16 RAM_CatOx1ABSFilt;
extern i16 RAM_CatOx2Dev;
extern u16 RAM_CatOx2ABS;
extern u16 RAM_CatOx2ABSFilt;
extern u16 RAM_CatSignalQuote;
extern u16 RAM_CatDevDiff;
extern u16 RAM_CatOx2DevLim;
extern u16 RAM_CatStableTimer;
extern u16 RAM_CatReadyTimer;
extern u16 RAM_CatStartTimer;
extern u16 RAM_CatLowLoadTimer;
extern u16 RAM_CatHlTimer;
extern u16 RAM_CatIdleTimer;
extern u16 RAM_CatFcTimer;
extern u32 RAM_CatOx2ProcessTime;
extern u32 RAM_CatOx2ProcessInvalidTime;
extern u16 RAM_CatOx1CycleTimeHiLim;
extern u16 RAM_CatOx1CycleTimeLoLim;
extern u16 RAM_CatOx1CycleTime;
extern u16 RAM_CatOx1DutyCycle;
extern u8 RAM_CatStableOK;
extern u8 RAM_CatNrOfEmptyBufPos;
extern u16 RAM_obdCatDiagLevStatus;
extern u8 RAM_obdCatDiagLevActive;
extern i16 RAM_obdCatDiagLevLambdaIntMeanValue;
extern u16 RAM_obdErrorAtLine;
extern u8 RAM_obdCheckEngineLamp;
extern u8 RAM_obdOutOfLimits;
extern u16 RAM_obdNoOfFaults;
extern u16 RAM_obdLastFault;
extern u8 RAM_obdKeyOn;
extern u8 RAM_obdEngRunning;
extern u8 RAM_obdRunningIdle;
extern u8 RAM_obdIsEngineHot;
extern u8 RAM_obdWarmUpCycle;
extern u8 RAM_obdRunningClosedLoop;
extern u8 RAM_obdDrivingCycleDone;
extern u8 RAM_obdDiagCompleteTrip;
extern u16 RAM_obdNoOfRuns;
extern i16 RAM_obdStartTemp;
extern i16 RAM_obdInletStartTemp;
extern u32 RAM_obdRunTime;
extern u32 RAM_obdTotalRunTime;
extern u8 RAM_obdMisfComplete;
extern u8 RAM_obdFuelTrimComplete;
extern u8 RAM_obdComponentComplete;
extern u8 RAM_obdCatalystComplete;
extern u8 RAM_obdSAIComplete;
extern u8 RAM_obdEvapComplete;
extern u8 RAM_obdO2SensorsComplete;
extern u8 RAM_obdO2HeatersComplete;
extern i16 RAM_obdTestPos;
extern u16 RAM_obdO2HeatPreStatus;
extern u16 RAM_obdO2SensPreStatus;
extern i16 RAM_t_O2SPreHeatBefTest;
extern u16 RAM_obdO2SensPreDeadtime;
extern u16 RAM_obdO2SensPreLowtime;
extern u16 RAM_obdO2SensPreLowToHeatertime;
extern u16 RAM_obdO2SensFreqStatus;
extern i16 RAM_O2SensFreqCombustCnt;
extern i16 RAM_O2SensFreqFlankShiftCnt;
extern u8 RAM_O2FrequencyTestDone;
extern i16 RAM_O2FrequencyLoadCnt;
extern u8 RAM_obdO2FrontFreqTestActive;
extern i16 RAM_SondDeltaLoad;
extern u16 RAM_obdO2SensSPStatus;
extern u16 RAM_obdO2HeatPostStatus;
extern u16 RAM_obdO2SensPostStatus;
extern u16 RAM_obdO2SensPostLowtime;
extern u16 RAM_obdO2SensPostLowToHeatertime;
extern u8 RAM_obdO2SensPostDeadTestDone;
extern u8 RAM_obdO2SensPostLowTestDone;
extern u8 RAM_obdO2SensPostDeadTestEnabled;
extern u16 RAM_obdShortTFuelTrimStatus;
extern u8 RAM_obdSTFT_sameDriveCond;
extern u8 RAM_obdSTFT_foundOk;
extern u16 RAM_obdLTMulFuelTrimStatus;
extern u8 RAM_obdLTMFT_sameDriveCond;
extern u8 RAM_obdLTMFT_foundOK;
extern u16 RAM_obdLTAddFuelTrimStatus;
extern u8 RAM_obdLTAFT_sameDriveCond;
extern u8 RAM_obdLTAFT_foundOK;
extern u16 RAM_obdLambdaStartTimeStatus;
extern u32 RAM_obdLambdaStartTimer;
extern u16 RAM_obdStartTempState;
extern u32 RAM_obdTEngineAccumAir;
extern u16 RAM_obdTEngine_mAirperDegree;
extern i16 RAM_obdTEngCombust;
extern i16 RAM_obdTEngStartCombFac;
extern i16 RAM_obdTEngine_mAirComb;
extern i16 RAM_obdTEngineLoadFac;
extern u16 RAM_obdMisfireCVSStatus;
extern u8 RAM_obdMISFCVS_sameDriveCond;
extern u8 RAM_obdMISFCVS_foundOK;
extern u16 RAM_nrOfBlocksCVSEvaluated;
extern u16 RAM_nrOfCVSEvalCombustInBlock;
extern u8 RAM_misfireFilterActive;
extern u8 RAM_obdMisfCVSMilCount;
extern u16 RAM_obdMisfireTempStatus;
extern u8 RAM_obdMISFTEMP_sameDriveCond;
extern u8 RAM_obdMISFTEMP_foundOK;
extern u16 RAM_nrOfBlocksTempEvaluated;
extern u16 RAM_nrOfTempEvalCombustInBlock;
extern u8 RAM_obdMisfAdjustForO2RearSensor;
extern u8 RAM_obdMisfO2RearAdjBlockErrCnt;
extern u8 RAM_obdMisfO2RearAdjBlockOKCnt;
extern u32 RAM_tempDetectAvLevelCyl[4];
extern u16 RAM_n_detectAvLevel[4];
extern u16 RAM_MissfLevel;
extern u8 RAM_obdNoOfDiagDone;
extern u16 RAM_obdThrLimpHomeStatus;
extern u16 RAM_obdCrankcaseVentStatus;
extern u16 RAM_obdOutpCMDPurgeDiagStatus;
extern u16 RAM_obdOutpESTStatus;
extern u16 RAM_obdOutpPumpRlyStatus;
extern u16 RAM_obdOutpMainRlyStatus;
extern u16 RAM_obdOutpACRlyStatus;
extern u16 RAM_obdOutpInjStatus;
extern u16 RAM_obdOutpPWPurgeStatus;
extern u16 RAM_obdOutCMDSAIPumpDiagStatus;
extern u16 RAM_obdXErrorAtLine;
extern u8 RAM_obdMode8EvapTestAllowed;
extern u16 RAM_obdDebugStatus;
extern u16 RAM_obdTCMStatus;
extern u8 RAM_TCMErrorCountDone;
extern u16 RAM_obdTCSStatus;
extern u8 RAM_TCSErrorCountDone;
extern u16 RAM_obdMIUDiagStatus;
extern u8 RAM_MIUErrorCountDone;
extern u16 RAM_obdKnockStatus;
extern u16 RAM_obdEngineSyncStatus;
extern u16 RAM_obdImmobilizerStatus;
extern u16 RAM_obdBrakeLightStatus;
extern u32 RAM_obdBrakeLightTimer;
extern u16 RAM_obdDetectSignal1Status;
extern u16 RAM_obdDetectSignal2Status;
extern u16 RAM_obdEOLProgStatus;
extern u16 RAM_obdV_VehicleStatus;
extern u8 RAM_obdNoSpeedSignal;
extern u16 RAM_obdMaxSpeed;
extern u16 RAM_obdMinSpeed;
extern u16 RAM_obdCurrSpeed;
extern u32 RAM_obdnosignalTime;
extern u16 RAM_obdN_EngineStatus;
extern u8 RAM_obdNEngineUBattIgnOn;
extern u8 RAM_obdNrOfLostEnginePosition;
extern u8 RAM_obdLostEnginePosition;
extern u8 RAM_obdEnginePosFound;
extern u16 RAM_IdleSpeedDiagStatus;
extern u16 RAM_obdTAirInletStatus;
extern u16 RAM_obdTEngineStatus;
extern u16 RAM_obdTEngQCtempDiff;
extern u16 RAM_obdTEngQCStack[10];
extern u16 RAM_obdTEngQCMeanValueStack;
extern u32 RAM_obdTEngDeadCombustion;
extern u8 RAM_obdTEngTempChange;
extern u16 RAM_obdTCoolingSystemStatus;
extern u16 RAM_obdTCoolingSystemPreCond;
extern u32 RAM_SafetyReqSpecTest;
extern u16 RAM_obdThrottleSensorStatus;
extern u16 RAM_obdThrottleSensorLimpHomeStatus;
extern u16 RAM_obdThrottleMechStatus;
extern u16 RAM_obdInternalECUStatus;
extern u16 RAM_obdPedalSensorStatus;
extern u16 RAM_obdPedalSensorLimpHomeStatus;
extern u16 RAM_obdThrottleLimpHomeStatus;
extern u16 RAM_obdThrottleInLimpHomeStatus;
extern u16 RAM_timerErrorAt;
extern u16 RAM_FuelCalcDelay[14];
extern u8 RAM_n_FuelCalc;
extern i16 RAM_m_Purge;
extern u32 RAM_t_reStartStamp;
extern u32 RAM_old_time;
extern u8 RAM_number_since_last;
extern u8 RAM_AftSt1ExtraFactor;
extern u8 RAM_AftSt2ExtraFactor;
extern i16 RAM_IgnTorqueAngle;
extern u8 RAM_Ad_0;
extern u8 RAM_Ad_1;
extern u8 RAM_Ad_2;
extern u8 RAM_Ad_3;
extern u8 RAM_Ad_4;
extern u8 RAM_Ad_5;
extern u8 RAM_Ad_6;
extern u8 RAM_Ad_7;
//extern u8 [130];
extern u8 RAM_HardwareRevision;
extern u8 RAM_ImmoState;
extern u32 RAM_PlotTimer;
extern u32 RAM_DiagnosThisPtr;
extern u8 RAM_triggerRestart;
extern u16 RAM_TIME_AFTDETWIN;
extern u16 RAM_TIME_1_2b;
extern u16 RAM_TIME_DETWINMULTI;
extern u16 RAM_TIME_DETWINNORMAL;
extern i16 RAM_Angle_4_5;
extern u8 RAM_IgnActive;
extern u8 RAM_IgnPulseWaiting;
extern u16 RAM_ActualKnockCyl;
extern u8 RAM_MultiIgnMode;
extern u8 RAM_FirstUpdate;
extern u16 RAM_Pos_720;
extern u8 RAM_PMMXCopy;
extern u32 RAM_maf_frequency;
extern u8 RAM_UartIntCnt;
extern u8 RAM_SendTriggCnt;
extern u16 RAM_rxErrorCount;
#endif