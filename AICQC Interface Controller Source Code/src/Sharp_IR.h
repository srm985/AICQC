#ifndef Sharp_IR_h_
#define Sharp_IR_h_

//*******Define sensor channels*******
#define Forward_IR		0
#define Rear_IR			1
#define Left_IR			2
#define Right_IR		3
#define Top_IR			4
#define Bottom_IR		5

#define maxDist			115	//130 = 75cm
#define minDist			268

void IR_init(void);
uint16_t IR_Read(uint8_t ch);
char Obstacle_Detect(void);

#endif