int TorqueStorage_Proc()
{
  char v0; // bl
  char v1; // bl
  unsigned int v3; // [esp+28h] [ebp-28h]
  unsigned int v4; // [esp+28h] [ebp-28h]
  int v5; // [esp+30h] [ebp-20h]
  char *v6; // [esp+44h] [ebp-Ch]
  u8 *v7; // [esp+44h] [ebp-Ch]

  if ( TrqStorage.m_WheelStatus )
  {
    if ( TrqStorage.a601_status )
    {
      if ( TrqStorage.m_Wheel >= (unsigned int)TrqStorage.m_DriveMaster )
      {
        TrqStorage.m_MaxOfWheelAndDriveMast = TrqStorage.m_DriveMaster;
        TrqStorage.a201_Status = TrqStorage.a601_status;
      }
      else
      {
        TrqStorage.m_MaxOfWheelAndDriveMast = TrqStorage.m_Wheel;
        TrqStorage.a201_Status = TrqStorage.m_WheelStatus;
        RAM_AirmassMaster_Status = 4;
      }
    }
    else
    {
      TrqStorage.m_MaxOfWheelAndDriveMast = TrqStorage.m_Wheel;
      TrqStorage.a201_Status = TrqStorage.m_WheelStatus;
      RAM_AirmassMaster_Status = 4;
    }
  }
  else if ( TrqStorage.a601_status )
  {
    TrqStorage.m_MaxOfWheelAndDriveMast = TrqStorage.m_DriveMaster;
    TrqStorage.a201_Status = TrqStorage.a601_status;
  }
  else
  {
    TrqStorage.m_MaxOfWheelAndDriveMast = TrqStorage.m_DriveMaster;
    TrqStorage.a201_Status = 0;
  }
  if ( TrqStorage.m_LoadCompStatus )
  {
    if ( TrqStorage.a201_Status )
    {
      v3 = TrqStorage.m_LoadComp + TrqStorage.m_MaxOfWheelAndDriveMast;
      if ( v3 <= 0xFFFF )
        TrqStorage.field_18 = v3;
      else
        TrqStorage.field_18 = -1;
      if ( TrqStorage.m_MaxOfWheelAndDriveMast )
        v0 = TrqStorage.a201_Status;
      else
        v0 = TrqStorage.m_LoadCompStatus;
      TrqStorage.a202_Status = v0;
    }
    else
    {
      TrqStorage.field_18 = TrqStorage.m_LoadComp;
      TrqStorage.a202_Status = TrqStorage.m_LoadCompStatus;
    }
  }
  else if ( TrqStorage.a201_Status )
  {
    TrqStorage.field_18 = TrqStorage.m_MaxOfWheelAndDriveMast;
    TrqStorage.a202_Status = TrqStorage.a201_Status;
  }
  else
  {
    TrqStorage.field_18 = TrqStorage.m_MaxOfWheelAndDriveMast;
    TrqStorage.a202_Status = 0;
  }
  if ( TrqStorage.m_IdleStatus )
  {
    if ( TrqStorage.a202_Status )
    {
      v4 = TrqStorage.m_Idle + TrqStorage.field_18;
      if ( v4 <= 0xFFFF )
        TrqStorage.field_20 = v4;
      else
        TrqStorage.field_20 = -1;
      if ( TrqStorage.m_MaxOfWheelAndDriveMast )
        v1 = TrqStorage.a202_Status;
      else
        v1 = TrqStorage.m_IdleStatus;
      TrqStorage.a203_Status = v1;
    }
    else
    {
      TrqStorage.field_20 = TrqStorage.m_Idle;
      TrqStorage.a203_Status = TrqStorage.m_IdleStatus;
    }
  }
  else if ( TrqStorage.a202_Status )
  {
    TrqStorage.field_20 = TrqStorage.field_18;
    TrqStorage.a203_Status = TrqStorage.a202_Status;
  }
  else
  {
    TrqStorage.field_20 = TrqStorage.field_18;
    TrqStorage.a203_Status = 0;
  }
  v6 = &TrqStorage.m_nLowStatus;
  if ( TrqStorage.m_nLowStatus )
  {
    if ( TrqStorage.a203_Status )
    {
      if ( (unsigned int)TrqStorage.m_nLow <= TrqStorage.field_20 )
      {
        TrqStorage.field_28 = TrqStorage.field_20;
        TrqStorage.a204_Status = TrqStorage.a203_Status;
      }
      else
      {
        TrqStorage.field_28 = TrqStorage.m_nLow;
        TrqStorage.a204_Status = *v6;
        RAM_AirmassMaster_Status = 8;
      }
    }
    else
    {
      TrqStorage.field_28 = TrqStorage.m_nLow;
      TrqStorage.a204_Status = *v6;
      RAM_AirmassMaster_Status = 8;
    }
  }
  else if ( TrqStorage.a203_Status )
  {
    TrqStorage.field_28 = TrqStorage.field_20;
    TrqStorage.a204_Status = TrqStorage.a203_Status;
  }
  else
  {
    TrqStorage.field_28 = TrqStorage.field_20;
    TrqStorage.a204_Status = 0;
  }
  v7 = &TrqStorage.m_nHighStatus;
  if ( TrqStorage.m_nHighStatus )
  {
    if ( TrqStorage.a204_Status )
    {
      if ( TrqStorage.m_nHigh >= TrqStorage.field_28 )
      {
        TrqStorage.m_Master = TrqStorage.field_28;
        RAM_help_m_master_status = TrqStorage.a204_Status;
      }
      else
      {
        TrqStorage.m_Master = TrqStorage.m_nHigh;
        RAM_help_m_master_status = *v7;
        RAM_AirmassMaster_Status = 16;
      }
    }
    else
    {
      TrqStorage.m_Master = TrqStorage.m_nHigh;
      RAM_help_m_master_status = *v7;
      RAM_AirmassMaster_Status = 16;
    }
  }
  else if ( TrqStorage.a204_Status )
  {
    TrqStorage.m_Master = TrqStorage.field_28;
    RAM_help_m_master_status = TrqStorage.a204_Status;
  }
  else
  {
    TrqStorage.m_Master = TrqStorage.field_28;
    RAM_help_m_master_status = 0;
  }
  v5 = Calc_BoostProt_P_DiffILimReq();
  if ( Boost.AirMasterStatus == 1 && !RAM_closed_loop_test )
    RAM_help_m_master_status = 1;
  if ( ECMStat.ST_ThrottleLimpHome == 1 || Fault.p_AirInlet || Fault.p_AirBefThrottle )
    RAM_help_m_master_status = 1;
  if ( RAM_help_m_master_status > 2u )
    RAM_help_m_master_status = 2;
  if ( !RAM_help_m_master_status )
    TrqStorage.m_Master = 100;
  byte_F0DC40 = 1;
  TrqStorage.m_MasterStatus = RAM_help_m_master_status;
  RAM_m_Driver = TrqStorage.m_Driver;
  RAM_m_CC = TrqStorage.m_CC;
  RAM_m_DriveMaster = TrqStorage.m_DriveMaster;
  RAM_m_Wheel = TrqStorage.m_Wheel;
  RAM_m_LoadComp = TrqStorage.m_LoadComp;
  RAM_m_Idle = TrqStorage.m_Idle;
  RAM_m_nLow = TrqStorage.m_nLow;
  RAM_m_nHigh = TrqStorage.m_nHigh;
  RAM_m_Master = TrqStorage.m_Master;
  RAM_m_DriverStatus = TrqStorage.m_DriverStatus;
  RAM_m_CCStatus = TrqStorage.m_CCStatus;
  RAM_m_WheelStatus = TrqStorage.m_WheelStatus;
  RAM_m_LoadCompStatus = TrqStorage.m_LoadCompStatus;
  RAM_m_IdleStatus = TrqStorage.m_IdleStatus;
  RAM_m_nLowStatus = TrqStorage.m_nLowStatus;
  RAM_m_nHighStatus = TrqStorage.m_nHighStatus;
  RAM_m_MasterStatus = TrqStorage.m_MasterStatus;
  RAM_a601_status = TrqStorage.a601_status;
  RAM_a201_Status = TrqStorage.a201_Status;
  RAM_a202_Status = TrqStorage.a202_Status;
  RAM_a203_Status = TrqStorage.a203_Status;
  RAM_a204_Status = TrqStorage.a204_Status;
  RAM_a205_Status = RAM_m_MasterStatus;
  if ( !MonStim.State )
  {
    MonStim.Calc -= 5;
    MonStim.S[21] = MonStim.Calc;
    MonStim.State = 1;
  }
  return v5;
}
