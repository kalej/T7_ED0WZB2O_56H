typeof(IgnNorm.fi_Ignition) Get_IgnNorm_fi_Ignition() {
	typeof(IgnNormCal.Map) fi_Ignition;
	typeof(IgnNormCal.Map) fi_NormCalMap;

	fi_NormCalMap = MAP_U16_U16_I16(18, 16, IgnNormCal.m_AirXSP,
			IgnNormCal.n_EngYSP, MAF.m_AirInletIgn, In.n_Engine,
			IgnNormCal.Map);
	fi_Ignition = fi_NormCalMap;
	if (Ign.ActiveMap == 'N') {
		if (fi_NormCalMap >= IgnNormProt.fi_Map) {
			IgnNormProt.fi_Map += IgnNormCal.fi_Step;
			if (fi_NormCalMap < IgnNormProt.fi_Map)
				IgnNormProt.fi_Map = fi_NormCalMap;
			fi_Ignition = IgnNormProt.fi_Map;
		} else {
			IgnNormProt.fi_Map = fi_NormCalMap;
		}
	} else {
		IgnNormProt.fi_Map = fi_NormCalMap;
	}
	IgnNorm.fi_Ignition = fi_Ignition;

	return IgnNorm.fi_Ignition;
}
