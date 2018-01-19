task blink();

task usercontrol(){
	int DY, DT;
	bool isReset = false;
	startTask(blink);

	//Enable Positioning System
	startTask(positionsystem);

	while(true){
		//Driving
		DY = threshold(PAIRED_CH2^2 / MAX_POWER, 5);
		DT = threshold(PAIRED_CH1^2 / MAX_POWER, 5);
		drive(DY, DT);

		//Mogo
		mogo(threshold(PAIRED_CH3, 15));

		//Arm
		arm((PAIRED_BTN6U - PAIRED_BTN6D) * MAX_POWER);

		//Lift
		lift((PAIRED_BTN7U - PAIRED_BTN7D) * MAX_POWER);

		//Intake
		intake((PAIRED_BTN5U - PAIRED_BTN5D) * MAX_POWER);

		//Reset (can be done multiple times, only required once)
		if(SensorValue[resetButton]){
			resetAll();
			isReset = true;
			stopTask(blink);
			SensorValue[resetLED] = false;
			waitUntil(!SensorValue[resetButton]);
		}
	}
}

task blink(){
	while(true){
		SensorValue[resetLED] = !SensorValue[resetLED];
		wait1Msec(1000);
	}
}
