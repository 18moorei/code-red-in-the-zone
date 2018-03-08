task blink();

task usercontrol(){
	int DY, DT;
	bool isReset = false;
	startTask(blink);

	while(true){
		//Driving
		DY = threshold(vexRT[Ch2]^2 / MAX_POWER, 5) + ((vexRT[Btn8U] - vexRT[Btn8D]) * MAX_POWER);
		DT = threshold(vexRT[Ch1]^2 / MAX_POWER, 5) + ((vexRT[Btn8R] - vexRT[Btn8L]) * MAX_POWER);
		drive(DY, DT);

		//Mogo
		mogo(threshold(PAIRED_CH3, 15) - (DY + DT != 0 ? MOGO_LOCK : 0));

		//Arm
		arm((PAIRED_BTN6U - PAIRED_BTN6D) * MAX_POWER);

		//Lift
		lift((PAIRED_BTN7U - PAIRED_BTN7D) * MAX_POWER);

		//Intake
		intake((PAIRED_BTN5U - PAIRED_BTN5D) * MAX_POWER);

		//Run AutoPreloader (blocking)
		if(SensorValue[Btn7L]){
			startTask(autopreloader);
			waitUntil(!SensorValue[Btn7L]);
			stopTask(autopreloader);
		}

		//Tell AutoPreloader the current cone total
		if(PAIRED_BTN7R){
			current_cones.total = 0;
		} else if(vexRT[Btn8U]){
			current_cones.total += 1;
		} else if(vexRT[Btn8D]){
			current_cones.total -= 1;
		}

		//Reset (can be done multiple times, only required once)
		if(abs(SensorValue[aclZ]) > 50){
			startTask(blink);
		}
		if(SensorValue[resetButton]){
			setHome();
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
