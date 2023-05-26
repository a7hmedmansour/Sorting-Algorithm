
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
