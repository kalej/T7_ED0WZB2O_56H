#include "t7types.h"

typeof(ECMStat.msCounter) t_LoadLimStart;
typeof(ECMStat.msCounter) t_ReduceTimeStart[4];
typeof(ECMStat.msCounter) t_RampTimeStart[4];
typeof(ECMStat.msCounter) t_IgnKnk_Adap_Start;

u8 byte_F0EE6C, byte_F0EE6D, byte_F0EE6E;

int Get_IgnKnk_fi_Offset(i16 cylIdx) {
	u8 fi_OffAdapMinIdx;
	u8 idx;

	typeof(ECMStat.msCounter) rampTime;
	typeof(ECMStat.msCounter) reduceTime;
	typeof(ECMStat.msCounter) * pt_RampTimeStart;
	typeof(In.n_Engine) n_Engine;
	typeof(In.n_Engine) n_Engine_div_400;
	typeof(In.n_Engine) * pn_Engine;
	typeof(IgnKnk.fi_Offset[0]) fi_OffsetSum;
	typeof(IgnKnk.fi_Offset[0]) * pfi_Offset;
	typeof(IgnKnk.fi_OffNorm[0]) fi_OffNorm;
	typeof(IgnKnk.fi_OffNorm[0]) fi_OffNormMax;
	typeof(IgnKnk.fi_OffNorm[0]) fi_OffNormSum;

	typeof(IgnKnkAdap.fi_OffsetAdap[0]) * pfi_OffsetAdap;
	typeof(IgnKnkAdap.fi_OffsetAdap[0]) fi_OffAdapMin;
	typeof(IgnKnkAdap.fi_OffsetAdap[0]) fi_OffsetAdapSum;
	typeof(IgnKnkAdap.fi_OffsetAdap[0]) fi_OffAdapAvgMax;

	typeof(IgnKnkProt.KnockNumber[0]) * pKnockNumber;

	i16 *pfi_OffNorm;
	i16 fi_OffsetSumAdjusted;

	if (F_KnkDet.ST_Active)
		rampTime = ((IgnKnkCal.X_FalseDetRamp * IgnKnkCal.RampTime) & 0xFFFF)
				/ 16;
	else
		rampTime = IgnKnkCal.RampTime;

	if (Fault.U_Knock & 0xF0) {
		idx = 0;
		pfi_OffsetAdap = IgnKnkAdap.fi_OffsetAdap;
		do {
			*pfi_OffsetAdap++ = 0;
			++idx;
		} while (idx < 4);
	}

	if (In.n_Engine < 6400)
		n_Engine = In.n_Engine;
	else
		n_Engine = 6399;

	IgnKnk.fi_MaxOffset = TAB_U16_I16(IgnKnkCal.n_EngYSP, In.n_Engine,
			IgnKnkCal.fi_Map1MaxOffset);
	IgnKnk.Index = MAP_U16_U16_I16(IgnKnkCal.m_AirXSP, IgnKnkCal.n_EngYSP,
			MAF.m_AirInlet, In.n_Engine, IgnKnkCal.IndexMap);
	IgnKnk.AdpHighLim = TAB_U16_U16(IgnKnkCal.n_EngYSP, In.n_Engine,
			IgnKnkCal.AdpHighLimTab);
	IgnKnkProt.AdpLowLim = TAB_U16_U16(IgnKnkCal.n_EngYSP, In.n_Engine,
			IgnKnkCal.AdpLowLimTab);

	if (ECMStat.ST_EngineStarted && MAF.m_AirInletIgn >= IgnKnkProt.AdpLowLim
			&& Ign.ActiveMap != 'I') {
		if (IgnKnk.AdpHighLim >= MAF.m_AirInletIgn) {
			if (byte_F0EE6C) {
				if (IgnKnk.AdpHighLim > IgnKnkProt.AdpLowLim) {
					if (MAF.m_AirInletIgn > IgnKnkProt.AdpLowLim) {
						IgnKnkProt.fi_PartAdap = (MAF.m_AirInletIgn
								- IgnKnkProt.AdpLowLim)
								* IgnKnkAdap.fi_OffsetAdap[cylIdx]
								/ (IgnKnk.AdpHighLim - IgnKnkProt.AdpLowLim);
					} else {
						IgnKnkProt.fi_PartAdap = 0;
					}
				} else {
					IgnKnkProt.fi_PartAdap = IgnKnkAdap.fi_OffsetAdap[cylIdx];
				}

				if (IgnKnk.fi_OffNorm[cylIdx] > IgnKnkProt.fi_PartAdap)
					IgnKnk.fi_OffNorm[cylIdx] = IgnKnkProt.fi_PartAdap;
			} else {
				byte_F0EE6D = 1;
			}
		} else if (byte_F0EE6C) {
			byte_F0EE6C = 0;
			byte_F0EE6D = 0;
			byte_F0EE6E = 1;
			idx = 0;
			pfi_OffNorm = IgnKnk.fi_OffNorm;
			pfi_OffsetAdap = IgnKnkAdap.fi_OffsetAdap;
			do {
				if (*pfi_OffsetAdap < *pfi_OffNorm)
					*pfi_OffNorm++ = *pfi_OffsetAdap++;
				++idx;
			} while (idx < 4);
			t_LoadLimStart = ECMStat.msCounter;
		} else if (byte_F0EE6D) {
			byte_F0EE6C = 0;
			byte_F0EE6D = 0;
			byte_F0EE6E = 1;
			idx = 0;
			pfi_OffNorm = IgnKnk.fi_OffNorm;
			pfi_OffsetAdap = IgnKnkAdap.fi_OffsetAdap;
			do {
				if (*pfi_OffsetAdap < *pfi_OffNorm)
					*pfi_OffNorm++ = *pfi_OffsetAdap++;
				++idx;
			} while (idx < 4);
		} else {
			IgnKnkAdap.fi_OffsetAdap[cylIdx] = IgnKnk.fi_OffNorm[cylIdx];
		}

		if (KnkDet.KnockCyl[cylIdx] && IgnKnkCal.ST_Enable) {
			if (IgnKnkProt.KnockNumber[cylIdx] > 8) {
				if (IgnKnk.Index) {
					IgnKnk.fi_OffNorm[cylIdx] += 100 * IgnKnkCal.fi_Offset[7]
							/ IgnKnk.Index;
				}
			} else if (IgnKnk.Index) {
				IgnKnk.fi_OffNorm[cylIdx] +=
						100
								* IgnKnkCal.fi_Offset[IgnKnkProt.KnockNumber[cylIdx]
										- 1] / IgnKnk.Index;
			}
			idx = 0;
			fi_OffNormSum = 0;
			pfi_OffNorm = IgnKnk.fi_OffNorm;
			while (idx < 4) {
				if (idx != cylIdx)
					fi_OffNormSum += *pfi_OffNorm;
				++pfi_OffNorm;
				++idx;
			}
			fi_OffNorm = IgnKnkCal.fi_OffsRelMax + (IgnKnk.fi_OffNorm / 3);
			if (fi_OffNorm > IgnKnk.fi_OffNorm[cylIdx])
				IgnKnk.fi_OffNorm[cylIdx] = fi_OffNorm;

			idx = 0;
			fi_OffNormMax = -200;
			pfi_OffNorm = IgnKnk.fi_OffNorm;
			while (idx < 4) {
				if (fi_OffNormMax < *pfi_OffNorm)
					fi_OffNormMax = *pfi_OffNorm;
				++pfi_OffNorm;
				++idx;
			}

			if (IgnKnk.fi_OffNorm[cylIdx] < IgnKnkCal.MaxDiff2 + fi_OffNormMax)
				IgnKnk.fi_OffNorm[cylIdx] = IgnKnkCal.MaxDiff2 + fi_OffNormMax;

			if (!ECMStat.ST_EngineSynced) {
				switch (cylIdx) {
				case 0:
					IgnKnk.fi_OffNorm[3] = IgnKnk.fi_OffNorm[0];
					break;
				case 1u:
					IgnKnk.fi_OffNorm[2] = IgnKnk.fi_OffNorm[1];
					break;
				case 2u:
					IgnKnk.fi_OffNorm[1] = IgnKnk.fi_OffNorm[2];
					break;
				case 3u:
					IgnKnk.fi_OffNorm[0] = IgnKnk.fi_OffNorm[3];
					break;
				}

			}
			t_ReduceTimeStart[cylIdx] = ECMStat.msCounter;
			if (!ECMStat.ST_EngineSynced) {
				switch (cylIdx) {
				case 0:
					t_ReduceTimeStart[3] = t_ReduceTimeStart[0];
					break;
				case 1u:
					t_ReduceTimeStart[2] = t_ReduceTimeStart[1];
					break;
				case 2u:
					t_ReduceTimeStart[1] = t_ReduceTimeStart[2];
					break;
				case 3u:
					t_ReduceTimeStart[0] = t_ReduceTimeStart[3];
					break;
				}

			}
			t_IgnKnk_Adap_Start = ECMStat.msCounter;
			pn_Engine = &IgnKnkProt.n_Engine[cylIdx];
			*pn_Engine = In.n_Engine;
			if (!ECMStat.ST_EngineSynced) {
				switch (cylIdx) {
				case 0:
					IgnKnkProt.n_Engine[3] = *pn_Engine;
					break;
				case 1u:
					IgnKnkProt.n_Engine[2] = *pn_Engine;
					break;
				case 2u:
					IgnKnkProt.n_Engine[1] = *pn_Engine;
					break;
				case 3u:
					IgnKnkProt.n_Engine[0] = *pn_Engine;
					break;
				}
			}
		} else if (t_LoadLimStart + IgnKnkCal.LoadLimTimer
				< ECMStat.msCounter) {
			n_Engine_div_400 = n_Engine / 400;
			if (F_KnkDet.ST_Active) {
				reduceTime = IgnKnkCal.ReduceTime[n_Engine_div_400]
						* IgnKnkCal.X_FalseDetReduce / 16;
			} else {
				reduceTime = IgnKnkCal.ReduceTime[n_Engine_div_400];
			}

			if (IgnKnkCal.n_EngHyst + IgnKnkProt.n_Engine[cylIdx] < In.n_Engine
					|| (IgnKnkProt.n_Engine[cylIdx] - IgnKnkCal.n_EngHyst
							> In.n_Engine)) {
				t_ReduceTimeStart[cylIdx] = 0;
			}

			if (reduceTime + t_ReduceTimeStart[cylIdx] > ECMStat.msCounter
					|| IgnKnk.fi_OffNorm[cylIdx] >= 0) {
				IgnKnkProt.KnockNumber[cylIdx] = 0;
			} else {
				if (rampTime + t_RampTimeStart[cylIdx] <= ECMStat.msCounter) {
					IgnKnk.fi_OffNorm[cylIdx] += IgnKnkCal.fi_Ramp;
					if (IgnKnk.fi_OffNorm[cylIdx] > 0)
						IgnKnk.fi_OffNorm[cylIdx] = 0;

					t_RampTimeStart[cylIdx] = ECMStat.msCounter;
				}
				if (IgnKnk.fi_OffNorm[cylIdx] > 0)
					IgnKnk.fi_OffNorm[cylIdx] = 0;

				IgnKnkProt.KnockNumber[cylIdx] = 0;
			}
		}
		if (IgnKnk.Index != 0) {
			RAM_adjust_max_fi_offset = 100 * IgnKnk.fi_MaxOffset / IgnKnk.Index;
		} else {
			RAM_adjust_max_fi_offset = IgnKnk.fi_MaxOffset;
		}
		if (IgnKnk.fi_OffNorm[cylIdx] < RAM_adjust_max_fi_offset)
			IgnKnk.fi_OffNorm[cylIdx] = RAM_adjust_max_fi_offset;
	} else //if !ECMStat.ST_EngineStarted || MAF.m_AirInletIgn < IgnKnkProt.AdpLowLim || Ign.ActiveMap == 'I'
	{
		if (ECMStat.ST_EngineStarted) {
			if (Ign.ActiveMap == 'I') {
				idx = 0;
				pfi_OffNorm = IgnKnk.fi_OffNorm;
				do {
					*pfi_OffNorm++ = 0;
					++idx;
				} while (idx < 4);

				if (KnkDet.ST_ClearIgnOff) {
					idx = 0;
					pfi_OffsetAdap = IgnKnkAdap.fi_OffsetAdap;
					do {
						*pfi_OffsetAdap++ = 0;
						++idx;
					} while (idx < 4);
					KnkDet.ST_ClearIgnOff = 0;
				}

				if (byte_F0EE6E == 1) {
					fi_OffAdapMin = 0;
					fi_OffsetAdapSum = 0;
					fi_OffAdapMinIdx = 0;
					idx = 0;
					pfi_OffsetAdap = IgnKnkAdap.fi_OffsetAdap;
					do {
						if (fi_OffAdapMin > *pfi_OffsetAdap) {
							fi_OffAdapMin = *pfi_OffsetAdap;
							fi_OffAdapMinIdx = idx;
						}
						fi_OffsetAdapSum += *pfi_OffsetAdap++;
						++idx;
					} while (idx < 4);

					fi_OffAdapAvgMax = (fi_OffsetAdapSum - fi_OffAdapMin) / 3;
					if ((fi_OffAdapMin - fi_OffAdapAvgMax)
							< IgnKnkCal.MaxDiff) {
						IgnKnkAdap.fi_OffsetAdap[fi_OffAdapMinIdx] =
								fi_OffAdapAvgMax;
						IgnKnk.fi_OffNorm[fi_OffAdapMinIdx] = fi_OffAdapAvgMax;
					}
					byte_F0EE6E = 0;
				}
			} else // if Ign.ActiveMap != 'I'
			{
				if (rampTime + t_RampTimeStart[cylIdx] <= ECMStat.msCounter) {
					IgnKnk.fi_OffNorm[cylIdx] += IgnKnkCal.fi_Ramp;
					if (IgnKnk.fi_OffNorm[cylIdx] > 0)
						IgnKnk.fi_OffNorm[cylIdx] = 0;

					t_RampTimeStart[cylIdx] = ECMStat.msCounter;
				}
			}
		} // if !ECMStat.ST_EngineStarted
		else {
			t_IgnKnk_Adap_Start = ECMStat.msCounter;

			if (In.T_Engine < 60) {
				idx = 0;
				pfi_OffsetAdap = IgnKnkAdap.fi_OffsetAdap;
				do {
					*pfi_OffsetAdap++ = 0;
					++idx;
				} while (idx < 4);
			}

			idx = 0;
			pfi_OffNorm = IgnKnk.fi_OffNorm;
			pt_RampTimeStart = t_RampTimeStart;
			pKnockNumber = IgnKnkProt.KnockNumber;
			do {
				*pfi_OffNorm++ = 0;
				*pKnockNumber++ = 0;
				*pt_RampTimeStart++ = ECMStat.msCounter;
				++idx;
			} while (idx < 4);
		}

		if (t_IgnKnk_Adap_Start + IgnKnkCal.AdapTimer < ECMStat.msCounter) {
			idx = 0;
			pfi_OffsetAdap = IgnKnkAdap.fi_OffsetAdap;
			do {
				if (*pfi_OffsetAdap < 0)
					++*pfi_OffsetAdap;
				t_IgnKnk_Adap_Start = ECMStat.msCounter;
				++pfi_OffsetAdap;
				++idx;
			} while (idx < 4);
		}
		byte_F0EE6C = 1;
	}

	IgnKnk.fi_Offset[cylIdx] = (IgnKnk.fi_OffNorm[cylIdx] * IgnKnk.Index) / 100;

	idx = 0;
	fi_OffsetSum = 0;
	pfi_Offset = IgnKnk.fi_Offset;
	while (idx < 4u) {
		fi_OffsetSum += *pfi_Offset++;
		++idx;
	}

	fi_OffsetSumAdjusted = fi_OffsetSum;
	if (fi_OffsetSum < 0)
		fi_OffsetSumAdjusted = IgnKnk.fi_Offset + 3;
	IgnKnk.fi_MeanKnock = fi_OffsetSumAdjusted / 4;
	return IgnKnk.fi_Offset[cylIdx];
}
