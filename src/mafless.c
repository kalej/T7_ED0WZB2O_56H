#include <misc.h>
#include <functions/conversion.h>
#include <functions/interpolation.h>
#include <symbols/actualin.h>
#include <symbols/fault.h>
#include <symbols/in.h>
#include <symbols/limpin.h>
#include <symbols/maf.h>
#include <symbols/mafcal.h>
#include <symbols/mafprot.h>

__attribute__((section(".S1574E")))
void Calc_MAF_Consts(void)
{
  MAFProt.ConstT_Engine = TAB_I16_U8(MAFCal.T_EngineSP, In.T_Engine, MAFCal.ConstT_EngineTab);
  MAFProt.ConstT_AirInlet = TAB_I16_U8(MAFCal.T_AirInlSP, In.T_AirInlet, MAFCal.ConstT_AirInlTab);
}

__attribute__((section(".S4A53C")))
void Calc_In_Q_AirInlet(void) {
	i8 fault = 0;
	MAF_T* pMAF;
	MAFCal_T* pMAFCal;
	MAFProt_T* pMAFProt;
	In_T* pIn;
	register u16 i10000 = 10000;

	pIn = &In;
	pMAF = &MAF;
	pMAFCal = &MAFCal;
	pMAFProt = &MAFProt;

	if ( (Fault.p_AirInlet & 0xF0) || (Fault.T_Engine & 0xF0) )
		fault |= 1;

	if ( (pIn->T_Engine < pMAFCal->T_EngineSP[0] ) || (pIn->T_AirInlet < pMAFCal->T_AirInlSP[0]) ||
			(pIn->n_Engine < pMAFCal->n_EngXSP[0]) )
		fault |= 2;

	if ( (pIn->T_Engine > pMAFCal->T_EngineSP[ARRMAXIDX(MAFCal.T_EngineSP)] ) ||
			(pIn->T_AirInlet > pMAFCal->T_AirInlSP[ARRMAXIDX(MAFCal.T_AirInlSP)]) ||
				(pIn->n_Engine > pMAFCal->n_EngXSP[ARRMAXIDX(MAFCal.n_EngXSP)]) )
		fault |= 4;

	pMAFProt->LoadPointer = pIn->p_AirInlet * pMAFProt->ConstT_Engine
				* pMAFProt->ConstT_AirInlet / i10000;

	if ( pMAFProt->LoadPointer < pMAFCal->LoadYSP[0] )
		fault |= 2;

	if ( pMAFProt->LoadPointer > pMAFCal->LoadYSP[ARRMAXIDX(MAFCal.LoadYSP)] )
		fault |= 4;

	pMAF->m_AirFromp_AirInlet = MAP_U16_U16_U16(pMAFCal->n_EngXSP, pMAFCal->LoadYSP,
			pIn->n_Engine, pMAFProt->LoadPointer, pMAFCal->m_RedundantAirMap);

	pMAF->Q_AirFromp_AirInlet = Convert_m_to_Q(pMAF->m_AirFromp_AirInlet);
	ActualIn.Q_AirInlet = pMAF->Q_AirFromp_AirInlet;

	Fault.Q_AirInlet &= 0xF0u;
	Fault.Q_AirInlet |= fault;

	pIn->Q_AirInlet = pMAF->Q_AirFromp_AirInlet;
}

__attribute__((section(".S14B76")))
void Calc_MAF_Values(void) {
	MAF_T* pMAF;

	Calc_In_Q_AirInlet();

	pMAF = &MAF;

	pMAF->Q_AirInletFilt = pMAF->Q_AirFromp_AirInlet;
	pMAF->m_AirInlet = pMAF->m_AirFromp_AirInlet;
	pMAF->m_AirInletFuel = pMAF->m_AirFromp_AirInlet;
	pMAF->m_AirInletIgn = pMAF->m_AirFromp_AirInlet;
	pMAF->m_AirInletBoost = pMAF->m_AirFromp_AirInlet;
	pMAF->m_AirInletTorq = pMAF->m_AirFromp_AirInlet;
	pMAF->m_AirInletAir = pMAF->m_AirFromp_AirInlet;

	LimpIn.Q_AirInlet = ActualIn.Q_AirInlet;
}
