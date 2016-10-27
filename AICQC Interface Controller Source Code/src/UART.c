#include <asf.h>
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#include "UART.h"

void UART_init(int baud)
{
	UBRRH = (uint8_t)(baud >> 8);
	UBRRL = (uint8_t)(baud);
	
	UCSRB = ((1<<RXEN) | (1<<TXEN) | (1<<RXCIE));
	UCSRC = ((1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0));
	
	UCSRA |= 0x02; 
}

void UART_PutChar(unsigned char c)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = c; 
	//while(!(UCSRA & (1 << TXC)));
}

unsigned char UART_ReadChar(void)
{
	while(!(UCSRA & (1 << RXC)));
	return UDR;
}