#include "Timer0.h"
#include <stdio.h>
void (*g_callbacktimer)(int* ,int*) = NULL_PTR;
int *g_numberarray= NULL;
int *g_arraysize=NULL;
uint8 over_flow_times=0;
void Timer0_init()
{
	TCNT0=0;
	SET_BIT(TIMSK,TOIE0);
	
	TCCR0=(1<<FOC0)|(1<<CS02)|(1<<CS00);
	
	SET_BIT(SREG,I_BIT);
}
void Timer0_setcallback(void(*ptr)(int*,int*),int arr[],int *size)
{
g_callbacktimer=ptr;	
g_numberarray=arr;
g_arraysize=size;
}

ISR(TIMER0_OVF_vect)
{
	if (g_callbacktimer!=NULL_PTR )
	{
		(*g_callbacktimer)(g_numberarray,g_arraysize);
	}
}