/*
 * Timer0.h
 *
 * Created: 16-May-23 8:42:56 PM
 *  Author: A7MED
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "BIT_MATH.h"
#include "std_types.h"
#include <avr/interrupt.h>
#define I_BIT (7)
#define NULL_PTR ((void*)0) 
#define  Number_of_Tovf 31


void Timer0_init();
void Timer0_setcallback(void(*ptr)(void));



#endif /* TIMER0_H_ */