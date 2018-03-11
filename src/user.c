task blink();
task coneCount();
task autoPreloader();
int cones = 0; //Current cone count
bool apPreload = false; //If auto preloading preloads (true) or ground loads (false)

task usercontrol(){
	int DY, DT;
	bool isReset = false;
	startTask(blink);
	startTask(coneCount);

	while(true){
		//Driving
		DY = threshold(vexRT[Ch2]^2 / MAX_POWER, 5) + ((vexRT[Btn8U] - vexRT[Btn8D]) * MAX_POWER);
		DT = threshold(vexRT[Ch1]^2 / MAX_POWER, 5) + ((vexRT[Btn8R] - vexRT[Btn8L]) * MAX_POWER);
		drive(DY, DT);

		//Mogo
		mogo(threshold(PAIRED_CH3, 15) - (DY + DT > 5 ? MOGO_LOCK : 0));
		SensorValue[leftMogoIndicator] = SensorValue[leftMogoDetector];
		SensorValue[rightMogoIndicator] = SensorValue[rightMogoDetector];

		//Arm
		arm((PAIRED_BTN6U - PAIRED_BTN6D) * MAX_POWER);

		//Lift
		lift((PAIRED_BTN7U - PAIRED_BTN7D) * MAX_POWER);

		//Intake
		intake((PAIRED_BTN5U - PAIRED_BTN5D) * MAX_POWER);

		//Run AutoPreloader (blocking)
		if(SensorValue[Btn7L]){
			startTask(autoPreloader);
			waitUntil(!SensorValue[Btn7L]);
			stopTask(autoPreloader);
		}

		//Reset (can be done multiple times, only required once)
		if(abs(SensorValue[aclZ]) > 50){ //Warn if bot has been lifted
			startTask(blink);
		}
		if(SensorValue[resetButton]){ //Reset sensors if reset button is pressed
			setHome();
			isReset = true;
			stopTask(blink);
			SensorValue[resetLED] = false;
			waitUntil(!SensorValue[resetButton]);
		}
	}
}

//Blink the warning LED is the sensors need to be reset
task blink(){
	while(true){
		SensorValue[resetLED] = !SensorValue[resetLED];
		wait1Msec(1000);
	}
}

//Handle the automated preloader stuff to allow stopping and starting at any point
task autoPreloader(){
	apPreload = SensorValue[armEncoder] > -1380;
	while(true){
		//Return for pickup
		intake(MAX_POWER);
		setArmPosition(apPreload ? -1380 : -1500);
		setLiftPosition(0);
		//Pickup cone
		wait1Msec(500);
		//Bring cone to tower
		setLiftPosition(cones * 15);
		setArmPosition(cones * 20);
		//Release cone
		intake(-MAX_POWER);
		setArmPosition(-1000);
	}
}

//Allows the partner to count the cones but not add more that 1 per button and not block the driver
task coneCount(){
	while(true){
		//Tell AutoPreloader the current cone total
		if(PAIRED_BTN7R){
			cones = 0;
		} else if(vexRT[Btn8UXmtr2]){
			cones += 1;
			waitUntil(!vexRT[Btn8UXmtr2]);
		} else if(vexRT[Btn8DXmtr2]){
			cones -= 1;
			waitUntil(!vexRT[Btn8DXmtr2]);
		}
	}
}
