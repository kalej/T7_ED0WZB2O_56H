#include "t7types.h"
#include <symbols/blockheat.h>
#include <symbols/blockheatcal.h>
#include <symbols/dncomp.h>
#include <symbols/dncompprot.h>
#include <symbols/ecmstat.h>
#include <symbols/fault.h>
#include <symbols/flashsave.h>
#include <symbols/idle.h>
#include <symbols/idleadap.h>
#include <symbols/idlecal.h>
#include <symbols/idleprot.h>
#include <symbols/ignloff.h>
#include <symbols/in.h>
#include <symbols/loadco.h>
#include <symbols/out.h>
#include <user/trqstorage.h>
#include <functions/interpolation.h>


extern u8 ECMStat_ST_AutNeutral_Old, IsStarted, ElevateIdle, ST_DriveActive_old, ST_NeutralControl_old, ST_AutNeutral_old;
extern u8 byte_F0DE9E, byte_F0DE9F;
extern u16 IdleCal_n_EngNom;
extern i16 In_n_Engine_old, Idle_I_Part;
extern u32 t_Idle_I_PartDelay2Start, t_N_StartAirMode2Start, t_IdleCalcTime, t_Idle_AdapDelayStart, t_Idle_I_PartDelayStart;

//at 013260
int Get_Idle_C_A_Part()
{
  int C_PartTabValue;

  if ( ECMStat.ST_Automatic && Fault.n_GearBoxIn && ECMStat.ST_EngineStarted )
  {
    DNCompProt.State = 2;
    Calc_DNComp_Q_AirExtra_Engaged();
  }
  else if ( Get_In_ST_IgnitionKey() )
  {
    if ( DNCompProt.State <= 3u )
    {
      switch ( DNCompProt.State )
      {
        case 0u:
          Calc_DNComp_Q_AirExtra_Steady();
          if ( (ECMStat.ST_PedalReleased && In.v_Vehicle <= 30) || ECMStat.ST_AutNeutral )
          {
            if ( ECMStat.ST_PedalReleased
              && In.v_Vehicle < 30
              && !ECMStat.ST_AutNeutral
              && ECMStat.ST_AutNeutral != ECMStat_ST_AutNeutral_Old )
            {
              DNCompProt.RampStart = 0;
              DNCompProt.RampFinished = 0;
              DNComp.IgnRampStart = 0;
              DNComp.IgnRampFinished = 0;
              DNComp.IgnRampType = 0;
              DNCompProt.State = 1;
            }
          }
          else
          {
            DNCompProt.RampStart = 0;
            DNCompProt.RampFinished = 0;
            DNComp.IgnRampStart = 0;
            DNComp.IgnRampFinished = 0;
            DNComp.IgnRampType = 0;
            DNCompProt.ActiveAirRampTimer = 0;
            DNCompProt.I_PartStart = 0;
            DNCompProt.State = 2;
          }
          break;
        case 1u:
          Calc_DNComp_Q_AirExtra_Ramping();
          if ( (ECMStat.ST_PedalReleased && In.v_Vehicle <= 30) || ECMStat.ST_AutNeutral )
          {
            if ( (ECMStat.ST_PedalReleased && In.v_Vehicle <= 30) || !ECMStat.ST_AutNeutral )
            {
              if ( ECMStat.ST_PedalReleased && In.v_Vehicle < 30 && ECMStat.ST_AutNeutral )
              {
                DNCompProt.RampStart = 0;
                DNCompProt.RampFinished = 0;
                DNComp.IgnRampStart = 0;
                DNComp.IgnRampFinished = 0;
                DNComp.IgnRampType = 0;
                DNCompProt.State = 0;
              }
              else if ( ECMStat.ST_PedalReleased
                     && In.v_Vehicle < 30
                     && !ECMStat.ST_AutNeutral
                     && IdleProt.ST_DriveActive )
              {
                DNCompProt.RampStart = 0;
                DNCompProt.RampFinished = 0;
                DNComp.IgnRampStart = 0;
                DNComp.IgnRampFinished = 0;
                DNComp.IgnRampType = 0;
                DNCompProt.ActiveAirRampTimer = 0;
                DNCompProt.I_PartStart = 0;
                DNCompProt.State = 2;
              }
            }
            else
            {
              DNCompProt.RampStart = 0;
              DNCompProt.RampFinished = 0;
              DNComp.IgnRampStart = 0;
              DNComp.IgnRampFinished = 0;
              DNComp.IgnRampType = 0;
              DNCompProt.State = 0;
            }
          }
          else
          {
            DNCompProt.RampStart = 0;
            DNCompProt.RampFinished = 0;
            DNComp.IgnRampStart = 0;
            DNComp.IgnRampFinished = 0;
            DNComp.IgnRampType = 0;
            DNCompProt.ActiveAirRampTimer = 0;
            DNCompProt.I_PartStart = 0;
            DNCompProt.State = 2;
          }
          goto lbl_013486;
        case 2u:
lbl_013486:
          if ( DNCompProt.State == 2 )
          {
            Calc_DNComp_Q_AirExtra_Engaged();
            if ( (ECMStat.ST_PedalReleased && In.v_Vehicle <= 30) || !ECMStat.ST_AutNeutral )
            {
              if ( ECMStat.ST_PedalReleased && ECMStat.ST_AutNeutral && !IdleProt.ST_DriveActive )
              {
                DNCompProt.RampStart = 0;
                DNCompProt.RampFinished = 0;
                DNComp.IgnRampStart = 0;
                DNComp.IgnRampFinished = 0;
                DNComp.IgnRampType = 0;
                DNCompProt.ActiveAirRampTimer = 0;
                DNCompProt.VSpeedIn2 = 0;
                DNCompProt.GearActivatedIn2 = 0;
                DNCompProt.I_PartStart = 0;
                DNCompProt.State = 3;
              }
            }
            else
            {
              DNCompProt.RampStart = 0;
              DNCompProt.RampFinished = 0;
              DNComp.IgnRampStart = 0;
              DNComp.IgnRampFinished = 0;
              DNComp.IgnRampType = 0;
              DNCompProt.VSpeedIn2 = 0;
              DNCompProt.GearActivatedIn2 = 0;
              DNCompProt.I_PartStart = 0;
              DNCompProt.State = 0;
            }
          }
          if ( Idle.Q_FirstDrvComp <= IdleCal.Q_FirstDrvCompRmp )
            Idle.Q_FirstDrvComp = 0;
          else
            Idle.Q_FirstDrvComp -= IdleCal.Q_FirstDrvCompRmp;
          break;
        case 3u:
          Calc_DNComp_Q_AirExtra_Disengaged();
          if ( (ECMStat.ST_PedalReleased && In.v_Vehicle <= 30) || ECMStat.ST_AutNeutral )
          {
            if ( (ECMStat.ST_PedalReleased && In.v_Vehicle <= 30) || !ECMStat.ST_AutNeutral )
            {
              if ( !ECMStat.ST_PedalReleased || IdleProt.ST_DriveActive || ECMStat.ST_AutNeutral )
              {
                if ( (ECMStat.ST_PedalReleased
                  && ECMStat.ST_AutNeutral
                  && !IdleProt.ST_DriveActive
                  && Idle.n_EngQuote > 0x78u)
                  || DNComp.n_GearBoxMissing )
                {
                  DNCompProt.RampStart = 0;
                  DNCompProt.RampFinished = 0;
                  DNComp.IgnRampStart = 0;
                  DNComp.IgnRampFinished = 0;
                  DNComp.IgnRampType = 0;
                  DNComp.ActiveIgnRamp = 0;
                  DNCompProt.State = 0;
                }
              }
              else
              {
                DNCompProt.RampStart = 0;
                DNCompProt.RampFinished = 0;
                DNComp.IgnRampStart = 0;
                DNComp.IgnRampFinished = 0;
                DNComp.IgnRampType = 0;
                DNCompProt.I_PartStart = 0;
                DNComp.ActiveIgnRamp = 0;
                DNCompProt.State = 1;
              }
            }
            else
            {
              DNCompProt.RampStart = 0;
              DNCompProt.RampFinished = 0;
              DNComp.IgnRampStart = 0;
              DNComp.IgnRampFinished = 0;
              DNComp.IgnRampType = 0;
              DNComp.ActiveIgnRamp = 0;
              DNCompProt.State = 0;
            }
          }
          else
          {
            DNCompProt.RampStart = 0;
            DNCompProt.RampFinished = 0;
            DNComp.IgnRampStart = 0;
            DNComp.IgnRampFinished = 0;
            DNComp.IgnRampType = 0;
            DNCompProt.ActiveAirRampTimer = 0;
            DNCompProt.I_PartStart = 0;
            DNComp.ActiveIgnRamp = 0;
            DNCompProt.State = 2;
          }
          break;
      }
    }
  }
  else
  {
    DNComp.fi_Offset = 0;
    DNComp.Q_AirExtra = IdleAdap.Q_AirNeutral + DNComp.C_Part[1];
    DNComp.fi_OffsetPnt = 0;
    DNCompProt.State = 0;
    DNCompProt.RampStart = 0;
    DNCompProt.RampFinished = 0;
    DNComp.IgnRampStart = 0;
    DNCompProt.ActiveAirRampTimer = ECMStat.msCounter;
    DNComp.ActiveIgnRamp = 0;
    DNComp.IgnRampFinished = 0;
    DNCompProt.VSpeedIn2 = 0;
    DNCompProt.GearActivatedIn2 = 0;
    DNComp.n_GearBoxMissing = 0;
  }
  DNCompProt.C_Part[0] = DNComp.Q_AirExtra;
  DNCompProt.C_Part[1] = DNComp.C_Part[1];
  C_PartTabValue = TAB_U16_U16(IdleCal.v_VehicleLim, In.v_Vehicle, DNCompProt.C_Part);
  DNComp.fi_OffsetPnt = Idle.Q_FirstDrvComp + C_PartTabValue - DNComp.C_Part[1] - IdleAdap.Q_AirNeutral;
  ECMStat_ST_AutNeutral_Old = ECMStat.ST_AutNeutral;
  return Idle.Q_FirstDrvComp + C_PartTabValue;
}

