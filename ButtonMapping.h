bool X(int joyNum){
	if(joyNum == 1) return joy1Btn(1) == 1;
	else return joy2Btn(1) == 1;
}

bool A(int joyNum){
	if(joyNum == 1) return joy1Btn(2) == 1;
	else return joy2Btn(2) == 1;
}

bool B(int joyNum){
	if(joyNum == 1) return joy1Btn(3) == 1;
	else return joy2Btn(3) == 1;
}

bool Y(int joyNum){
	if(joyNum == 1) return joy1Btn(4) == 1;
	else return joy2Btn(4) == 1;
}

bool LB(int joyNum){
	if(joyNum == 1) return joy1Btn(5) == 1;
	else return joy2Btn(5) == 1;
}

bool RB(int joyNum){
	if(joyNum == 1) return joy1Btn(6) == 1;
	else return joy2Btn(6) == 1;
}

bool LT(int joyNum){
	if(joyNum == 1) return joy1Btn(7) == 1;
	else return joy2Btn(7) == 1;
}

bool RT(int joyNum){
	if(joyNum == 1) return joy1Btn(8) == 1;
	else return joy2Btn(8) == 1;
}

bool BACK(int joyNum){
	if(joyNum == 1) return joy1Btn(9) == 1;
	else return joy2Btn(9) == 1;
}

bool START(int joyNum){
	if(joyNum == 1) return joy1Btn(10) == 1;
	else return joy2Btn(10) == 1;
}

bool L_Stick(int joyNum){
	if(joyNum == 1) return joy1Btn(11) == 1;
	else return joy2Btn(11) == 1;
}

bool R_Stick(int joyNum){
	if(joyNum == 1) return joy1Btn(12) == 1;
	else return joy2Btn(12) == 1;
}
