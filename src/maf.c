#include <functions/conversion.h>
#include <functions/interpolation.h>
#include <symbols/actualin.h>
#include <symbols/ecmstat.h>
#include <symbols/fault.h>
#include <symbols/in.h>
#include <symbols/limpin.h>
#include <symbols/maf.h>
#include <symbols/mafcal.h>
#include <symbols/mafprot.h>
#include <symbols/qairdiagcal.h>
#include <symbols/vars.h>
#include <user/hfmcal.h>
#include <user/tpu.h>

void Calc_MAF_Consts(void)
{
  MAFProt.ConstT_Engine = TAB_I16_U8(MAFCal.T_EngineSP, In.T_Engine, MAFCal.ConstT_EngineTab);
  MAFProt.ConstT_AirInlet = TAB_I16_U8(MAFCal.T_AirInlSP, In.T_AirInlet, MAFCal.ConstT_AirInlTab);
}

extern i16 Ch_F_P3_Old, Ch_F_P5_Old;
extern u32 HFMCalcCount;
extern u32 t_MAF_Fault_Start;
extern u8 FaultBitArray[];
extern u16 m_AirInlet_Old;
void Calc_In_Q_AirInlet(void)
{
  int p5Diff;
  unsigned int p3Diff;
  i16 Ch_F_P5;
  u8 fault;
  i16 Ch_F_P3;
  u16 maf_period;
  i16 Q_AirInlet;

  if ( QAirDiagCal.EnableHFMOffset )
    RAM_hfmOffsetSimFac = TAB_I16_U16(QAirDiagCal.HFMOffSimSP, RAM_tmpqair, QAirDiagCal.HFMOffSim);

  Ch_F_P5 = pTpuParams->ch15.p5;
  Ch_F_P3 = pTpuParams->ch15.p3;
  if ( pTpuParams->ch15.p3 != Ch_F_P3 )
    Ch_F_P5 = pTpuParams->ch15.p5;

  fault = 0;
  if ( Ch_F_P3 == Ch_F_P3_Old || Ch_F_P5 == Ch_F_P5_Old || In.n_Engine <= 0 )
  {
    if ( In.n_Engine <= 0 )
    {
      p3Diff = (Ch_F_P3 - Ch_F_P3_Old);
      p5Diff = (Ch_F_P5 - Ch_F_P5_Old);
      Ch_F_P3_Old = pTpuParams->ch15.p3;
      Ch_F_P5_Old = Ch_F_P5;
      if ( p3Diff )
      {
    	  maf_period = 100 * p5Diff / p3Diff;
        if ( QAirDiagCal.EnableHFMOffset )
        {
          RAM_tmpqair = TAB_U16_U16(HFMCal.t_SP, maf_period, HFMCal.Q_Tab);
          Q_AirInlet = RAM_tmpqair * RAM_hfmOffsetSimFac / 1028;
        }
        else
        {
          Q_AirInlet = TAB_U16_U16(HFMCal.t_SP, maf_period, HFMCal.Q_Tab);
        }
        ActualIn.Q_AirInlet = Q_AirInlet;
      }
      else
      {
        ActualIn.Q_AirInlet = 0;
      }
      HFMCalcCount = 0;
    }
    else
    {
      fault = 1;
      ActualIn.Q_AirInlet = 0;
      t_MAF_Fault_Start = ECMStat.msCounter;
      ++HFMCalcCount;
    }
  }
  else
  {
    p3Diff = (Ch_F_P3 - Ch_F_P3_Old);
    p5Diff = (Ch_F_P5 - Ch_F_P5_Old);
    Ch_F_P3_Old = pTpuParams->ch15.p3;
    Ch_F_P5_Old = Ch_F_P5;
    maf_period = 100 * p5Diff / p3Diff;
    if ( maf_period )
    {
      RAM_maf_frequency = 13107800 / maf_period;
    }
    if ( HFMCalcCount > 2 )
    {
      if ( maf_period <= 26215 )
      {
        if ( maf_period < 873 )
        {
          fault = 4;
          t_MAF_Fault_Start = ECMStat.msCounter;
        }
      }
      else
      {
        fault = 2;
        t_MAF_Fault_Start = ECMStat.msCounter;
      }
    }

    if ( HFMCalcCount <= 2 )
    {
      if ( QAirDiagCal.EnableHFMOffset )
      {
        RAM_tmpqair = HFMCal.Q_Tab[17];
        Q_AirInlet = RAM_tmpqair * RAM_hfmOffsetSimFac / 0x404;
        ActualIn.Q_AirInlet = Q_AirInlet;
      }
      else
      {
        ActualIn.Q_AirInlet = HFMCal.Q_Tab[17];
      }
    }
    else
    {
      if ( QAirDiagCal.EnableHFMOffset )
      {
        RAM_tmpqair = TAB_U16_U16(HFMCal.t_SP, maf_period, HFMCal.Q_Tab);
        Q_AirInlet = RAM_tmpqair * RAM_hfmOffsetSimFac / 0x404;
      }
      else
      {
        Q_AirInlet = TAB_U16_U16(HFMCal.t_SP, maf_period, HFMCal.Q_Tab);
      }
      ActualIn.Q_AirInlet = Q_AirInlet;
    }
    ++HFMCalcCount;
  }

  if ( In.n_Engine != 0 )
  {
    if ( ECMStat.msCounter > 100000 )
    {
      if ( t_MAF_Fault_Start + 10000 > ECMStat.msCounter )
        fault |= 8u;
    }
  }
  else
  {
    t_MAF_Fault_Start = 0;
  }
  Fault.Q_AirInlet &= 0xF0u;
  Fault.Q_AirInlet |= fault;
  if ( FaultBitArray[0] & 2 )
    In.Q_AirInlet = LimpIn.Q_AirInlet;
  else
    In.Q_AirInlet = ActualIn.Q_AirInlet;
}

