#include <functions/conversion.h>
#include <functions/interpolation.h>
#include <symbols/aircomp.h>
#include <symbols/airctldata.h>
#include <symbols/airctrlcal.h>
#include <symbols/airctrlprot.h>
#include <symbols/areaadap.h>
#include <symbols/areacal.h>
#include <symbols/areadata.h>
#include <symbols/boost.h>
#include <symbols/ecmstat.h>
#include <symbols/idle.h>
#include <symbols/in.h>
#include <symbols/maf.h>
#include <symbols/mafcal.h>
#include <symbols/out.h>
#include <symbols/purge.h>
#include <symbols/rampcal.h>
#include <symbols/rampprot.h>
#include <symbols/switch.h>
#include <symbols/templimposcal.h>
#include <symbols/temptical.h>
#include <symbols/temptiidlecal.h>
#include <symbols/ticalcucal.h>
#include <symbols/ticalcuprot.h>
#include <symbols/threrr.h>
#include <symbols/vars.h>

extern u32 n_Combustion_ReqFilt;
extern u16 m_RequestTrans;
extern i32 FactorFiltAdjust(i32, i32, i32);

__attribute__((section(".S0CF06")))
void Calc_AirctlData_Actual(void)
{
  u8 t_mReqDelay;
  u8 idx;
  u16 *pReqBuff0;
  u16 *pReqBuff1;

  if ( m_RequestTrans <= 2000u )
    AirctlData.Request = m_RequestTrans;
  else
    AirctlData.Request = 2000;
  idx = 0;
  pReqBuff1 = &AirCtrlProt.m_ReqBuff[1];
  pReqBuff0 = &AirCtrlProt.m_ReqBuff[0];
  t_mReqDelay = AirCtrlCal.t_mReqDelay;
  while ( idx < t_mReqDelay )
  {
    *pReqBuff0++ = *pReqBuff1++;
    ++idx;
  }
  AirCtrlProt.m_ReqBuff[AirCtrlCal.t_mReqDelay] = AirctlData.Request;

  if ( ECMStat.n_Combustion < n_Combustion_ReqFilt )
  {
    n_Combustion_ReqFilt = 0;
    AirCtrlProt.m_ReqFilt = AirCtrlProt.m_ReqBuff[0];
  }

if ( ECMStat.n_Combustion > n_Combustion_ReqFilt || ECMStat.n_Combustion == 0 )
  {
    AirCtrlProt.m_ReqFilt = FactorFiltAdjust(AirCtrlProt.m_ReqBuff[0], AirCtrlProt.m_ReqFilt, MAFCal.FilterConstAir);
    n_Combustion_ReqFilt = ECMStat.n_Combustion;
  }
  if ( MAF.m_AirInletAir <= 2000u )
    AirctlData.Actual = MAF.m_AirInletAir;
  else
    AirctlData.Actual = 2000;
}

extern u8 byte_F0DC3E;
extern u32 t_TiCalcu_InletUpdate;

__attribute__((section(".S0CFE8")))
void Calc_AirctlData_Ti(void)
{
  i16 *pDeltaN1;

  pDeltaN1 = &AirctlData.DeltaN1;
  AirctlData.iPartN0 = AirctlData.iPartN1;
  if ( byte_F0DC3E >= 2u )
  {
    AirctlData.DeltaN0 = *pDeltaN1;
    *pDeltaN1 = AirCtrlProt.m_ReqFilt - AirctlData.Actual;
  }
  else
  {
    AirctlData.DeltaN0 = 0;
    *pDeltaN1 = 0;
    AirctlData.iPartRest = 0;
  }
  if ( ECMStat.msCounter >= t_TiCalcu_InletUpdate )
  {
    TiCalcuProt.p_DeltaIn50ms = In.p_AirInlet - TiCalcuProt.p_InletOld;
    t_TiCalcu_InletUpdate = ECMStat.msCounter + TiCalcuCal.ms_InletUpdate;
    TiCalcuProt.p_InletOld = In.p_AirInlet;
  }

  if ( ((ECMStat.p_DiffThrot >= TiCalcuCal.p_DiffMin || Switch.ST_LimActive || ThrErr.ST_PwmLimOrdered) && *pDeltaN1 > 0)
    || (Out.A_Throttle + AreaAdap.A_Throttle <= 10 && *pDeltaN1 < 0) )
  {
    AirctlData.Ti = TiCalcuCal.TiNoPressure;
    AirctlData.FreezeIPart = 1;
    return;
  }

if ( TiCalcuCal.p_DiffMin - TiCalcuCal.p_DiffHysteresis > ECMStat.p_DiffThrot || *pDeltaN1 < 0 )
  {
    AirctlData.FreezeIPart = 0;
    if ( Idle.ST_Enable )
    {
      AirctlData.Ti = TempTiIdleCal.Idle;
      return;
    }
    AirctlData.Ti = MAP_I16_I16_I16(TempTiCal.x_axis, TempTiCal.y_axis, TiCalcuProt.p_DeltaIn50ms, *pDeltaN1, TempTiCal.map);
  }
}

// Calc_AirctlData_iPartN1 at 0x00D12C

