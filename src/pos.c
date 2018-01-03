typedef struct {
	int x;
	int y;
} Point;

Point current_pos;

task positionsystem {
	while (true) {
		int velX = threshold(SensorValue[aclX], 1);
		int velY = threshold(SensorValue[aclY], 1);
		int dir = SensorValue[gyro] % 360;
		int c = velY;
		int a = cos(dir) * c; //x
		int b = sin(dir) * c; //y
		current_pos.x += a;
		current_pos.y += b;
	}
}

void setHome(void) {
	current_pos.x = 0;
	current_pos.y = 0;
	SensorValue[gyro] = 0;
	SensorValue[aclX] = 0;
	SensorValue[aclY] = 0;
	SensorValue[aclZ] = 0;
}
