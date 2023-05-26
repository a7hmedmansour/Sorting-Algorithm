#ifndef TIMER0_H_
#define TIMER0_H_
#include "BIT_MATH.h"
#include "std_types.h"
#include <avr/interrupt.h>
#define I_BIT (7)
#define NULL_PTR ((void*)0) 
#define  Number_of_dely 61 //count 1 sec 



void Timer0_init();
void Timer0_setcallback(void(*ptr)(int*,int*),int arr[],int *size);


#endif /* TIMER0_H_ */