//at 013694
i16 Get_Idle_Parts_Summ()
{
  i16 v7;
  u8 v9;
  i16 lOff_part;
  i16 I_PartTabValue;
  i16 v13;
  u8 v15;
  i16 v16;
  i16 *pP_Part;

  v13 = 0;
  if ( ECMStat.msCounter >= t_IdleCalcTime
    || IdleProt.ST_DriveActive != ST_DriveActive_old
    || DNComp.ST_NeutralControl != ST_NeutralControl_old
    || ECMStat.ST_AutNeutral != ST_AutNeutral_old )
  {
    if ( ECMStat.ST_AutNeutral )
    {
      IdleCal_n_EngNom = TAB_I16_U16(IdleCal.T_EngineSP, In.T_Engine, IdleCal.n_EngNomNeutral);
    }
    else
    {
      IdleCal_n_EngNom = TAB_I16_U16(IdleCal.T_EngineSP, In.T_Engine, IdleCal.n_EngNomDrive);
      if ( FlashSave.Tech2IdleOffset <= 50 )
      {
        if ( FlashSave.Tech2IdleOffset < -50 )
          FlashSave.Tech2IdleOffset = -50;
      }
      else
      {
        FlashSave.Tech2IdleOffset = 50;
      }
      if ( In.T_Engine > IdleCal.T_EngineSP[7]
        || IdleCal.n_EngNomDrive[7] + FlashSave.Tech2IdleOffset > IdleCal_n_EngNom )
      {
        v13 = ((FlashSave.Tech2IdleOffset + IdleCal_n_EngNom) * IdleCal.C_PartDrive[7] / IdleCal_n_EngNom)
            - IdleCal.C_PartDrive[7];
        IdleCal_n_EngNom += FlashSave.Tech2IdleOffset;
      }
    }
    IdleProt.ST_Do_ElevIdle = 1;
    DNComp.C_Part[0] = v13 + TAB_I16_I16(IdleCal.T_EngineSP, In.T_Engine, IdleCal.C_PartDrive);
    DNComp.C_Part[1] = TAB_I16_I16(IdleCal.T_EngineSP, In.T_Engine, IdleCal.C_PartNeutral);
    if ( ECMStat.ST_BlkHeatStart && BlockHeat.C_PartNFac != 128 )
    {
      if ( !Idle.StartAirMode )
      {
        BlockHeat.C_PartNFac -= BlockHeatCal.C_PartDec;
        if ( BlockHeat.C_PartNFac < 128 )
          BlockHeat.C_PartNFac = 128;
      }
      DNComp.C_Part[1] = BlockHeat.C_PartNFac * DNComp.C_Part[1] / 128;
    }
    if ( IdleCal.n_TPartRamp <= ECMStat.n_Combustion )
    {
      IdleProt.T_Part = 0;
    }
    else
    {
      IdleProt.T_Part = ((1024 - ((ECMStat.n_Combustion << 10) / IdleCal.n_TPartRamp))
                            * TAB_I16_I16(IdleCal.T_AirSP, In.T_AirInlet, IdleCal.T_AirTab))
                      / 1024;
    }

    IdleProt.p_ambcomp = TAB_U16_I16(IdleCal.p_AirAmbSP, In.p_AirAmbient, IdleCal.Q_AirAmbTab);
    t_IdleCalcTime = ECMStat.msCounter + 1000;
    ST_DriveActive_old = IdleProt.ST_DriveActive;
    ST_AutNeutral_old = ECMStat.ST_AutNeutral;
    ST_NeutralControl_old = DNComp.ST_NeutralControl;
  }
  if ( byte_F0DE9E && ECMStat.ST_Automatic )
  {
    IdleProt.n_IdleMovAutOff = IdleCal.n_IdleMovAutOffset;
  }
  else if ( byte_F0DE9F && !byte_F0DE9E && ECMStat.ST_Automatic )
  {
    IdleProt.n_IdleMovAutOff -= 10;
    if ( IdleProt.n_IdleMovAutOff < 0 )
    {
      IdleProt.n_IdleMovAutOff = 0;
      byte_F0DE9F = 0;
    }
  }
  else
  {
    IdleProt.n_IdleMovAutOff = 0;
  }
  Idle.n_EngineNominal = IdleProt.n_ElevIdleOff
                       + LoadCo.n_NomIdleOff
                       + IdleProt.n_IdleMovAutOff
                       + IdleProt.n_EngLOffOffset
                       + IdleCal_n_EngNom;
  IdleProt.n_EngineDiff = Idle.n_EngineNominal - In.n_Engine;
  IdleProt.n_EngineDelta = In_n_Engine_old - In.n_Engine;
  In_n_Engine_old = In.n_Engine;
  if ( Out.X_AccPedal >= IdleCal.X_AccPedalLim )
  {
    if ( Out.X_AccPedal > IdleCal.X_AccPedalLim2 )
      ECMStat.ST_PedalReleased = 0;
  }
  else
  {
    ECMStat.ST_PedalReleased = 1;
  }
  if ( ECMStat.ST_PedalReleased )
  {
    if ( Idle.StartAirMode )
      Idle_I_Part = 0;
  }
  else if ( Idle.StartAirMode )
  {
    Idle_I_Part = 0;
  }
  else
  {
    Idle_I_Part = IdleCal.I_Part;
  }
  if ( In.ST_IgnitionKey )
  {
    if ( ECMStat.ST_EngineStarted
      && !Idle.StartAirMode
      && In.v_Vehicle < IdleCal.v_VehicLim
      && ECMStat.ST_PedalReleased
      && (IdleProt.n_EngineDelta < IdleCal.n_EngDeltaLim || Idle.ST_Enable)
      && IdleCal.n_EngDiffLim + Idle.n_EngineNominal > In.n_Engine
      && !ECMStat.ST_ThrottleLimpHome )
    {
      Idle.ST_Enable = 1;
      IdleProt.P_Part = TAB_I16_I16(IdleCal.P_PartSP, IdleProt.n_EngineDiff, IdleCal.P_PartTab)
    		  * IdleProt.n_EngineDiff / 1000;
      v9 = 0;
      v15 = 1;
      if ( In.T_Engine < IdleCal.T_EngineLimit
        || abs(IdleProt.n_EngineDiff) >= IdleCal.n_EngAdapLim
        || Idle.I_PartLimited
        || (Fault.M_TCMLimitReq & 0xF0)
        || IdleProt.n_EngLOffOffset
        || LoadCo.ST_IdleAdapt
        || (Fault.v_Vehicle & 0xF0)
        || ((!ECMStat.ST_TCSCANBased || Fault.M_TCSTorqueReq) && ECMStat.ST_TCSCANBased)
        || IdleProt.n_EngLOffOffset )
      {
        t_Idle_AdapDelayStart = ECMStat.msCounter + IdleCal.AdapDelay;
        Idle.ST_AdapAllowed = 0;
      }
      else if ( ECMStat.msCounter >= t_Idle_AdapDelayStart )
      {
        if ( !IdleProt.ST_DriveActive || ECMStat.ST_AutNeutral || DNComp.ST_NeutralControl )
        {
          if ( !IdleProt.ST_DriveActive && ECMStat.ST_AutNeutral && !DNComp.ST_NeutralControl )
          {
            if ( IdleProt.I_Part >= -2 )
            {
              if ( IdleProt.I_Part > 2 )
              {
                ++IdleAdap.Q_AirNeutral;
                --IdleProt.I_Part;

                if ( IdleAdap.Q_AirDrive + DNComp.C_Part[0] <= IdleAdap.Q_AirNeutral + DNComp.C_Part[1] )
                  IdleAdap.Q_AirDrive = IdleAdap.Q_AirNeutral + DNComp.C_Part[1] - DNComp.C_Part[0] + 1;
              }
            }
            else
            {
              --IdleAdap.Q_AirNeutral;
              ++IdleProt.I_Part;
            }
            if ( IdleAdap.Q_AirNeutral <= 500 )
            {
              if ( IdleAdap.Q_AirNeutral < -500 )
                IdleAdap.Q_AirNeutral = -500;
            }
            else
            {
              IdleAdap.Q_AirNeutral = 500;
            }
            t_Idle_AdapDelayStart = ECMStat.msCounter + IdleCal.AdapDelay;
            Idle.ST_AdapAllowed = 1;
          }
        }
        else
        {
          if ( IdleProt.I_Part >= -2 )
          {
            if ( IdleProt.I_Part > 2 )
            {
              ++IdleAdap.Q_AirDrive;
              if ( --IdleProt.I_Part == 2 )
                IdleProt.ST_DAdapDone = 1;
            }
          }
          else
          {
            --IdleAdap.Q_AirDrive;
            if ( ++IdleProt.I_Part == -2 )
              IdleProt.ST_DAdapDone = 1;
          }
          if ( IdleAdap.Q_AirDrive <= 200 )
          {
            if ( IdleAdap.Q_AirDrive < -200 )
              IdleAdap.Q_AirDrive = -200;
          }
          else
          {
            IdleAdap.Q_AirDrive = 200;
          }
          t_Idle_AdapDelayStart = ECMStat.msCounter + IdleCal.AdapDelay;
          Idle.ST_AdapAllowed = 1;
        }
      }
    }
    else if ( In.X_ActualGear <= IdleCal.X_ActualGearLim
           || In.v_Vehicle <= IdleCal.v_VehicleLim[1]
           || !ECMStat.ST_PedalReleased
           || IdleProt.n_EngineDelta >= IdleCal.n_EngDeltaLim2
           || ((ECMStat.ST_Automatic || ECMStat.ManualGear != 'U' || !IdleCal.ST_IdleMovCarMan)
           && (!ECMStat.ST_Automatic
            || In.X_ActualGear == 11
            || In.X_ActualGear == 12
            || In.X_ActualGear == 13
            || In.X_ActualGear == 28
            || In.X_ActualGear == 29
            || ((In.v_Vehicle >= IdleCal.v_VehicleLim2
            && (IdleProt.ST_DriveActive || DNComp.ST_NeutralControl))))) )
    {
      t_Idle_AdapDelayStart = ECMStat.msCounter + IdleCal.AdapDelay;
      Idle.ST_Enable = 0;
      Idle.ST_AdapAllowed = 0;
      v9 = 1;
      v15 = 0;
      byte_F0DE9E = 0;
      if ( IdleProt.I_Part < Idle_I_Part )
        IdleProt.I_Part = Idle_I_Part;
    }
    else
    {
      t_Idle_AdapDelayStart = ECMStat.msCounter + IdleCal.AdapDelay;
      Idle.ST_Enable = 0;
      Idle.ST_AdapAllowed = 0;
      v9 = 1;
      v15 = 1;
      byte_F0DE9E = 1;
      byte_F0DE9F = 1;
    }
  }
  else
  {
    IdleProt.I_Part = Idle_I_Part;
    v9 = 1;
    v15 = 0;
    byte_F0DE9E = 0;
  }
  if ( (v15 || IdleProt.I_Part != Idle_I_Part) && ECMStat.msCounter >= t_Idle_I_PartDelayStart )
  {
    if ( v15 )
    {
      if ( IgnLOff.fi_Offset )
        lOff_part = 400;
      else
        lOff_part = 200;
      I_PartTabValue = TAB_I16_I16(IdleCal.I_PartSP, IdleProt.n_EngineDiff, IdleCal.I_PartTab);
      if ( I_PartTabValue > 0
        || TrqStorage.m_Idle < TrqStorage.m_nLow
        || Out.A_Throttle <= 10
        || IdleProt.I_Part <= -300 )
      {
        if ( I_PartTabValue < 0
          || lOff_part <= IdleProt.I_Part
          || In.n_Engine <= IdleCal.n_LowIPart )
        {
          Idle.I_PartLimited = 1;
        }
        else
        {
          IdleProt.I_Part += I_PartTabValue;
          Idle.I_PartLimited = 0;
          if ( lOff_part < IdleProt.I_Part )
          {
            IdleProt.I_Part = lOff_part;
            Idle.I_PartLimited = 1;
          }
        }
      }
      else
      {
        IdleProt.I_Part += I_PartTabValue;
        Idle.I_PartLimited = 0;
        if ( IdleProt.I_Part < -300 )
        {
          IdleProt.I_Part = -300;
          Idle.I_PartLimited = 1;
        }
      }
    }
    else
    {
      if ( IdleProt.I_Part <= Idle_I_Part )
        v7 = IdleProt.I_Part + 5;
      else
        v7 = IdleProt.I_Part - 5;
      IdleProt.I_Part = v7;
    }
    if ( v15 )
      t_Idle_I_PartDelayStart = ECMStat.msCounter + IdleCal.I_PartDelay;
    else
      t_Idle_I_PartDelayStart = ECMStat.msCounter + IdleCal.I_PartDelay2;
  }
  if ( v9 && IdleProt.P_Part && ECMStat.msCounter >= t_Idle_I_PartDelay2Start )
  {
    pP_Part = &IdleProt.P_Part;
    if ( IdleProt.P_Part >= 0 )
      --*pP_Part;
    else
      *pP_Part = 0;
    t_Idle_I_PartDelay2Start = ECMStat.msCounter + IdleCal.I_PartDelay2;
  }
  IdleProt.C_A_Part = Get_Idle_C_A_Part();
  Idle.Q_AirFriction = DNComp.C_Part[1];
  v16 = IdleProt.p_ambcomp + IdleProt.T_Part + IdleProt.I_Part + IdleProt.P_Part + IdleProt.C_A_Part;
  if ( v16 < 0 )
    v16 = 0;
  return v16;
}

