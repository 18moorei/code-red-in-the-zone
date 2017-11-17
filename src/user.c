task usercontrol(){
	int DY, DT;
	bool motionAssist = true;
	//Disable PID
	setPIDforMotor(driveSplitLeft, false);
	setPIDforMotor(driveSplitRight, false);
	setPIDforMotor(liftRight, false);
	setPIDforMotor(armLeft, false);

	while(true){
		//Motion Assist
		clearTimer(T1);
		if(PAIRED_BTN7L){
			waitUntil(!PAIRED_BTN7L);
			if(time1[T1] > 1500){
				reset_I2C_sensors();
			} else {
				motionAssist = !motionAssist;
			}
		}

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
		int armPower = threshold(PAIRED_CH3, 15) + ((PAIRED_BTN6U - PAIRED_BTN6D) * MAX_POWER);
		if(armPower){
			arms(armPower, motionAssist);
		} else if(motionAssist){
			arms(required_sign(nMotorEncoder[armLeft], -1000, -1000) * ARM_LOCK, motionAssist);
		} else {
			arms(0, motionAssist);
		}

		//Lift
		lift((PAIRED_BTN7U - PAIRED_BTN7D) * MAX_POWER, motionAssist);

		//Intake
		intake((PAIRED_BTN5U - PAIRED_BTN5D) * MAX_POWER);
	}
}
