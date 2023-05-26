//#include <avr/io.h>
#define F_CPU (16000000UL)
#include <util/delay.h>
#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include "Functions.h"
int main(void)
{
seven_segment_Init();
LCD_Init();
keypad_Init();
Timer0_init();

int Number[10]={0}; //number user input
int num=0; //num: index for Number store input

Userinput(Number,&num);
Display_sort_Number(Number,&num);

while(1)
{
	
}
return 0;
}