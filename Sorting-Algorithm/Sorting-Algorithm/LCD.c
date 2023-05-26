/*
 * LCD.c
 *
 * Created: 08-Apr-23 9:36:24 PM
 *  Author: BITS Team
 */ 
#include "LCD.h"
#define SET_CURSOR_LOCATION (0x80)
void LCD_Init(void) /* LCD initialization */
{
	LCD_Data_Dir |= 0b00010111;		 /*set PB0 PB1 PB2 PB4 as output*/
	
	//LCD_Command_Dir |= 0b00001100;	 /*set EN , RS as output*/
	
	LCD_Command_Dir |= (1<<RS)|(1<<EN);
	
	_delay_ms(15); //LCD power on delay in 4-bit mode 15ms
	
	LCD_Command(0x02);			/* initialize LCD in 4-bit mode */
	LCD_Command(0x28);			/* initialize the LCD in 4-bit mode, 2 lines, and 5*8 format */
	LCD_Command(0x0C);			/* Display ON, Cursor OFF */
	LCD_Command(0x06);			/* Shift cursor from left to right on read/write */
	LCD_Command(0x01);			/* Clear Display */
	LCD_Command(0x80);			/* Cursor at home position */
}
void LCD_Command(unsigned char cmd)
{
	PORTB &= 0b11101000;		/* Clear the 4 bits of the data bus */ //0000-0000
	unsigned char High=((cmd&0xF0) >> 4);
	PORTB |= ((( High& 0b00001000) << 1 ) | (High & 0b00000111));	/* Send the lowest 4 bits of cmd to the data bus */
	CLR_BIT (LCD_Command_Port, RS);		/* RS = 0 command reg. */
	SET_BIT (LCD_Command_Port, EN);		/* Enable pulse */
	_delay_us(1);						/* more than 450 ns */
	CLR_BIT (LCD_Command_Port, EN);		/* Display pulse */
	_delay_ms(2);						/* wait for the longest command */
	
	PORTB &= 0b11101000;		/* Clear the 4 bits of the data bus */
	unsigned char low=(cmd&0x0F);
	PORTB |= ((( low& 0b00001000) << 1 ) | (low & 0b00000111));	/* Send the lowest 4 bits of cmd to the data bus */
	SET_BIT (LCD_Command_Port, EN);		/* Enable pulse */
	_delay_us(1);						/* more than 450 ns */
	CLR_BIT (LCD_Command_Port, EN);		/* Display pulse */
	_delay_ms(2);						/* wait for the longest command */
	
}
void LCD_Char(unsigned char char_data) 
{
	PORTB &= 0b11101000;		/* Clear the 4 bits of the data bus */
	unsigned char High=((char_data&0xF0) >> 4);
	PORTB |= ((( High& 0b00001000) << 1 ) | (High & 0b00000111));	/* Send the lowest 4 bits of cmd to the data bus */
	SET_BIT (LCD_Command_Port, RS);		/* RS = 1 data reg. */
	SET_BIT (LCD_Command_Port, EN);		/* Enable pulse */
	_delay_us(1);						/* more than 450 ns */
	CLR_BIT (LCD_Command_Port, EN);		/* Display pulse */
	_delay_us(100);						/* more than 43us for data writing */
	
	PORTB &= 0b11101000;
	unsigned char low=(char_data&0x0F);
	PORTB |= ((( low& 0b00001000) << 1 ) | (low & 0b00000111));	/* Send the lowest 4 bits of cmd to the data bus */
	SET_BIT (LCD_Command_Port, EN);		/* Enable pulse */
	_delay_us(1);						/* more than 450 ns */
	CLR_BIT (LCD_Command_Port, EN);		/* Display pulse */
	_delay_us(100);						/* more than 43us for data writing */
	
}
void LCD_String(char *str)
{
	int i;
	for (i=0; str[i]!=0; i++)
	{
		LCD_Char(str[i]);
	}
}
void LCD_Clear(void)
{
	LCD_Command(0x01);
}