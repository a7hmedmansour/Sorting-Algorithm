#include "Functions.h"
uint8 g_ticks=0;
uint8 g_second=0;
int i=0;
void Userinput(int Number[],int *num)
{
int count_digit=0; // count_digit : to count number of digits user input
int digit;	//digit: user to convert to decimal	
bool check=TRUE; //check if user press + one time	
uint8 value=0;	
*num=0; //size of array
do{
value=keypad_get_value(); /*scan value from keypad*/

if (value)
{
if (value >='0' && value <='9' && count_digit < 4) //check if input  number or not
{
	digit = value - '0';
	Number[*num] = (Number[*num] * 10) + digit;
	count_digit++;
	LCD_Char(value);
	check=TRUE;
}
}
if (value == '+') //check if user input more than 4 digit or user input other number
{
	LCD_Char(' ');
	count_digit=0;
	if (check) //To avoid increase size of array when button + pressed more one
	{
			(*num)++;
		check=FALSE;
	}
}

}while (value != 'E');
}
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
void seven_segment_number(int number[],int *num)
{
SET_BIT(PORTB,COM1);
SET_BIT(PORTB,COM2);
SET_BIT(PORTA,COM3);
SET_BIT(PORTA,COM4);
	 
// Split the number into individual digits
int digit4 = number[i] % 10;
int digit3 = (number[i] / 10) % 10;
int digit2 = (number[i] / 100) % 10;
int digit1 = (number[i] / 1000) % 10;
	
g_ticks++;
if (g_ticks == Number_of_dely)
{			
	g_second++;
	g_ticks=0;
}
if (g_second == 1)
{
	CLR_BIT(PORTB,COM1);
	seven_segment_Display(digit1);
}
if (g_second == 2)
{
	SET_BIT(PORTB,COM1);
	CLR_BIT(PORTB,COM2);
	seven_segment_Display( digit2);
}
if (g_second== 3)
{
	SET_BIT(PORTB,COM2);
	CLR_BIT(PORTA,COM3);
	seven_segment_Display( digit3);
}
if (g_second == 4)
{
	SET_BIT(PORTA,COM3);
	CLR_BIT(PORTA,COM4);
	seven_segment_Display(digit4);
}
if (g_second == 5)
{
	SET_BIT(PORTA,COM4);
	if (i <= (*num) )
	{
		i++;
	}
	g_second=0;
}
}
void Display_sort_Number(int Number[],int *num)
{
int i;
char str[4]; //To covert int to string 
LCD_Clear();
bubbleSort(Number,(*num)+1);
if (*num > 0)
{
	for (i = 0; i <=(*num); i++)
	{
	LCD_Char(' ');
	sprintf(str, "%d", Number[i]);
	LCD_String(str);
	}
}

Timer0_setcallback(seven_segment_number,Number,num);	

}
