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
#include "std_types.h"
#define F_CPU (16000000UL)
#include <util/delay.h>

#define seven_segment_Data_Dir DDRB
#define seven_segment_Data_port PORTB
//columns in 7-segment
#define COM1 PIN6
#define COM2 PIN5
#define COM3 PIN2
#define COM4 PIN3

void seven_segment_Init(void);
void seven_segment_Display(unsigned char number); 

#endif /* SEVEN_SEGMENT_H_ */