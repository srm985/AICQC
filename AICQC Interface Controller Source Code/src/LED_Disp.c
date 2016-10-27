#include <asf.h>
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "LED_Disp.h"



void LED_init()
{
	int delay = 30;	//30msec delay
	DDRA |= 0x7F;	//Set PORTA 0-6 to output
	DDRB |= 0X03;	//Set PORTB 0-1 to output
	PORTA |= 0x7F;	//Define pull-up resistors 0-6
	PORTB &= 0xFC;	//Define pull-down resistors 0-1
	
	//*******Sweep Display For Error Detection*******
	LED_Write(zero, digit_one);
	_delay_ms(delay);
	LED_Write(zero, digit_two);
	_delay_ms(delay);
	LED_Write(one, digit_one);
	_delay_ms(delay);
	LED_Write(one, digit_two);
	_delay_ms(delay);
	LED_Write(two, digit_one);
	_delay_ms(delay);
	LED_Write(two, digit_two);
	_delay_ms(delay);
	LED_Write(three, digit_one);
	_delay_ms(delay);
	LED_Write(three, digit_two);
	_delay_ms(delay);
	LED_Write(four, digit_one);
	_delay_ms(delay);
	LED_Write(four, digit_two);
	_delay_ms(delay);
	LED_Write(five, digit_one);
	_delay_ms(delay);
	LED_Write(five, digit_two);
	_delay_ms(delay);
	LED_Write(six, digit_one);
	_delay_ms(delay);
	LED_Write(six, digit_two);
	_delay_ms(delay);
	LED_Write(seven, digit_one);
	_delay_ms(delay);
	LED_Write(seven, digit_two);
	_delay_ms(delay);
	LED_Write(eight, digit_one);
	_delay_ms(delay);
	LED_Write(eight, digit_two);
	_delay_ms(delay);
	LED_Write(nine, digit_one);
	_delay_ms(delay);
	LED_Write(nine, digit_two);
	_delay_ms(delay);
	LED_Write(dash, digit_one);
}

void LED_Write(uint8_t letter, uint8_t digit)
{
	PORTA |= 0x7F;	//Clear previous
	PORTB &= 0xFC;	//Clear previous
	digit &= Digit_Locations;	//Safety
	PORTB |= digit;
	PORTA &= letter;
}

void LED_Clear(void)
{
	PORTA |= 0x7F;
	PORTB &= 0xFC;	
}