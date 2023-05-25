/*
 * Timer0.c
 *
 * Created: 16-May-23 8:43:10 PM
 *  Author: A7MED
 */ 
#include "Timer0.h"

void(*g_callbackPTR)(uint8)=NULL_PTR;
uint8 g_callbackValue =0;
void Timer0_init()
{
	TCNT0=0;
	SET_BIT(TIMSK,TOIE0);
	TCCR0=(1<<FOC0)|(1<<CS02)|(1<<CS00);
	SET_BIT(SREG,I_BIT);
}
void Timer0_setcallback(void(*ptr)(uint8),uint8 value)
{
g_callbackPTR=ptr;	
g_callbackValue=value;
}
ISR(TIMER0_OVF_vect)
{
	if (g_callbackPTR!=NULL_PTR)
	{
		
		(*g_callbackPTR)(g_callbackValue);
	}
}