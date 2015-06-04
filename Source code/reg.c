typedef struct registr
{
	char *regi,*address;
	int used;
}registr;


registr regs[64];

void register_init(){
	regs[0].regi="R0";
	regs[0].address="000000";
	regs[0].used=1;		

	regs[1].regi="R1";
	regs[1].address="000001";
	regs[1].used=1;

	regs[2].regi="R2";
	regs[2].address="000010";
	regs[2].used=1;

	regs[3].regi="R3";
	regs[3].address="000011";
	regs[3].used=1;

	regs[4].regi="R4";
	regs[4].address="000100";
	regs[4].used=1;

	regs[5].regi="R5";
	regs[5].address="000101";
	regs[5].used=1;

	regs[6].regi="R6";
	regs[6].address="000110";
	regs[6].used=1;

	regs[7].regi="R7";
	regs[7].address="000111";
	regs[7].used=1;

	regs[8].regi="R8";
	regs[8].address="001000";
	regs[8].used=1;

	regs[9].regi="R9";
	regs[9].address="001001";
	regs[9].used=1;

	regs[10].regi="R10";
	regs[10].address="001010";
	regs[10].used=1;

	regs[11].regi="R11";
	regs[11].address="001011";
	regs[11].used=1;

	regs[12].regi="R12";
	regs[12].address="001100";
	regs[12].used=1;

	regs[13].regi="R13";
	regs[13].address="001101";
	regs[13].used=1;

	regs[14].regi="R14";
	regs[14].address="001110";
	regs[14].used=1;

	regs[15].regi="R15";
	regs[15].address="001111";
	regs[15].used=1;

	regs[16].regi="R16";
	regs[16].address="010000";
	regs[16].used=1;

	regs[17].regi="R17";
	regs[17].address="010001";
	regs[17].used=1;

	regs[18].regi="R18";
	regs[18].address="010010";
	regs[18].used=1;

	regs[19].regi="R19";
	regs[19].address="010011";
	regs[19].used=1;

	regs[20].regi="R20";
	regs[20].address="010100";
	regs[20].used=1;

	regs[21].regi="R21";
	regs[21].address="010101";
	regs[21].used=1;

	regs[22].regi="R22";
	regs[22].address="010110";
	regs[22].used=1;

	regs[23].regi="R23";
	regs[23].address="010111";
	regs[23].used=1;

	regs[24].regi="R24";
	regs[24].address="011000";
	regs[24].used=1;

	regs[25].regi="R25";
	regs[25].address="011001";
	regs[25].used=1;

	regs[26].regi="R26";
	regs[26].address="011010";
	regs[26].used=1;

	regs[27].regi="R27";
	regs[27].address="011011";
	regs[27].used=1;

	regs[28].regi="R28";
	regs[28].address="011100";
	regs[28].used=1;

	regs[29].regi="R29";
	regs[29].address="011101";
	regs[29].used=1;

	regs[30].regi="R30";
	regs[30].address="011110";
	regs[30].used=1;
	
	regs[31].regi="R31";
	regs[31].address="011111";
	regs[31].used=1;

	regs[32].regi="R32";
	regs[32].address="100000";
	regs[32].used=1;

	regs[33].regi="R33";
	regs[33].address="100001";
	regs[33].used=1;

	regs[34].regi="R34";
	regs[34].address="100010";
	regs[34].used=1;

	regs[35].regi="R35";
	regs[35].address="100011";
	regs[35].used=1;

	regs[36].regi="R36";
	regs[36].address="100100";
	regs[36].used=1;

	regs[37].regi="R37";
	regs[37].address="100101";
	regs[37].used=1;

	regs[38].regi="R38";
	regs[38].address="100110";
	regs[38].used=1;

	regs[39].regi="R39";
	regs[39].address="100111";
	regs[39].used=1;

	regs[40].regi="R40";
	regs[40].address="101000";
	regs[40].used=1;

	regs[41].regi="R41";
	regs[41].address="101001";
	regs[41].used=1;

	regs[42].regi="R42";
	regs[42].address="101010";
	regs[42].used=1;

	regs[43].regi="R43";
	regs[43].address="101011";
	regs[43].used=1;

	regs[44].regi="R44";
	regs[44].address="101100";
	regs[44].used=1;

	regs[45].regi="R45";
	regs[45].address="101101";
	regs[45].used=1;

	regs[46].regi="R46";
	regs[46].address="101110";
	regs[46].used=1;

	regs[47].regi="R47";
	regs[47].address="101111";
	regs[47].used=1;

	regs[48].regi="R48";
	regs[48].address="110000";
	regs[48].used=1;

	regs[49].regi="R49";
	regs[49].address="110001";
	regs[49].used=1;

	regs[50].regi="R50";
	regs[50].address="110010";
	regs[50].used=1;

	regs[51].regi="R51";
	regs[51].address="110011";
	regs[51].used=1;

	regs[52].regi="R52";
	regs[52].address="110100";
	regs[52].used=1;

	regs[53].regi="R53";
	regs[53].address="110101";
	regs[53].used=1;

	regs[54].regi="R54";
	regs[54].address="110110";
	regs[54].used=1;

	regs[55].regi="R55";
	regs[55].address="110111";
	regs[55].used=1;

	regs[56].regi="R56";
	regs[56].address="111000";
	regs[56].used=1;

	regs[57].regi="R57";
	regs[57].address="11001";
	regs[57].used=1;

	regs[58].regi="R58";
	regs[58].address="11010";
	regs[58].used=1;

	regs[59].regi="R59";
	regs[59].address="11011";
	regs[59].used=1;

	regs[60].regi="R60";
	regs[60].address="11100";
	regs[60].used=1;

	regs[61].regi="R61";
	regs[61].address="11101";
	regs[61].used=1;

	regs[62].regi="R62";
	regs[62].address="11110";
	regs[62].used=1;

	regs[63].regi="R63";
	regs[63].address="11111";
	regs[63].used=1;
}
