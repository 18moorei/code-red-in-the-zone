task usercontrol(){
	int DY, DT;
	bool isReset = false;

	//Enable Positioning System
	startTask(positionsystem);

	while(true){
		//Driving
		DY = threshold(PAIRED_CH2^2 / MAX_POWER, 5);
		DT = threshold(PAIRED_CH1^2 / MAX_POWER, 5);
		drive(DY, DT);

		//Mogo
		mogo(threshold(PAIRED_CH3, 15));

		//Lift
		lift((PAIRED_BTN7U - PAIRED_BTN7D) * MAX_POWER);

		//Reset
		if(SensorValue[reset] && !isReset){
			resetAll();
			isReset = true;
			waitUntil(!SensorValue[reset]);
		}
	}
}