//at 0129D6
void Calc_Idle_Q_ElevIdle(void)
{
  i16 *pn_ElevIdleOff;

  pn_ElevIdleOff = &IdleProt.n_ElevIdleOff;
  if ( !ECMStat.ST_EngineStarted )
  {
    *pn_ElevIdleOff = 0;
    IdleProt.n_ElevIdleGoal = 0;
    IdleProt.Q_ElevIdle = 0;
  }
  if ( (In.ST_ElevatedIdle || ElevateIdle) && IdleCal.ST_ElevIdleAct )
  {
    if ( In.ST_ElevatedIdle )
      IdleProt.n_ElevIdleGoal = IdleCal.n_EngElevOff;
    else
      IdleProt.n_ElevIdleGoal = 0;
    ElevateIdle = 1;
    if ( *pn_ElevIdleOff >= IdleProt.n_ElevIdleGoal )
    {
      if ( *pn_ElevIdleOff > IdleProt.n_ElevIdleGoal )
        --*pn_ElevIdleOff;
    }
    else
    {
      ++*pn_ElevIdleOff;
    }
    if ( !In.ST_ElevatedIdle && !*pn_ElevIdleOff )
      ElevateIdle = 0;

    IdleProt.Q_ElevIdle = MAP_I16_I16_I16(
            IdleCal.T_EngRPMOffSP,
            IdleCal.n_RPMOffYSP,
            In.T_Engine,
            *pn_ElevIdleOff,
            IdleCal.Q_IdleOffsMAP);
  }
  else
  {
    *pn_ElevIdleOff = 0;
    IdleProt.n_ElevIdleGoal = 0;
    IdleProt.Q_ElevIdle = 0;
  }
}