extern u32 MAFCalcCount;
extern i32 t_TDC_TDC_Buffer[];
extern u8 ST_IgnSteady;
extern i16 m_AirDevTrans;
extern i16 m_AirDevSteady;
extern i16 p_AirInlet_Old;
extern u32 t_PosTransFreezStart;
extern u32 t_NegTransFreezStart;
extern u32 t_FreezePosTransStart;
extern u32 t_FreezeNegTransStart;
extern u16 MAF_to_MAP_Blend;
void Calc_MAF_Values(void)
{
  u16 m_AirInletBoost;
  u16 m_AirInletTorq;
  u16 m_AirInletAir;
  u16 m_AirInletIgn;
  u16 m_AirInletFuel;
  u16 m_AirInlet; // [esp+CCh] [ebp-2Ch]
  i32 v18;
  u16 v19;
  i16 m_Air;
  u16 Q_AirInletFilt;
  i32 v32; // [esp+D8h] [ebp-20h]

  Calc_In_Q_AirInlet();
  if ( ECMStat.ST_EngineStarted && MAFCalcCount > 10 )
  {
    if ( In.t_TDC_TDC <= t_TDC_TDC_Buffer[0] )
    {
      if ( In.t_TDC_TDC >= t_TDC_TDC_Buffer[0] )
        MAFProt.X_DecreaseStep = 0;
      else
        ++MAFProt.X_DecreaseStep;
      MAFProt.X_IncreaseStep = 0;
    }
    else
    {
      ++MAFProt.X_IncreaseStep;
      MAFProt.X_DecreaseStep = 0;
    }
    if ( MAFProt.X_DecreaseStep < MAFCal.X_DecrStepLim && MAFProt.X_IncreaseStep < MAFCal.X_IncrStepLim )
    {
      if ( MAFProt.ST_Transient )
      {
        MAFProt.t_TDC_TDC_Filt = In.t_TDC_TDC;
        MAFProt.ST_Transient = 0;
      }
      else
      {
        MAFProt.t_TDC_TDC_Filt = (((t_TDC_TDC_Buffer[2] + t_TDC_TDC_Buffer[1]) >> 1)
                                + ((t_TDC_TDC_Buffer[0] + In.t_TDC_TDC) >> 1)) >> 1;
      }
      t_TDC_TDC_Buffer[2] = t_TDC_TDC_Buffer[1];
      t_TDC_TDC_Buffer[1] = t_TDC_TDC_Buffer[0];
      t_TDC_TDC_Buffer[0] = In.t_TDC_TDC;
    }
    else
    {
      v18 = 2 * In.t_TDC_TDC - t_TDC_TDC_Buffer[0];
      if ( v18 < 0 )
        v18 = In.t_TDC_TDC;
      MAFProt.t_TDC_TDC_Filt = FactorFiltAdjust(v18, MAFProt.t_TDC_TDC_Filt, MAFCal.X_RpmFiltConst);
      MAFProt.ST_Transient = 1;
      t_TDC_TDC_Buffer[2] = t_TDC_TDC_Buffer[1];
      t_TDC_TDC_Buffer[1] = t_TDC_TDC_Buffer[0];
      t_TDC_TDC_Buffer[0] = In.t_TDC_TDC;
    }
  }
  else
  {
    MAFProt.t_TDC_TDC_Filt = In.t_TDC_TDC;
    t_TDC_TDC_Buffer[2] = t_TDC_TDC_Buffer[1];
    t_TDC_TDC_Buffer[1] = t_TDC_TDC_Buffer[0];
    t_TDC_TDC_Buffer[0] = In.t_TDC_TDC;
  }
  MAFProt.LoadPointer = In.p_AirInlet * MAFProt.ConstT_Engine * MAFProt.ConstT_AirInlet / 10000;
  MAF.m_AirFromp_AirInlet = MAP_U16_U16_U16(
                              MAFCal.n_EngXSP,
                              MAFCal.LoadYSP,
                              In.n_Engine,
                              MAFProt.LoadPointer,
                              MAFCal.m_RedundantAirMap);
  MAF.Q_AirFromp_AirInlet = Convert_m_to_Q(MAF.m_AirFromp_AirInlet);
  m_AirInlet = Convert_Q_to_m(ActualIn.Q_AirInlet);
  if ( ECMStat.ST_EngineStarted )
  {
	m_AirInletBoost = FactorFiltAdjust(m_AirInlet, MAF.m_AirInletBoost, MAFCal.FilterConstBoost);
    m_AirInletAir = FactorFiltAdjust(m_AirInlet, MAF.m_AirInletAir, MAFCal.FilterConstAir);
    if ( Fault.p_AirInlet )
    {
      m_AirInletFuel = FactorFiltAdjust(m_AirInlet, m_AirInlet_Old, MAFCal.FilterCFuelSteady);
      m_AirInlet_Old = m_AirInletFuel;
      if ( ST_IgnSteady )
      {
        m_Air = m_AirDevTrans + m_AirInlet;
        if ( (m_AirDevTrans + m_AirInlet) < 0 )
          m_Air = 0;

        m_AirInletIgn = FactorFiltAdjust(m_Air, MAF.m_AirInletIgn, MAFCal.FilterCIgnSteady);
      }
      else
      {
        m_AirInletIgn = FactorFiltAdjust(m_AirInlet, MAF.m_AirInletIgn, MAFCal.FilterCIgnSteady);
      }
      m_AirInletTorq = m_AirInletAir;
      if ( m_AirDevTrans )
      {
        if ( m_AirDevTrans < 0 )
          m_AirDevTrans += 1;
        m_AirDevTrans /= 2;
      }
    }
    else
    {
      MAFProt.p_DeltaInlet = In.p_AirInlet - p_AirInlet_Old;
      p_AirInlet_Old = In.p_AirInlet;

      if ( MAFCal.p_DeltaFuelTrans >= MAFProt.p_DeltaInlet )
      {
        if ( MAFCal.p_DeltaFuelTrans + MAFProt.p_DeltaInlet >= 0 )
        {
          if ( MAFProt.ST_PosFuelTrans && t_PosTransFreezStart + MAFProt.t_PosTransFreez < ECMStat.msCounter )
            MAFProt.ST_PosFuelTrans = 0;
          if ( MAFProt.ST_NegFuelTrans && t_NegTransFreezStart + MAFProt.t_NegTransFreez < ECMStat.msCounter )
            MAFProt.ST_NegFuelTrans = 0;
        }
        else
        {
          MAFProt.t_NegTransFreez = TAB_I16_U16(MAFCal.n_EngineXSP, In.n_Engine, MAFCal.t_NegTransFreezTab);
          if ( MAFProt.t_NegTransFreez )
            MAFProt.ST_NegFuelTrans = 1;
          else
            MAFProt.ST_NegFuelTrans = 0;
          MAFProt.ST_PosFuelTrans = 0;
          t_NegTransFreezStart = ECMStat.msCounter;
        }
      }
      else
      {
        MAFProt.t_PosTransFreez = TAB_I16_U16(MAFCal.n_EngineXSP, In.n_Engine, MAFCal.t_PosTransFreezTab);
        if ( MAFProt.t_PosTransFreez )
          MAFProt.ST_PosFuelTrans = 1;
        else
          MAFProt.ST_PosFuelTrans = 0;
        MAFProt.ST_NegFuelTrans = 0;
        t_PosTransFreezStart = ECMStat.msCounter;
      }
      if ( MAFCal.p_DeltaTransLim < MAFProt.p_DeltaInlet && MAFCal.t_FreezePosTrans )
      {
        MAFProt.ST_PosTrans = 1;
        MAFProt.ST_NegTrans = 0;
        t_FreezePosTransStart = ECMStat.msCounter;
      }
      else
      {
        if ( MAFCal.p_DeltaTransLim + MAFProt.p_DeltaInlet < 0 && MAFCal.t_FreezeNegTrans )
        {
          MAFProt.ST_NegTrans = 1;
          t_FreezeNegTransStart = ECMStat.msCounter;
          MAFProt.ST_PosTrans = 0;
        }
        else
        {
          if ( MAFProt.ST_PosTrans && t_FreezePosTransStart + MAFCal.t_FreezePosTrans < ECMStat.msCounter )
            MAFProt.ST_PosTrans = 0;
          if ( MAFProt.ST_NegTrans && t_FreezeNegTransStart + MAFCal.t_FreezeNegTrans < ECMStat.msCounter )
            MAFProt.ST_NegTrans = 0;
        }
      }
      if ( MAFProt.ST_NegTrans )
      {
        v19 = m_AirDevSteady + MAF.m_AirFromp_AirInlet;
        if ( (m_AirDevSteady + MAF.m_AirFromp_AirInlet) < 0 )
          v19 = 0;
        m_AirInletIgn = v19;
        m_AirInletTorq = FactorFiltAdjust(m_AirInlet, MAF.m_AirInletTorq, MAFCal.FilterCTorqTrans);
        if ( m_AirDevSteady )
        {
          if ( m_AirDevSteady < 0 )
        	  m_AirDevSteady += 1;
          m_AirDevSteady /= 2;
        }
        m_AirDevTrans = MAF.m_AirFromp_AirInlet - m_AirInletAir;
        ST_IgnSteady = 1;
      }
      else if ( MAFProt.ST_PosTrans )
      {
        m_AirInletIgn = FactorFiltAdjust(m_AirInlet, MAF.m_AirInletIgn, MAFCal.FilterCIgnTrans);
        m_AirInletTorq = FactorFiltAdjust(m_AirInlet, MAF.m_AirInletTorq, MAFCal.FilterCTorqSteady);
        if ( m_AirDevTrans )
        {
          if ( m_AirDevTrans < 0 )
        	  m_AirDevTrans += 1;
          m_AirDevTrans /= 2;
        }
        if ( m_AirDevSteady )
        {
          if ( m_AirDevSteady < 0 )
        	  m_AirDevSteady += 1;
          m_AirDevSteady /= 2;
        }
        ST_IgnSteady = 0;
      }
      else
      {
        if ( ST_IgnSteady )
        {
          m_Air = m_AirDevTrans + m_AirInlet;
          if ( m_Air < 0 )
        	  m_Air = 0;
          m_AirInletIgn = FactorFiltAdjust(m_Air, MAF.m_AirInletIgn, MAFCal.FilterCIgnSteady);
        }
        else
        {
          m_AirInletIgn = FactorFiltAdjust(m_AirInlet, MAF.m_AirInletIgn, MAFCal.FilterCIgnSteady);
        }
        m_AirInletTorq = FactorFiltAdjust(m_AirInlet, MAF.m_AirInletTorq, MAFCal.FilterCTorqSteady);
        if ( m_AirDevTrans )
        {
          if ( m_AirDevTrans < 0 )
        	  m_AirDevTrans += 1;
          m_AirDevTrans /= 2;
        }
        m_AirDevSteady = m_AirInletAir - MAF.m_AirFromp_AirInlet;
      }
      if ( (MAFProt.ST_NegFuelTrans
        && (MAFProt.p_DeltaInlet + MAFCal.p_DeltaTransLim >= 0))
        || (MAFProt.ST_PosFuelTrans && MAFCal.p_DeltaTransLim > MAFProt.p_DeltaInlet ) )
      {
        m_AirInlet_Old = FactorFiltAdjust(m_AirInlet, m_AirInlet_Old, MAFCal.FilterCFuelTrans);
        m_AirInletFuel = FactorFiltAdjust(m_AirInlet_Old, MAF.m_AirFromp_AirInlet, MAFProt.HFMWeightCoef);
      }
      else if ( MAFProt.ST_NegFuelTrans || MAFProt.ST_PosFuelTrans )
      {
        m_AirInlet_Old = FactorFiltAdjust(m_AirInlet, m_AirInlet_Old, MAFCal.FilterCFuelTrans);
        MAFProt.HFMWeightCoef = FactorFiltAdjust(
        		MAP_I16_I16_I16(
        		               MAFCal.n_EngineXSP,
        		               MAFCal.p_InletGradYSP,
        		               In.n_Engine,
        		               MAFProt.p_DeltaInlet,
        		               MAFCal.WeightConstFuelMap),
        		MAFProt.HFMWeightCoef, MAFCal.WeightCoefFConst);
        m_AirInletFuel = FactorFiltAdjust(m_AirInlet_Old, MAF.m_AirFromp_AirInlet, MAFProt.HFMWeightCoef);
      }
      else
      {
        m_AirInlet_Old = FactorFiltAdjust(m_AirInlet, m_AirInlet_Old, MAFCal.FilterCFuelSteady);
        MAFProt.HFMWeightCoef = FactorFiltAdjust(
        		MAP_I16_I16_I16(
					MAFCal.n_EngineXSP,
					MAFCal.p_InletGradYSP,
					In.n_Engine,
					MAFProt.p_DeltaInlet,
					MAFCal.WeightConstFuelMap),
				MAFProt.HFMWeightCoef, MAFCal.WeightCoefFConst);
        m_AirInletFuel = FactorFiltAdjust(m_AirInlet_Old, MAF.m_AirFromp_AirInlet, MAFProt.HFMWeightCoef);
      }
    }
  }
  else
  {
    m_AirInletAir = m_AirInlet;
    m_AirInletBoost = m_AirInlet;
    m_AirInletIgn = m_AirInlet;
    m_AirInletFuel = m_AirInlet;
    m_AirInletTorq = m_AirInlet;
    m_AirInlet_Old = m_AirInlet;
    p_AirInlet_Old = In.p_AirInlet;
  }
  ++MAFCalcCount;

  Q_AirInletFilt = Convert_m_to_Q(m_AirInletAir);
  if ( Fault.Q_AirInlet || Fault.CMD_Bypass )
  {
    m_AirInlet = MAF.m_AirFromp_AirInlet;
    m_AirInletBoost = MAF.m_AirFromp_AirInlet;
    m_AirInletIgn = MAF.m_AirFromp_AirInlet;
    m_AirInletFuel = MAF.m_AirFromp_AirInlet;
    m_AirInletTorq = MAF.m_AirFromp_AirInlet;
    m_AirInletAir = MAF.m_AirFromp_AirInlet;
    Q_AirInletFilt = MAF.Q_AirFromp_AirInlet;
  }
  if ( !In.n_Engine )
    MAFCalcCount = 0;
  MAF.Q_AirInletFilt = Q_AirInletFilt;
  MAF.m_AirInlet = m_AirInlet;
  MAF.m_AirInletFuel = m_AirInletFuel;
  MAF.m_AirInletIgn = m_AirInletIgn;
  MAF.m_AirInletBoost = m_AirInletBoost;
  MAF.m_AirInletTorq = m_AirInletTorq;
  MAF.m_AirInletAir = m_AirInletAir;
  if ( FaultBitArray[0] & 2 )
  {
    MAF_to_MAP_Blend++;
    if ( MAF_to_MAP_Blend++ >= 0x100u )
    {
      LimpIn.Q_AirInlet = MAF.Q_AirFromp_AirInlet;
    }
    else
    {
      v32 = (256 - MAF_to_MAP_Blend) * ActualIn.Q_AirInlet + MAF_to_MAP_Blend * MAF.Q_AirFromp_AirInlet;
      if ( v32 < 0 )
        v32 += 255;
      LimpIn.Q_AirInlet = v32 >> 8;
    }
  }
  else
  {
    LimpIn.Q_AirInlet = ActualIn.Q_AirInlet;
    MAF_to_MAP_Blend = 0;
  }
}
