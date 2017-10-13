void drive(int y, int t = 0){
	//y - Forwards/Backwards
	//t - Turning (optional parameter)
	motor[driveSplitLeft] = y-t;
	motor[driveSplitRight] = y+t;
}

int toggle_pistons(){
	int position = !SensorValue[pistonLeft];
	SensorValue[pistonLeft] = position;
	SensorValue[pistonRight] = position;
	return position;
}

void arms(int power){
	motor[armLeft]	= motor[armRight] = power;
}

void lift(int power){
	motor[liftLeft] = motor[liftRight] = power;
}

void intake(int power){
	motor[coneIntake]	= power;
}