//at 0126CE
i16 Get_IdleProt_Q_LOff()
{
  Idle.Q_LOffIgnPart = TAB_I16_I16(IdleCal.LOffSP, IgnLOff.fi_Offset, IdleCal.LOffTab);
  /*
  if ( !ECMStat.ST_EngineStarted )
    dword_F0DE72 = 0;
  HIWORD(v5) = 0;
  if ( dword_F0DE72 != 2 && IdleCal.ST_EnableLOffRpm )
  {
    if ( dword_F0DE72 )
    {
      if ( *(_DWORD *)Idle_n_EngLOff )
      {
        LOWORD(v0) = In.v_Vehicle;
        if ( v0 <= (unsigned __int16)IdleCal.v_VehicleLOffRamp || byte_F09A8A )
        {
          LOWORD(v0) = In.v_Vehicle;
          if ( v0 <= (unsigned __int16)IdleCal.v_VehicleLOffRamp )
          {
            if ( ECMStat.msCounter > t_LOffRampDelayEnd )
            {
              n_LOffIdle += IdleCal.n_LOffIdleStep;
              v3 = (unsigned __int16)n_LOffIdle / 10;
              if ( v3 )
              {
                if ( v3 >= Idle_n_EngLOff[0] )
                  Idle_n_EngLOff[0] = 0;
                else
                  Idle_n_EngLOff[0] -= v3;
                if ( v3 >= Idle_n_EngLOff[1] )
                  Idle_n_EngLOff[1] = 0;
                else
                  Idle_n_EngLOff[1] -= v3;
                n_LOffIdle = 10;
              }
              t_LOffRampDelayEnd = ECMStat.msCounter + IdleCal.LOffRampDelay;
            }
          }
          else
          {
            if ( Idle_n_EngLOff[0] )
            {
              if ( (unsigned int)IdleCal.n_LOffSmallStep >= Idle_n_EngLOff[0] )
                Idle_n_EngLOff[0] = 0;
              else
                Idle_n_EngLOff[0] -= IdleCal.n_LOffSmallStep;
            }
            if ( Idle_n_EngLOff[1] )
            {
              if ( Idle_n_EngLOff[1] <= (unsigned int)IdleCal.n_LOffSmallStep )
                Idle_n_EngLOff[1] = 0;
              else
                Idle_n_EngLOff[1] -= IdleCal.n_LOffSmallStep;
            }
          }
        }
        else
        {
          if ( Idle_n_EngLOff[0] )
          {
            if ( (unsigned int)IdleCal.n_LOffStep >= Idle_n_EngLOff[0] )
              Idle_n_EngLOff[0] = 0;
            else
              Idle_n_EngLOff[0] -= IdleCal.n_LOffStep;
          }
          if ( Idle_n_EngLOff[1] )
          {
            if ( Idle_n_EngLOff[1] <= (unsigned int)IdleCal.n_LOffStep )
              Idle_n_EngLOff[1] = 0;
            else
              Idle_n_EngLOff[1] -= IdleCal.n_LOffStep;
          }
          byte_F09A8A = 1;
        }
      }
      else
      {
        dword_F0DE72 = 2;
      }
    }
    else
    {
      Idle_n_EngLOff[1] = TAB_I16_U16(6, IdleCal.T_EngineLOffSP, In.T_Engine, IdleCal.n_EngLOffDrive);
      Idle_n_EngLOff[0] = TAB_I16_U16(6, IdleCal.T_EngineLOffSP, In.T_Engine, IdleCal.n_EngLOffNeutral);
      dword_F0DE72 = 1;
      byte_F09A8A = 0;
      n_LOffIdle = 0;
    }
    if ( IdleProt.ST_DriveActive || DNComp.ST_NeutralControl )
    {
      IdleProt.n_EngLOffOffset = Idle_n_EngLOff[1];
      v1 = TAB_U16_I16(6, IdleCal.n_EngLOffSP, IdleProt.n_EngLOffOffset, IdleCal.Q_LOffRpmDrive);
      IdleProt.Q_LOffRpmOffs = v1;
    }
    else
    {
      IdleProt.n_EngLOffOffset = Idle_n_EngLOff[0];
      v1 = TAB_U16_I16(6, IdleCal.n_EngLOffSP, IdleProt.n_EngLOffOffset, IdleCal.Q_LOffRpmNeutral);
      IdleProt.Q_LOffRpmOffs = v1;
    }
    if ( Fault.p_AirAmbient
      || (LOWORD(v1) = In.p_AirAmbient, v1 >= IgnLOffCal.p_AirAmbHigh)
      || ECMStat.ST_ActiveAirDem != 12
      || IgnLOff.NrCombDelay <= (unsigned int)IdleCal.N_LOffComb )
    {
      v4 = 128;
    }
    else
    {
      v4 = TAB_I16_U16(4, IdleCal.n_RpmDiffLOffSP, IdleProt.n_EngineDiff, IdleCal.X_mLOffHighAltTab);
    }
    IdleProt.X_mLOffFactor = FactorFiltAdjust(v4, IdleProt.X_mLOffFactor, IdleCal.LOffFilterFactor);
    v5 = IdleProt.Q_LOffRpmOffs * IdleProt.X_mLOffFactor / 128;
    IdleProt.Q_LOffRpmOffs = v5;
  }
  else
  {
  */
    IdleProt.Q_LOffRpmOffs = 0;
    IdleProt.n_EngLOffOffset = 0;
  /*
  }
  */
  return IdleProt.Q_LOffRpmOffs + Idle.Q_LOffIgnPart;
}

