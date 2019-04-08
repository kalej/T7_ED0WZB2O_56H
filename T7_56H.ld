MEMORY
{
	rom    (rx)  : ORIGIN = 0x000000, LENGTH = 512K
	ram    (rwx) : ORIGIN = 0xF00000, LENGTH = 64k
}

SECTIONS
{
	. = 0x000000;
	.text :
	{
		Convert_Q_to_m = 0x015476; 
		Convert_m_to_Q = 0x0154F8;
		FactorFiltAdjust = 0x015534;
		map_u16_u16_u16 = 0x04295E;
		tab_i16_u8 = 0x042E1E;
	} >rom
	
	.S14B76 0x014B76 : 
	{
	*(.S14B76);
	} >rom =0x4E71
	
	.S1574E 0x01574E : 
	{
	*(.S1574E);
	} >rom =0x4E71
	
	.S4A53C 0x04A53C : 
	{
	*(.S4A53C);
	} >rom =0x4E71
	
	. = 0xF00000;
	.data :
	{
		RAM_VersionLimitIdx = 0xF00000 - 0xF00000;
		MAFCal = 0xF034A0 - 0xF00000; 
		MAFProt = 0xF0DEF4 - 0xF00000;
		MAF = 0xF0DF1C - 0xF00000;
		MAFCalcCount = 0xF0DF3E - 0xF00000;  
		t_TDC_TDC_Buffer = 0xF0DF52 - 0xF00000;
		In = 0xF0F418 - 0xF00000;
		ActualIn = 0xF0F49A - 0xF00000;
		LimpIn = 0xF0F51C - 0xF00000;
		Fault = 0xF0F59E - 0xF00000;
		FaultBitArray = 0xF0F61A - 0xF00000;
		Out = 0xF0F624 - 0xF00000;
		DiagOut = 0xF0F67E - 0xF00000;
		DiagActive = 0xF0F696 - 0xF00000;
		ECMStat = 0xF0F6A8 - 0xF00000;    
	*(.data);
	} >ram
}
