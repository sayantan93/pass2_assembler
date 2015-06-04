
struct instruction
{
	char *nemo,*mcode;
	int id;
} ins[41];

void instr_init(){

	ins[0].nemo="START";
	ins[0].mcode="111111";
	ins[0].id=0;

	ins[1].nemo="MOV";
	ins[1].mcode="000001";
	ins[1].id=1;
	
	ins[2].nemo="MOV";
	ins[2].mcode="000010";
	ins[2].id=2;
	
	ins[3].nemo="MOV";
	ins[3].mcode="000100";
	ins[3].id=3;
	
	ins[4].nemo="MOV";
	ins[4].mcode="000101";
	ins[4].id=4;

	ins[5].nemo="MVI";
	ins[5].mcode="000011";
	ins[5].id=5;
	
	ins[6].nemo="ADI";
	ins[6].mcode="000111";
	ins[6].id=6;

	ins[7].nemo="ANI";
	ins[7].mcode="001110";
	ins[7].id=7;

	ins[8].nemo="MLI";
	ins[8].mcode="001010";
	ins[8].id=8;

   	ins[9].nemo="ADD";
	ins[9].mcode="000110";
	ins[9].id=9;

	ins[10].nemo="ADD";
	ins[10].mcode="001000";
	ins[10].id=10;

	ins[11].nemo="MUL";
	ins[11].mcode="001001";
	ins[11].id=11;

	ins[12].nemo="MUL";
	ins[12].mcode="001011";
	ins[12].id=12;
	
	ins[13].nemo="MAC";
	ins[13].mcode="001100";
	ins[13].id=13;
	
	ins[14].nemo="AND";
	ins[14].mcode="001101";
	ins[14].id=14;


	ins[15].nemo="AND";
	ins[15].mcode="001111";
	ins[15].id=15;	
	
	ins[16].nemo="OR";
	ins[16].mcode="010000";
	ins[16].id=16;
	
	ins[17].nemo="OR";
	ins[17].mcode="010001";
	ins[17].id=17;
	
	ins[18].nemo="OR";
	ins[18].mcode="010010";
	ins[18].id=18;
	
	ins[19].nemo="NOT";
	ins[19].mcode="010100";
	ins[19].id=19;
	
	ins[20].nemo="NOT";
	ins[20].mcode="010011";
	ins[20].id=20;
	
	ins[21].nemo="INR";
	ins[21].mcode="010101";
	ins[21].id=21;
	
	ins[22].nemo="DCR";
	ins[22].mcode="010110";
	ins[22].id=22;
	
	ins[23].nemo="RLC";
	ins[23].mcode="010111";
	ins[23].id=23;
	
	ins[24].nemo="RRC";
	ins[24].mcode="011000";
	ins[24].id=24;
	
	ins[25].nemo="PUSH";
	ins[25].mcode="100100";
	ins[25].id=25;
	
	ins[26].nemo="POP";
	ins[26].mcode="100101";
	ins[26].id=26;
	
	ins[27].nemo="CMP";
	ins[27].mcode="011011";
	ins[27].id=27;
	
	ins[28].nemo="JMP";
	ins[28].mcode="011100";
	ins[28].id=28;
	
	ins[29].nemo="JC";
	ins[29].mcode="011101";
	ins[29].id=29;

	ins[30].nemo="JZ";
	ins[30].mcode="011110";
	ins[30].id=30;
	
	ins[31].nemo="JP";
	ins[31].mcode="011111";
	ins[31].id=31;
	
	ins[32].nemo="JS";
	ins[32].mcode="100000";
	ins[32].id=32;
	
	ins[33].nemo="JNC";
	ins[33].mcode="100001";
	ins[33].id=33;
	
	ins[34].nemo="JNZ";
	ins[34].mcode="100010";
	ins[34].id=34;
	
	ins[35].nemo="JNS";
	ins[35].mcode="100011";
	ins[35].id=35;
	
	ins[36].nemo="CALL";
	ins[36].mcode="100110";
	ins[36].id=36;
	
	ins[37].nemo="RET";
	ins[37].mcode="100111";
	ins[37].id=37;
	
	ins[38].nemo="CLC";
	ins[38].mcode="101000";
	ins[38].id=38;
	
	ins[39].nemo="CMC";
	ins[39].mcode="101001";
	ins[39].id=39;
	
	ins[40].nemo="HLT";
	ins[40].mcode="101010";
	ins[40].id=40;
}
