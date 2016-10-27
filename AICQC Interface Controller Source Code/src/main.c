/******************************
 *********AICQC Testbed********
 ******************************/

#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "main.h"
#include "LED_Disp.h"
#include "Sharp_IR.h"
#include "I2C.h"
#include "LCD_Disp.h"
#include "UART.h"
#include "Ultrasonic.h"

#define F_CPU	1000000
#include <util/delay.h>
#define __DELAY_BACKWARD_COMPATIBLE__ 


int main(void)
{
	//*******Initialize External Hardware*******
	//LED_init();
	IR_init();
	//I2C_init();
	_delay_ms(10);
	LCD_init();
	UART_init(12);
	//******************************************
	
	
	//***************Define Ports***************
	DDRA &= 0b11000000;
	//PORTA &= 0b11000000;
	DDRB |= 0b00011111;
	PORTB &= 0b11100000;
	DDRD |= 0b00111100;
	PORTD |= 0b00111100;
	//******************************************
	
	
	//*************Define Variables*************
	uint16_t throttle = minPWM;
	uint16_t roll = midRoll;
	uint16_t pitch = midPitch;
	uint16_t yaw = midYaw;
	uint16_t aux1 = minPWM;
	
	int altitude;
	int prev_alt = 12;
	
	unsigned char highPitch = 0;
	unsigned char lowPitch = 0;
	unsigned char highRoll = 0;
	unsigned char lowRoll = 0;
	//******************************************
	
	
	//********Establish PWM Safety Timer********
	/*TIMSK = 1 << TOIE0;
	TCNT0 = 0x6C;	//Load timer0 counter
	TCCR0 |= (1 << CS02) | (1 << CS00);*/
	//******************************************
	
	//sei();	//Enable interrupts after main definitions
	_delay_ms(1000);
	
	while(1)
	{	
		_delay_ms(25);
		
		altitude = US_Read_ADC();
				
		if(altitude >= setAltitude && throttle <= maxThrottle && prev_alt >= altitude)
		{
			throttle += 10;	
		}
		else if(altitude <= setAltitude && throttle >= minThrottle && prev_alt <= altitude)
		{
			throttle -= 10;	
		}
			
		prev_alt = altitude;

		switch(Obstacle_Detect())
		{
			case 0x00:
				if(highRoll)
				{
					roll = midRoll - offset;
					highRoll --;
				}
				else if(lowRoll)
				{
					roll = midRoll + offset;
					lowRoll --;
				}
				else
				{
					roll = midRoll;
				}
			
				if(highPitch)
				{
					pitch = midPitch - offset;
					highPitch --;
				}
				else if(lowPitch)
				{
					pitch = midPitch + offset;
					lowPitch --;
				}
				else
				{
					pitch = midPitch;
				}
			break;
			
			case 0x01:
				if(highRoll)
				{
					roll = midRoll - offset;
					highRoll --;
				}
				else if(lowRoll)
				{
					roll = midRoll + offset;
					lowRoll --;
				}
				else
				{
					roll = midRoll;
				}
				
				pitch = midPitch - offset;
				lowPitch = count;
			break;
			
			case 0x02:
				if(highRoll)
				{
					roll = midRoll - offset;
					highRoll --;
				}
				else if(lowRoll)
				{
					roll = midRoll + offset;
					lowRoll --;
				}
				else
				{
					roll = midRoll;
				}
				
				pitch = midPitch + offset;
				highPitch = count;
			break;
			
			case 0x03:
				roll = midRoll + offset;
				highRoll = count;
				
				if(highPitch)
				{
					pitch = midPitch - offset;
					highPitch --;
				}
				else if(lowPitch)
				{
					pitch = midPitch + offset;
					lowPitch --;
				}
				else
				{
					pitch = midPitch;
				}
			break;
			
			case 0x04:
				roll = midRoll + offset;
				highRoll = count;
				
				if(highPitch)
				{
					pitch = midPitch - offset;
					highPitch --;
				}
				else if(lowPitch)
				{
					pitch = midPitch + offset;
					lowPitch --;
				}
				else
				{
					pitch = midPitch;
				}
			break;
			
			case 0x05:
				roll = midRoll + offset;
				highRoll = count;
				
				pitch = midPitch - offset;
				lowPitch = count;
			break;
			
			case 0x06:
				roll = midRoll + offset;
				highRoll = count;
				
				pitch = midPitch + offset;
				highPitch = count;
			break;
			
			case 0x07:
				roll = midRoll + offset;
				highRoll = count;
				
				if(highPitch)
				{
					pitch = midPitch - offset;
					highPitch --;
				}
				else if(lowPitch)
				{
					pitch = midPitch + offset;
					lowPitch --;
				}
				else
				{
					pitch = midPitch;
				}
			break;
			
			case 0x08:
				roll = midRoll - offset;
				lowRoll = count;
				
				if(highPitch)
				{
					pitch = midPitch - offset;
					highPitch --;
				}
				else if(lowPitch)
				{
					pitch = midPitch + offset;
					lowPitch --;
				}
				else
				{
					pitch = midPitch;
				}
			break;
			
			case 0x09:
				roll = midRoll - offset;
				lowRoll = count;
				
				pitch = midPitch - offset;
				lowPitch = count;
			break;
			
			case 0x0A:
				roll = midRoll - offset;
				lowRoll = count;
				
				pitch = midPitch + offset;
				highPitch = count;
			break;
			
			case 0x0B:
				roll = midRoll - offset;
				lowRoll = count;
				
				if(highPitch)
				{
					pitch = midPitch - offset;
					highPitch --;
				}
				else if(lowPitch)
				{
					pitch = midPitch + offset;
					lowPitch --;
				}
				else
				{
					pitch = midPitch;
				}
			break;
			
			case 0x0C:
				if(highRoll)
				{
					roll = midRoll - offset;
					highRoll --;
				}
				else if(lowRoll)
				{
					roll = midRoll + offset;
					lowRoll --;
				}
				else
				{
					roll = midRoll;
				}
				
				pitch = midPitch + offset;
				highPitch = count;
			break;
			
			case 0x0D:
				if(highRoll)
				{
					roll = midRoll - offset;
					highRoll --;
				}
				else if(lowRoll)
				{
					roll = midRoll + offset;
					lowRoll --;
				}
				else
				{
					roll = midRoll;
				}
				
				pitch= midPitch - offset;
				lowPitch = count;
			break;
			
			case 0x0E:
				if(highRoll)
				{
					roll = midRoll - offset;
					highRoll --;
				}
				else if(lowRoll)
				{
					roll = midRoll + offset;
					lowRoll --;
				}
				else
				{
					roll = midRoll;
				}
				
				pitch = midPitch + offset;
				highPitch = count;
			break;
			
			case 0x0F:
				if(highRoll)
				{
					roll = midRoll - offset;
					highRoll --;
				}
				else if(lowRoll)
				{
					roll = midRoll + offset;
					lowRoll --;
				}
				else
				{
					roll = midRoll;
				}
				
				if(highPitch)
				{
					pitch = midPitch - offset;
					highPitch --;
				}
				else if(lowPitch)
				{
					pitch = midPitch + offset;
					lowPitch --;
				}
				else
				{
					pitch = midPitch;
				}
			break;
		}
		
		
		//*********************************************************
		//********************Write PWM Values*********************
		//*********************************************************
		TCCR0 |= (1 << CS00);
		
		PORTB |= 0b00000001;
		for(int i = 1; i <= ((throttle+calib) >> 4); i++)	//Throttle
		{
			TCNT0 = 0x00;
			while(TCNT0 <= 3)
			{
			}
		}
		PORTB &= 0b11111110;
		
		
		PORTB |= 0b00000010;
		for(int i = 1; i <= ((roll+calib) >> 4); i++)	//Roll
		{
			TCNT0 = 0x00;
			while(TCNT0 <= 3)
			{
			}
		}
		PORTB &= 0b11111101;
		
		
		PORTB |= 0b00000100;
		for(int i = 1; i <= ((pitch+calib) >> 4); i++)	//Pitch
		{
			TCNT0 = 0x00;
			while(TCNT0 <= 3)
			{
			}
		}
		PORTB &= 0b11111011;
		
		
		PORTB |= 0b00001000;
		for(int i = 1; i <= ((yaw+calib) >> 4); i++)	//Yaw
		{
			TCNT0 = 0x00;
			while(TCNT0 <= 3)
			{
			}
		}
		PORTB &= 0b11110111;
		
		
		PORTB |= 0b00010000;
		for(int i = 1; i <= ((aux1+calib) >> 4); i++)	//Aux1
		{
			TCNT0 = 0x00;
			while(TCNT0 <= 3)
			{
			}
		}
		PORTB &= 0b11101111;
		//*********************************************************
		//**********************End PWM Write**********************
		//*********************************************************
	}
}
