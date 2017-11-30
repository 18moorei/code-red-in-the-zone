task usercontrol(){
	int DY, DT, DX;

	while(true){
		//Driving
		DY = threshold(PAIRED_CH2^2 / MAX_POWER, 5) + ((PAIRED_BTN8U - PAIRED_BTN8D) * MAX_POWER);
		DT = threshold(PAIRED_CH1^2 / MAX_POWER, 5);
		DX = threshold(PAIRED_CH4^2 / MAX_POWER, 5) + ((PAIRED_BTN8R - PAIRED_BTN8L) * MAX_POWER);
		drive(DY, DT, DX);

		//Mogo
		mogo(threshold(PAIRED_CH3, 15));
	}
}
