i16 Get_IgnTemp_fi_Offset() {
	i16 *pfi_AirOff;

	pfi_AirOff = &Ign.fi_AirOff;
	if (!(Fault.T_AirInlet & 0xF0) && IgnTempCal.ST_Enable
			&& (Ign.ActiveMap != 'I' || IgnTempCal.ST_ActiveAtIdle
					|| (*pfi_AirOff < 0 && In.T_AirInlet > IgnTempCal.AirLimIdle))) {
		if (In.T_AirInlet <= IgnTempCal.T_AirLim
				|| In.T_Engine <= IgnTempCal.T_EngLim) {
			if (In.T_AirInlet <= IgnTempCal.T_AirLim) {
				if (In.T_Engine <= IgnTempCal.T_EngLim) {
					IgnTemp.fi_Offset = *pfi_AirOff + Ign.fi_EngOff;
				} else {
					IgnTemp.fi_Offset = *pfi_AirOff
							+ (IgnKnk.Index * Ign.fi_EngOff) / 100;
				}
			} else {
				IgnTemp.fi_Offset = Ign.fi_EngOff
						+ (IgnKnk.Index * *pfi_AirOff) / 100;
			}
		} else {
			IgnTemp.fi_Offset = (IgnKnk.Index * (Ign.fi_EngOff + *pfi_AirOff))
					/ 100;
		}
	} else {
		IgnTemp.fi_Offset = 0;
	}

	return IgnTemp.fi_Offset;
}

void Calc_Ign_fi_TempOff(void) {
	if (Fault.T_AirInlet & 0xF0) {
		Ign.fi_AirOff = 0;
	} else {
		Ign.fi_AirOff = MAP_I16_I16_I16(IgnTempCal.n_EngXSP,
				IgnTempCal.T_AirYSP, In.n_Engine, In.T_AirInlet,
				IgnTempCal.AirMap);
	}
	if (Fault.T_Engine & 0xF0) {
		Ign.fi_EngOff = 0;
	} else {
		Ign.fi_EngOff = MAP_I16_I16_I16(IgnTempCal.n_EngXSP,
				IgnTempCal.T_EngYSP, In.n_Engine, In.T_Engine,
				IgnTempCal.EngMap);
	}
}
