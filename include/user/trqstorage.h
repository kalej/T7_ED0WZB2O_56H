#ifndef INCLUDE_USER_TRQSTORAGE_H_
#define INCLUDE_USER_TRQSTORAGE_H_

#include <t7types.h>

typedef struct
{
	//00000000 m_Driver        dw ?                    ; XREF: AirmassMaster_Status_Proc+A6/r
	u16 m_Driver;
	//00000002 m_DriverStatus  db ?                    ; XREF: Cruise_Proc:lbl_01091E/r
	u8 m_DriverStatus;
	//00000003 field_3         db ?
	//00000004 m_CC            dw ?                    ; XREF: Calc_CruiseProt_M_DelWheelLim+246/r
	u16 m_CC;
	//00000006 m_CCStatus      db ?                    ; XREF: Calc_MaxVehicleSpeed_Values+8E/w
	u8 m_CCStatus;
	//00000007 field_7         db ?
	//00000008 m_DriveMaster   dw ?                    ; XREF: Calc_ECMStat_P_Engine+328/r
	u16 m_DriveMaster;
	//0000000A a601_status     db ?
	u8 a601_status;
	//0000000B field_B         db ?
	//0000000C m_Wheel         dw ?                    ; XREF: Calc_Boost_NoiseReduction+46/r
	u16 m_Wheel;
	//0000000E m_WheelStatus   db ?
	u8 m_WheelStatus;
	//0000000F field_F         db ?
	//00000010 m_MaxOfWheelAndDriveMast dw ?
	u16 m_MaxOfWheelAndDriveMast;
	//00000012 a201_Status     db ?
	u8 a201_Status;
	//00000013 field_13        db ?
	//00000014 m_LoadComp      dw ?                    ; XREF: Calc_CruiseProt_m_AirRequest:lbl_00F806/r
	u16 m_LoadComp;
	//00000016 m_LoadCompStatus db ?                   ; XREF: Calc_CruiseProt_m_AirRequest:lbl_00F7FE/r
	u8 m_LoadCompStatus;
	//00000017 field_17        db ?
	//00000018 field_18        dw ?
	u16 field_18;
	//0000001A a202_Status     db ?
	u8 a202_Status;
	//0000001B field_1B        db ?
	//0000001C m_Idle          dw ?                    ; XREF: Calc_CruiseProt_m_AirRequest:lbl_00F81A/r
	u16 m_Idle;
	//0000001E m_IdleStatus    db ?                    ; XREF: Calc_CruiseProt_m_AirRequest:lbl_00F812/r
	u8 m_IdleStatus;
	//0000001F field_1F        db ?
	//00000020 field_20        dw ?
	u16 field_20;
	//00000022 a203_Status     db ?
	u8 a203_Status;
	//00000023 field_23        db ?
	//00000024 m_nLow          dw ?                    ; XREF: Calc_CruiseProt_m_AirRequest:lbl_00F7EC/r
	u16 m_nLow;
	//00000026 m_nLowStatus    db ?                    ; XREF: Calc_CruiseProt_m_AirRequest+25/r
	u8 m_nLowStatus;
	//00000027 field_27        db ?
	//00000028 field_28        dw ?
	u16 field_28;
	//0000002A a204_Status     db ?
	u8 a204_Status;
	//0000002B field_2B        db ?
	//0000002C m_nHigh         dw ?                    ; XREF: Calc_ECMStat_P_Engine+34C/o
	u16 m_nHigh;
	//0000002E m_nHighStatus   db ?
	u8 m_nHighStatus;
	//0000002F field_2F        db ?
	//00000030 m_Master        dw ?                    ; XREF: EmLim_Proc+751/w
	u16 m_Master;
	//00000032 m_MasterStatus  db ?                    ; XREF: EmLim_Proc+82B/r
	u8 m_MasterStatus;
	//00000033 field_33        db ?
} TrqStorage_T;

extern TrqStorage_T TrqStorage;
#endif /* INCLUDE_USER_TRQSTORAGE_H_ */
