typedef struct {
	int x;
	int y;
	int z;
	int r;
} Point;

Point current_pos;
Point bias;

task positionsystem {
	stopTask(positionsystem);
	int velY = 0, dir, c, a, b;
	while (true) {
		velY = threshold(SensorValue[aclY], bias.y);
		dir = SensorValue[gyro] % 3600 / 10;
		c = velY;
		a = cos(dir) * c; //x
		b = sin(dir) * c; //y
		current_pos.x += a;
		current_pos.y += b;
		current_pos.r = dir;
		wait1Msec(1000);
	}
}

void setHome(void) {
	current_pos.x = 0;
	current_pos.y = 0;
	current_pos.r = 0;
	SensorValue[gyro] = 0;
	SensorScale[gyro] = 260;
	SensorFullCount[gyro] = 3600;
	SensorValue[aclX] = 0;
	SensorValue[aclY] = 0;
	SensorValue[aclZ] = 0;
	wait1Msec(1000);
	bias.x = SensorValue[aclX] + 2;
	bias.y = SensorValue[aclY] + 2;
	bias.z = SensorValue[aclZ] + 2;
}
