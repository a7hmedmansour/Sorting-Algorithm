/*
 * CFile1.c
 *
 * Created: 26-May-23 10:59:26 PM
 *  Author: A7MED
 */ 

void seven_segment_dely(int number)
{
	// Split the number into individual digits
	int digit4 = number % 10;
	int digit3 = (number / 10) % 10;
	int digit2 = (number / 100) % 10;
	int digit1 = (number / 1000) % 10;
	
	g_ticks++;
	if (g_ticks >= Number_of_dely)
	{
		g_second++;
		CLR_BIT(PORTB,COM1);
		seven_segment_Display( digit1);
		if (g_second%2==0)
		{
			SET_BIT(PORTB,COM1);
			CLR_BIT(PORTB,COM2);
			seven_segment_Display( digit2);
		}
		if (g_second%3==0)
		{
			SET_BIT(PORTB,COM2);
			CLR_BIT(PORTA,COM3);
			seven_segment_Display( digit3);
		}
		if (g_second%4==0)
		{
			SET_BIT(PORTA,COM3);
			CLR_BIT(PORTA,COM4);
			seven_segment_Display(digit4);
		}
		if (g_second%5==0)
		SET_BIT(PORTA,COM4);
	}
}