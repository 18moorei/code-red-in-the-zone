task usercontrol(){
	int DY, DT;
	//Disable PID
	setPIDforMotor(driveSplitLeft, false);
	setPIDforMotor(driveSplitRight, false);
	setPIDforMotor(liftRight, false);
	setPIDforMotor(armLeft, false);

	while(true){
		//Driving
		DY = threshold(PAIRED_CH2^2 / MAX_POWER, 5) + ((PAIRED_BTN8U - PAIRED_BTN8D) * MAX_POWER);
		DT = threshold(PAIRED_CH1^2 / MAX_POWER, 5) + ((PAIRED_BTN8R - PAIRED_BTN8L) * MAX_POWER);
		drive(DY, DT);

		//Pistons (toggle)
		if(PAIRED_BTN7R){
			pistons(!PISTON_POS);
			waitUntil(!PAIRED_BTN7R);
		}

		//Arms
		arms(threshold(PAIRED_CH3, 15) + ((PAIRED_BTN6U - PAIRED_BTN6D) * MAX_POWER));

		//Lift
		lift((PAIRED_BTN7U - PAIRED_BTN7D) * MAX_POWER);

		//Intake
		intake((PAIRED_BTN5U - PAIRED_BTN5D) * MAX_POWER);
	}
}
