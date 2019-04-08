#include <functions/interpolation.h>
#include <symbols/aircomp.h>
#include <symbols/aircompcal.h>
#include <symbols/aircompprot.h>
#include <symbols/airctrlcal.h>
#include <symbols/boost.h>
#include <symbols/fault.h>
#include <symbols/in.h>
#include <symbols/vars.h>

extern u16 m_RequestTrans;

__attribute__((section(".S0CCBC")))
void Calc_AirComp_Comp(void)
{
  u16 *pPresComp;

  pPresComp = &AirComp.PresComp;
  if ( Fault.T_AirInlet & 0xF0 )
    AirComp.TempComp = 1000;
  else
    AirComp.TempComp = TAB_I16_U16(AirCompCal.T_AirSP, In.T_AirInlet, AirCompCal.AirTab);
  if ( Fault.p_AirBefThrottle & 0xF0 )
  {
    *pPresComp = 1000;
  }
  else
  {
    AirCompProt.m_LoadPoint = m_RequestTrans * AirComp.TempComp / 1000;
    AirComp.P1 = MAP_U16_U16_U16(
                   AirCtrlCal.x_axis,
                   AirCtrlCal.y_axis,
                   AirCompProt.m_LoadPoint,
                   In.n_Engine,
                   AirCompCal.PressMap);
    if ( In.p_AirBefThrottle )
      AirComp.RatioP1P2 = 1000 * AirComp.P1 / In.p_AirBefThrottle;
    RAM_localprescomp = TAB_I16_U16(AirCompCal.p_PresSP, AirComp.RatioP1P2, AirCompCal.PresTab);
    if ( Boost.AirMasterStatus == 1 )
    {
      if ( !RAM_prescompflag )
      {
        if ( *pPresComp >= 990u )
          RAM_prescompflag = 1;
        else
          *pPresComp += 10;
      }
      if ( RAM_localprescomp <= 1000u )
      {
        if ( RAM_prescompflag == 1 )
          *pPresComp = 1000;
      }
      else
      {
        *pPresComp = RAM_localprescomp;
        RAM_prescompflag = 1;
      }
    }
    else
    {
      *pPresComp = RAM_localprescomp;
      RAM_prescompflag = 0;
    }
  }

  AirComp.Comp =  *pPresComp * AirComp.TempComp / 1000;
}

__attribute__((section(".S0CE26")))
void Calc_AirComp_LimComp(void)
{
  u16 *pLimTempComp;
  u16 *pLimPresComp;

  pLimPresComp = &AirComp.LimPresComp;
  pLimTempComp = &AirComp.LimTempComp;

  if ( Fault.T_AirInlet & 0xF0 )
  {
    *pLimTempComp = 1000;
  }
  else
  {
    *pLimTempComp = TAB_I16_U16(AirCompCal.T_AirLimSP, In.T_AirInlet, AirCompCal.AirLimTab);
  }
  if ( Fault.p_AirAmbient & 0xF0 )
  {
    *pLimPresComp = 1000;
  }
  else
  {
    *pLimPresComp = 1000 * In.p_AirAmbient / 1013;
  }

  AirComp.LimComp = *pLimPresComp * *pLimTempComp / 1000;
}