//at 0124A4
i16 Get_Idle_Q_StartOffs()
{
  i16 Q_StartOffsTemp;

  if ( Idle.StartAirMode == 1 )
  {
    if ( In.n_Engine < 20 )
    {
      IsStarted = 0;
      IdleProt.Q_StartOffsAdd = 0;
    }
    Q_StartOffsTemp = TAB_I16_I16(IdleCal.T_EngineSP, In.T_Engine, IdleCal.Q_StartOffsTab);
    if ( ECMStat.ST_BlkHeatStart )
      Q_StartOffsTemp = BlockHeat.Q_StartOffsFac * Q_StartOffsTemp / 128;
    if ( IsStarted || In.n_Engine > 300 )
    {
      IsStarted = 1;
      if ( IdleProt.Q_StartOffsAdd < 300 )
        IdleProt.Q_StartOffsAdd += IdleCal.Q_StartOffsRamp;
    }
    else
    {
      IdleProt.Q_StartOffsAdd = 0;
    }

    IdleProt.Q_StartOffs =
    		TAB_U16_U16(IdleCal.p_AltStartSP, In.p_AirAmbient, IdleCal.Q_AltStartTAB) +
    		IdleProt.Q_StartOffsAdd + Q_StartOffsTemp;

    if ( IdleCal.n_EngNomExtra + Idle.n_EngineNominal
    		- IdleProt.n_EngLOffOffset - IdleProt.n_ElevIdleOff <= In.n_Engine )
    {
      Idle.StartAirMode = 2;
      t_N_StartAirMode2Start = ECMStat.n_Combustion + IdleCal.N_StartAirMode2;
    }
  }
  else if ( Idle.StartAirMode == 2 )
  {
    if ( IdleProt.Q_StartOffs
      && (IdleCal.n_EngNomExtra + Idle.n_EngineNominal <= In.n_Engine
       || ECMStat.n_Combustion <= t_N_StartAirMode2Start
       || IdleProt.Q_StartOffs >= IdleCal.I_PartMax) )
    {
      IdleProt.Q_StartOffs =
    		  IdleProt.Q_StartOffs *
    		  MAP_I16_I16_U16(
    				  IdleCal.n_EngDiffSP,
    				  IdleCal.t_yaxis,
    				  In.n_Engine - Idle.n_EngineNominal,
    				  In.T_Engine,
    				  IdleCal.StartRedFacMat) / 1000;
    }
    else
    {
      IdleProt.I_Part += IdleProt.Q_StartOffs;
      IdleProt.Q_StartOffs = 0;
      Idle.StartAirMode = 0;
    }
  }

  return IdleProt.Q_StartOffs;
}

//at 012662
void Idle_Proc(void)
{
  DNComp.Q_AirExtra = IdleAdap.Q_AirNeutral + DNComp.C_Part[1];
  In.ST_ElevatedIdle = 0;
  IdleProt.I_Part = 0;
  IdleProt.X_mLOffFactor = -128;
  Idle.Q_FirstDrvComp = IdleCal.Q_FirstDrvComp;
  Idle.Q_Air = Get_Idle_Q_StartOffs();
  Idle.Q_Air += Get_IdleProt_Q_LOff();
  Calc_Idle_Q_ElevIdle();
  Idle.Q_Air += IdleProt.Q_ElevIdle;
  Idle.Q_Air += Get_Idle_Parts_Summ();
  Idle.ST_IdleRpmInAreaMap = 1;
  Calc_m_Idle();
}
