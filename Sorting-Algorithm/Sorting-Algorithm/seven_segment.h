/*
 * seven_segment.h
 *
 * Created: 15-May-23 5:55:55 AM
 *  Author: BITS Team
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"

#define seven_segment_Data_Dir DDRB
#define seven_segment_Data_port PORTB
//columns in 7-segment
#define COM1 PIN3
#define COM2 PIN2
#define COM3 PIN5
#define COM4 PIN6



void seven_segment_Init(void);
void seven_segment_Display(unsigned char number); 




#endif /* SEVEN_SEGMENT_H_ */