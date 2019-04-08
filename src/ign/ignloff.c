#include <t7types.h>
#include <functions/interpolation.h>
#include <symbols/ecmstat.h>
#include <symbols/fault.h>
#include <symbols/idle.h>
#include <symbols/ignloff.h>
#include <symbols/ignloffcal.h>
#include <symbols/ignloffprot.h>
#include <symbols/ignstartcal.h>
#include <symbols/in.h>

u16 IgnLOff_PosRampAccum;
i16 Get_IgnLOff_PosRampStep_Rem() {
	int v1;

	IgnLOff_PosRampAccum += IgnLOffCal.PosRampStep;
	v1 = IgnLOff_PosRampAccum >> 7;
	IgnLOff_PosRampAccum -= v1 << 7;
	return v1;
}

u16 IgnLOff_NegRampAccum;

i16 Get_IgnLOff_NegRampStep_Rem() {
	int v1;

	IgnLOff_NegRampAccum += IgnLOffCal.NegRampStep;
	v1 = IgnLOff_NegRampAccum >> 7;
	IgnLOff_NegRampAccum -= v1 << 7;
	return v1;
}

typeof(ECMStat.n_Combustion) n_Combustion_LOff_diff;
typeof(ECMStat.n_Combustion) n_Combustion_LOff_Old;

void Calc_IgnLOff_fi_Offset() {
	u16 v0;
	i16 v2;
	u16 v6;

	typeof(IgnLOffProt.fi_Offset) * pLOffOffset;

	pLOffOffset = &IgnLOffProt.fi_Offset;
	if (!IgnLOffCal.ST_Enable || ECMStat.ST_BlkHeatStart) {
		*pLOffOffset = 0;
	} else if (ECMStat.ST_EngineStarted) {
		if (!IgnLOffProt.NrCombustion)
			IgnLOffProt.ST_LOStAftPowUp = 1;
		if (Idle.StartAirMode != 1 && IgnLOffProt.NrCombustion)
			++IgnLOff.NrCombDelay;
		if (IgnLOff.NrCombDelay <= IgnLOffCal.n_CombAftSt
				|| !IgnLOffProt.NrCombustion
				|| In.T_Engine >= IgnLOffCal.TempLim
				|| ((IgnStartCal.ST_Mode | Idle.StartAirMode)
						&& (Idle.StartAirMode == 1 || IgnStartCal.ST_Mode != 1))) {
			if (*pLOffOffset) {
				IgnLOffProt.TempOffset = MAP_U16_U16_I16(IgnLOffCal.m_AirXSP,
						IgnLOffCal.n_EngYSP, IgnLOffProt.m_requestLO,
						In.n_Engine, IgnLOffCal.fi_MapOffset);
				if (IgnLOffProt.TempOffset <= 0) {
					if (IgnLOffProt.TempOffset >= 0) {
						if (*pLOffOffset <= 0) {
							*pLOffOffset += Get_IgnLOff_PosRampStep_Rem();
						} else {
							*pLOffOffset -= Get_IgnLOff_NegRampStep_Rem();
						}
					} else if (*pLOffOffset >= IgnLOffProt.TempOffset) {
						if (*pLOffOffset >= 0) {
							*pLOffOffset = 0;
						} else {
							*pLOffOffset += Get_IgnLOff_PosRampStep_Rem();
						}
					} else {
						*pLOffOffset = IgnLOffProt.TempOffset;
					}
				} else if (*pLOffOffset <= IgnLOffProt.TempOffset) {
					if (*pLOffOffset <= 0) {
						*pLOffOffset = 0;
					} else {
						*pLOffOffset -= Get_IgnLOff_NegRampStep_Rem();
					}
				} else {
					*pLOffOffset = IgnLOffProt.TempOffset;
				}
			} else {
				*pLOffOffset = 0;
			}
		} else {
			if (IgnLOffProt.NrCombustion)
				IgnLOffProt.ST_LOStAftPowUp = 1;
			IgnLOffProt.TempOffset = MAP_U16_U16_I16(IgnLOffCal.m_AirXSP,
					IgnLOffCal.n_EngYSP, IgnLOffProt.m_requestLO, In.n_Engine,
					IgnLOffCal.fi_MapOffset);
			if (IgnLOffProt.ST_FirstTime == 1) {
				if (IgnLOffProt.TempOffset != *pLOffOffset) {
					if (IgnLOffProt.TempOffset <= 0)
						*pLOffOffset -= Get_IgnLOff_NegRampStep_Rem();
					else
						*pLOffOffset += Get_IgnLOff_PosRampStep_Rem();
				}
				if (IgnLOffProt.TempOffset >= *pLOffOffset)
					IgnLOffProt.ST_FirstTime = 0;
			} else {
				if (IgnLOffCal.NegDeltaLim + IgnLOffProt.TempOffset
						>= *pLOffOffset) {
					if (*pLOffOffset + IgnLOffCal.PosDeltaLim
							>= IgnLOffProt.TempOffset)
						v2 = IgnLOffProt.TempOffset;
					else
						v2 = IgnLOffCal.PosDeltaLim + *pLOffOffset;
					*pLOffOffset = v2;
				} else {
					*pLOffOffset -= IgnLOffCal.NegDeltaLim;
				}
			}

			n_Combustion_LOff_diff = ECMStat.n_Combustion
					- n_Combustion_LOff_Old;
			if (IgnLOffProt.NrCombustion
					<= ECMStat.n_Combustion - n_Combustion_LOff_Old)
				IgnLOffProt.NrCombustion = 0;
			else
				IgnLOffProt.NrCombustion -= n_Combustion_LOff_diff;
			n_Combustion_LOff_Old = ECMStat.n_Combustion;
		}
	} else {
		if (IgnLOffCal.ST_AllowRestart == 1 || !IgnLOffProt.ST_LOStAftPowUp) {
			v6 = TAB_I16_U16(IgnLOffCal.T_EngineSP, In.T_Engine,
					IgnLOffCal.CombTab);
			v0 = TAB_I16_U16(IgnLOffCal.T_AirInletSP, In.T_AirInlet,
					IgnLOffCal.N_AirTab);
			if (v6 >= v0)
				IgnLOffProt.NrCombustion = v0;
			else
				IgnLOffProt.NrCombustion = v6;
		}
		n_Combustion_LOff_Old = ECMStat.n_Combustion;
		IgnLOffProt.ST_FirstTime = 1;
		*pLOffOffset = 0;
		IgnLOff.NrCombDelay = 0;
		if (IgnLOffProt.ST_LOStAftPowUp && !IgnLOffCal.ST_AllowRestart)
			IgnLOffProt.NrCombustion = 0;
	}
	IgnLOff.fi_Offset = *pLOffOffset;

	if (In.p_AirAmbient < IgnLOffCal.p_AirAmbHigh && !Fault.p_AirAmbient) {
		if (In.p_AirAmbient <= IgnLOffCal.p_AirAmbLow) {
			IgnLOff.fi_Offset = 0;
			return;
		}

		IgnLOff.fi_Offset = ((In.p_AirAmbient - IgnLOffCal.p_AirAmbLow)
				* (*pLOffOffset)) / (*pLOffOffset - IgnLOffCal.p_AirAmbLow);
	}
}
