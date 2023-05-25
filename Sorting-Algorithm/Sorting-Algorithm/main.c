/*
 * Sorting-Algorithm.c
 *
 * Created: 14-May-23 11:59:27 PM
 * Author : BITS Team
 */ 
#include <stdio.h>
//#include <avr/io.h>
#define F_CPU (16000000UL)
#include <util/delay.h>

#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include "std_types.h"
#include "keypad.h"
#include "seven_segment.h"
#include "LCD.h"
#include "Timer0.h"

void bubbleSort(int arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// Swap elements
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main(void)
{
seven_segment_Init();
LCD_Init();
keypad_Init();
Timer0_init();
uint8 value;
int Number[10]={0},i; //number user input
bool check=TRUE;
char str[4]; //To covert int to string 
int count_digit=0,num=0,digit;	// count_digit : to count number of digits user input
								//num: index for Number store input
								//digit: user to convert to decimal			

				
do{
	value=keypad_get_value(); /*scan value from keypad*/
	if (value)
	{	
		if (value >='0' && value <='9' && count_digit < 4) //check if input  number or not
		{
			digit = value - '0';
			Number[num] = (Number[num] * 10) + digit;
			count_digit++;
			LCD_Char(value);
			_delay_ms(250);
			check=TRUE;
		}
		if (value == '+') //check if user input more than 4 digit or user input other number
		{
			LCD_Char(' ');
			count_digit=0;
			_delay_ms(50);
			if (check) //To avoid increase size of array when button + pressed more one 
			{
				num++;
				check=FALSE;
			}
		}		
	}
}while (value != 'E');

if (num > 0)
{
LCD_Clear();
bubbleSort(Number,num+1);
for (i = 0; i <=num; i++)
{	
	LCD_Char(' ');
	_delay_ms(250);
	 sprintf(str, "%d", Number[i]);
	 _delay_ms(500);
	 LCD_String(str);
}
}
while(1)
{	
for (i = 0; i <=num; i++)
{
	seven_segment_number(Number[i]);
}
}
return 0;
}