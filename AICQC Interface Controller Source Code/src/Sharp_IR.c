#include <asf.h>
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Sharp_IR.h"


void IR_init(void)
{
	ADMUX = 0x40;	//Use AVCC (5V ref.) w/external AREF cap
	ADCSRA = 0x87;	//Define ADC register
}

uint16_t IR_Read(uint8_t ch)
{
	int poll_factor = 5;
	uint16_t adc_result = 0;
	
	ch &= 0x07;	//Force channel to be 0-7 (safety)
	ADMUX = (ADMUX & 0xF8)|ch; //Define ADC channel (maybe 0xF8?)
	
	for(int i=1;i<=poll_factor;i++)
	{
		ADCSRA |= (1<<ADSC);	//Set ADC flag
		while(ADCSRA & (1<<ADSC));	//Wait for ADC flag
		adc_result += ADC;
	}
	return(adc_result /= poll_factor);
}

char Obstacle_Detect(void)
{
	int poll_factor = 3;
	uint16_t adc_result[4] = {0,0,0,0};
	uint8_t result = 0;
	for(int i = 0; i <= 3; i++)
	{
		ADMUX = (ADMUX & 0xF8) | i;
		for(int j = 1; j <= poll_factor; j++)
		{
			ADCSRA |= (1<<ADSC);
			while(ADCSRA & (1<<ADSC));
			adc_result[i] += ADC;
		}
		adc_result[i] /= poll_factor;
	}
	for(int i = 0; i <= 3; i++)
	{
		if(adc_result[i] >= maxDist)
		{
			result |= 1 << i;
		}
	}
	return result;
}