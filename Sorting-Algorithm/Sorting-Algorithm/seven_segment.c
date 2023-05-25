/*
 * seven_segment.c
 *
 * Created: 15-May-23 5:56:20 AM
 *  Author: BITS Team
 */ 
#include "seven_segment.h"

void seven_segment_Init(void)
{
	SET_BIT(DDRB,COM1); /*Enable first seven segment*/
	SET_BIT(DDRB,COM2);/*Enable second seven segment*/
	SET_BIT(DDRA,COM3); /*Enable third seven segment*/
	SET_BIT(DDRA,COM4); /*Enable fourth seven segment*/
	
	seven_segment_Data_Dir|=0b00010111;     	/*set PB0 ,PB1,PB2,PB4*/
}
void seven_segment_Display(unsigned char number)
{	
	seven_segment_Data_port&=0b11101000; /*Clear the 4-bits*/	                                                                                                                              
	seven_segment_Data_port|= (((number&0b00001000)<<1)| (number&0b00000111)); /*Display the number*/
}
void seven_segment_number(int number) {
  
	SET_BIT(PORTB,COM1);
	SET_BIT(PORTB,COM2);
	SET_BIT(PORTA,COM3);
	SET_BIT(PORTA,COM4);
	
	// Split the number into individual digits
	int digit4 = number % 10;
	int digit3 = (number / 10) % 10;
	int digit2 = (number / 100) % 10;
	int digit1 = (number / 1000) % 10;
		_delay_ms(1000);
	// Display the digits on the seven-segment display
	CLR_BIT(PORTB,COM1);
	seven_segment_Display( digit1);
	_delay_ms(1000);
	SET_BIT(PORTB,COM1);
	CLR_BIT(PORTB,COM2);
	seven_segment_Display( digit2);
	_delay_ms(1000);
	SET_BIT(PORTB,COM2);
	CLR_BIT(PORTA,COM3);
	seven_segment_Display( digit3);
	_delay_ms(1000);
	SET_BIT(PORTA,COM3);
	CLR_BIT(PORTA,COM4);
	seven_segment_Display(digit4);
	_delay_ms(1000);
	SET_BIT(PORTA,COM4);
}