__attribute__((section(".S0D1F2")))
void Calc_AirctlData_MaxAirmass(void)
{
  AirctlData.MaxAirmass = TAB_U16_U16(AirCtrlCal.y_axis, ECMStat.n_Engine10ms, AirCtrlCal.m_MaxAirTab);
}

extern u8 ST_PedalReleased_old;
extern u32 t_PedReceRel_Start;
extern u8 byte_F0DBFA;
extern u8 byte_F0DC40;
__attribute__((section(".S0D222")))
void Calc_AreaData_A_Controller(void)
{
  i16 m_Venturi;
  u16 Q_Venturi;
  int AirctlRequest;
  int A_Controller;
  i16 *piPartN1;

  if ( (ECMStat.ST_PedalReleased || ST_PedalReleased_old)
    && (!ECMStat.ST_PedalReleased || !ST_PedalReleased_old || byte_F0DBFA) )
  {
    if ( !ECMStat.ST_PedalReleased || ST_PedalReleased_old )
    {
      if ( !ECMStat.ST_PedalReleased
        || !ST_PedalReleased_old
        || AirCtrlCal.t_PedReceRel + t_PedReceRel_Start < ECMStat.msCounter )
      {
        if ( ECMStat.ST_PedalReleased
          && ST_PedalReleased_old
          && AirCtrlCal.t_PedReceRel + t_PedReceRel_Start < ECMStat.msCounter )
        {
          byte_F0DBFA = 0;
        }
        else if ( !ECMStat.ST_PedalReleased && ST_PedalReleased_old )
        {
          byte_F0DBFA = 0;
        }
      }
    }
    else
    {
      byte_F0DBFA = 1;
      t_PedReceRel_Start = ECMStat.msCounter;
    }
    if ( byte_F0DBFA && TiCalcuProt.p_DeltaIn50ms < AirCtrlCal.p_DeltaInlet )
    {
      AirctlData.iPartN1 = 0;
      byte_F0DBFA = 0;
    }
  }
  else
  {
    byte_F0DBFA = 0;
  }
  ST_PedalReleased_old = ECMStat.ST_PedalReleased;
  RAM_limit_pos = TAB_U16_U16(TempLimPosCal.Airmass, AirctlData.Request, TempLimPosCal.Limit);
  if ( AirctlData.iPartN1 > RAM_limit_pos )
  {
    AirctlData.iPartN1 = RAM_limit_pos;
    AirctlData.iPartRest = 0;
  }
  RAM_limit_neg = -RAM_limit_pos;

  piPartN1 = &AirctlData.iPartN1;
  if ( AirctlData.iPartN1 < -RAM_limit_pos )
  {
    *piPartN1 = RAM_limit_neg;
    AirctlData.iPartRest = 0;
  }
  if ( RampProt.StatusOld != 2 || byte_F0DC3E >= 2u )
  {
    if ( byte_F0DC3E == 2 )
      RampProt.Difference = 0;
  }
  else
  {
    RampProt.Difference = *piPartN1 << 7;
  }
  if ( RampProt.Difference )
  {
    if ( !RampCal.Gradient )
      RampProt.Difference = 0;

    if ( RampProt.Difference <= 0 )
    {
      RampProt.Difference += RampCal.Gradient;
      if ( RampProt.Difference > 0 )
        RampProt.Difference = 0;
    }
    else
    {
      if ( RampProt.Difference <= RampCal.Gradient )
      {
        RampProt.Difference = 0;
      }
      else
      {
        RampProt.Difference -= RampCal.Gradient;
      }
    }
    AirctlData.iPartN1 = RampProt.Difference / 128;
  }
  RampProt.StatusOld = byte_F0DC3E;

  AirctlData.m_CtrlOutput = MIN(MAX(*piPartN1,RAM_limit_neg), RAM_limit_pos);

  m_Venturi = Boost.AreaComp * ((AirComp.Comp * (AirctlData.m_CtrlOutput + AirctlData.Request) + 500) / 1000);
  AirctlRequest = m_Venturi / 1024;
  RAM_AirctlRequest = m_Venturi / 1024;
  if ( AreaCal.Enable_Venturi && !ECMStat.ST_Automatic )
  {
    Q_Venturi = TAB_I16_I16(AreaCal.Q_VenturiSP, ECMStat.p_DiffThrot, AreaCal.Q_VenturiTab);
    m_Venturi = Convert_Q_to_m(Q_Venturi);
    AreaData.m_Venturi = m_Venturi;
    AreaData.Q_Venturi = Q_Venturi;
    AirctlRequest -= m_Venturi;
  }

  AirctlData.ControllerOut = MAX(MIN(AirctlRequest - Purge.m_AirPrg,AirctlData.MaxAirmass), 0);
  if ( Idle.ST_IdleRpmInAreaMap == 1 )
    A_Controller = MAP_U16_U16_U16(
           AirCtrlCal.x_axis,
           AirCtrlCal.y_axis,
           AirctlData.ControllerOut,
           Idle.n_EngineNominal,
           AirCtrlCal.map);
  else
    A_Controller = MAP_U16_U16_U16(
           AirCtrlCal.x_axis,
           AirCtrlCal.y_axis,
           AirctlData.ControllerOut,
           ECMStat.n_Engine10ms,
           AirCtrlCal.map);
  AreaData.A_Controller = A_Controller;
  byte_F0DC40 = 0;
}
