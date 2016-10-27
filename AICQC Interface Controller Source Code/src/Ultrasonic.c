#include <asf.h>
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#include "Ultrasonic.h"
#include "main.h"
#include "UART.h"
#include "LCD_Disp.h"


ISR(USART_RXC_vect)
{
	char US_Data[3];
	while(UART_ReadChar() != 'R'){}
	
	US_Data[0] = UART_ReadChar();
	US_Data[1] = UART_ReadChar();
	US_Data[2] = UART_ReadChar();
	
	/*for(int i = 0; i <= 2; i++)
	{
		LCD_Write(US_Data[i], RS);
	}
	LCD_Shift(Cur_Shift, Left_Cur, 3);*/
	
	//altitude = (US_Data[2] - '0') + (10 * (US_Data[1] - '0')) + (100 * (US_Data[0] - '0'));
}

char US_Read()
{
	//PORTD |= 0b00000100;
	_delay_ms(500);
	
	char US_Data[3];
	while(UART_ReadChar() != 'R'){}
	
	US_Data[0] = UART_ReadChar();
	US_Data[1] = UART_ReadChar();
	US_Data[2] = UART_ReadChar();
	
	for(int i = 0; i <= 2; i++)
	{
		LCD_Write(US_Data[i], RS);
	}
	LCD_Shift(Cur_Shift, Left_Cur, 3);
	
	//PORTD &= 0b11111011;
	
	return (US_Data[2] - '0') + (10 * (US_Data[1] - '0')) + (100 * (US_Data[0] - '0'));
}

int US_Read_ADC()
{
	int poll_factor = 3;
	int adc_result = 0;
	
	ADMUX = (ADMUX & 0xF8)|0x05; //Define ADC channel (maybe 0xF8?)
	
	for(int i=1;i<=poll_factor;i++)
	{
		ADCSRA |= (1<<ADSC);	//Set ADC flag
		while(ADCSRA & (1<<ADSC));	//Wait for ADC flag
		adc_result += ADC;
	}
	adc_result = (adc_result/poll_factor);
	return(adc_result);
}