/*
 * Sorting-Algorithm.c
 *
 * Created: 14-May-23 11:59:27 PM
 * Author : BITS Team
 */ 

//#include <avr/io.h>
#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include "std_types.h"
#include "keypad.h"
#include "seven_segment.h"
#include "LCD.h"
#include "Timer0.h"
int main(void)
{
	seven_segment_Init();
	LCD_Init();
	keypad_Init();
    /* Replace with your application code */
    while (1) 
    {
    }
}

