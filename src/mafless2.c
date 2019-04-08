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
#include <symbols/vars.h>

extern i32 FactorFiltAdjust(i32, i32, i32);

extern u32 MAFCalcCount;
extern i32 t_TDC_TDC_Buffer[];
extern u8 FaultBitArray[];

__attribute__((section(".S4A53C")))
void Calc_In_Q_AirInlet(void) {
	i8 fault = 0;
	Fault_T* pFault;
	MAF_T* pMAF;
	MAFCal_T* pMAFCal;
	MAFProt_T* pMAFProt;
	In_T* pIn;
	register u16 i10000 = 10000;

	pFault = &Fault;
	pIn = &In;
	pMAF = &MAF;
	pMAFCal = &MAFCal;
	pMAFProt = &MAFProt;

	if ((pFault->p_AirInlet & 0xF0) || (pFault->T_Engine & 0xF0)
			|| (pFault->T_AirInlet & 0xF0) || (pFault->n_Engine & 0xF0))
		fault |= 1;

	if ((pIn->T_Engine < pMAFCal->T_EngineSP[0])
			|| (pIn->T_AirInlet < pMAFCal->T_AirInlSP[0])
			|| (pIn->n_Engine < pMAFCal->n_EngXSP[0]))
		fault |= 2;

	if ((pIn->T_Engine > pMAFCal->T_EngineSP[ARRMAXIDX(MAFCal.T_EngineSP)])
			|| (pIn->T_AirInlet
					> pMAFCal->T_AirInlSP[ARRMAXIDX(MAFCal.T_AirInlSP)])
			|| (pIn->n_Engine > pMAFCal->n_EngXSP[ARRMAXIDX(MAFCal.n_EngXSP)]))
		fault |= 4;

	pMAFProt->LoadPointer = pIn->p_AirInlet * pMAFProt->ConstT_Engine
			* pMAFProt->ConstT_AirInlet / i10000;

	if (pMAFProt->LoadPointer < pMAFCal->LoadYSP[0])
		fault |= 2;

	if (pMAFProt->LoadPointer > pMAFCal->LoadYSP[ARRMAXIDX(MAFCal.LoadYSP)])
		fault |= 4;

	pMAF->m_AirFromp_AirInlet = MAP_U16_U16_U16(pMAFCal->n_EngXSP,
			pMAFCal->LoadYSP, pIn->n_Engine, pMAFProt->LoadPointer,
			pMAFCal->m_RedundantAirMap);

	pMAF->Q_AirFromp_AirInlet = Convert_m_to_Q(pMAF->m_AirFromp_AirInlet);
	ActualIn.Q_AirInlet = pMAF->Q_AirFromp_AirInlet;

	pFault->Q_AirInlet &= 0xF0u;
	pFault->Q_AirInlet |= fault;
	if (FaultBitArray[0] & 2)
		pIn->Q_AirInlet = LimpIn.Q_AirInlet;
	else
		pIn->Q_AirInlet = ActualIn.Q_AirInlet;
}

__attribute__((section(".S14B76")))
void Calc_MAF_Values(void) {
	i32 v18;
	In_T* pIn;
	MAF_T* pMAF;
	MAFCal_T* pMAFCal;
	MAFProt_T* pMAFProt;
	u16 m_AirFromp_AirInlet;

	pIn = &In;
	pMAF = &MAF;
	pMAFCal = &MAFCal;
	pMAFProt = &MAFProt;

	Calc_In_Q_AirInlet();
	if (ECMStat.ST_EngineStarted && MAFCalcCount > 10) {
		if (pIn->t_TDC_TDC <= t_TDC_TDC_Buffer[0]) {
			if (pIn->t_TDC_TDC >= t_TDC_TDC_Buffer[0])
				pMAFProt->X_DecreaseStep = 0;
			else
				++pMAFProt->X_DecreaseStep;
			pMAFProt->X_IncreaseStep = 0;
		} else {
			++pMAFProt->X_IncreaseStep;
			pMAFProt->X_DecreaseStep = 0;
		}
		if (pMAFProt->X_DecreaseStep < pMAFCal->X_DecrStepLim
				&& pMAFProt->X_IncreaseStep < pMAFCal->X_IncrStepLim) {
			if (pMAFProt->ST_Transient) {
				pMAFProt->t_TDC_TDC_Filt = pIn->t_TDC_TDC;
				pMAFProt->ST_Transient = 0;
			} else {
				pMAFProt->t_TDC_TDC_Filt = (((t_TDC_TDC_Buffer[2]
						+ t_TDC_TDC_Buffer[1]) >> 1)
						+ ((t_TDC_TDC_Buffer[0] + pIn->t_TDC_TDC) >> 1)) >> 1;
			}
			t_TDC_TDC_Buffer[2] = t_TDC_TDC_Buffer[1];
			t_TDC_TDC_Buffer[1] = t_TDC_TDC_Buffer[0];
			t_TDC_TDC_Buffer[0] = pIn->t_TDC_TDC;
		} else {
			v18 = 2 * pIn->t_TDC_TDC - t_TDC_TDC_Buffer[0];
			if (v18 < 0)
				v18 = pIn->t_TDC_TDC;
			pMAFProt->t_TDC_TDC_Filt = FactorFiltAdjust(v18,
					pMAFProt->t_TDC_TDC_Filt, pMAFCal->X_RpmFiltConst);
			pMAFProt->ST_Transient = 1;
			t_TDC_TDC_Buffer[2] = t_TDC_TDC_Buffer[1];
			t_TDC_TDC_Buffer[1] = t_TDC_TDC_Buffer[0];
			t_TDC_TDC_Buffer[0] = pIn->t_TDC_TDC;
		}
	} else {
		pMAFProt->t_TDC_TDC_Filt = pIn->t_TDC_TDC;
		t_TDC_TDC_Buffer[2] = t_TDC_TDC_Buffer[1];
		t_TDC_TDC_Buffer[1] = t_TDC_TDC_Buffer[0];
		t_TDC_TDC_Buffer[0] = pIn->t_TDC_TDC;
	}

	if (++MAFCalcCount > 11)
		MAFCalcCount = 11;

	if (In.n_Engine == 0)
		MAFCalcCount = 0;

	pMAF->Q_AirInletFilt = pMAF->Q_AirFromp_AirInlet;
	m_AirFromp_AirInlet = pMAF->m_AirFromp_AirInlet;
	pMAF->m_AirInlet = m_AirFromp_AirInlet;
	pMAF->m_AirInletFuel = m_AirFromp_AirInlet;
	pMAF->m_AirInletIgn = m_AirFromp_AirInlet;
	pMAF->m_AirInletBoost = m_AirFromp_AirInlet;
	pMAF->m_AirInletTorq = m_AirFromp_AirInlet;
	pMAF->m_AirInletAir = m_AirFromp_AirInlet;

	if ((FaultBitArray[0] & 2) == 0) {
		LimpIn.Q_AirInlet = ActualIn.Q_AirInlet;
	}
}
