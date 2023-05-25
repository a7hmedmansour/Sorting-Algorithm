#include "Functions.h"
void Userinput(int Number[],int *num)
{
	int count_digit=0; // count_digit : to count number of digits user input
	int digit;	//digit: user to convert to decimal	
	bool check=TRUE; //check if user press + one time	
	uint8 value;	
	*num=0;
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
					 (*num)++;
					check=FALSE;
				}
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
void Display_sort_Number(int Number[],int num)
{
int i;
char str[4]; //To covert int to string 
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
for (i = 0; i <=num; i++)
{
	seven_segment_number(Number[i]);
}
seven_segment_Init();
}
