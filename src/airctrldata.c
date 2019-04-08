#include <functions/conversion.h>
#include <functions/interpolation.h>
#include <symbols/airctldata.h>
#include <symbols/airctrlcal.h>
#include <symbols/airctrlprot.h>
#include <symbols/areaadap.h>
#include <symbols/ecmstat.h>
#include <symbols/idle.h>
#include <symbols/in.h>
#include <symbols/maf.h>
#include <symbols/mafcal.h>
#include <symbols/out.h>
#include <symbols/switch.h>
#include <symbols/temptical.h>
#include <symbols/temptiidlecal.h>
#include <symbols/ticalcucal.h>
#include <symbols/ticalcuprot.h>
#include <symbols/threrr.h>

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
