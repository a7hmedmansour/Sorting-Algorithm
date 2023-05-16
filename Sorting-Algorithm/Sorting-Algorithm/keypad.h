/*
 * keypad.h
 *
 * Created: 01-Apr-23 2:43:49 AM
 *  Author:BITS Team
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define F_CPU (16000000UL)
#include <util/delay.h>
#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#define INVALID_KEYPAD_PRESS (0xFF)
void keypad_init();
unsigned char keypad_get_value();

#endif /* KEYPAD_H_ */