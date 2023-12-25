/*
 * LCD_project.c
 *
 * Created: 12/1/2023 3:20:55 PM
 * Author : osama
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "UART_interface.h"

/* HAL */
#include "LCD_interface.h"


int main(void)
{
	/*DIO_setPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT); // SS
	DIO_setPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT); // MOSI
	DIO_setPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);// MISO
	DIO_setPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT); // SCK*/
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	
	//checkValue
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	
	UART_init();
	EEPROM_init();
	
	u8 * userName;
	u8 * userNameData;
	
	u8 TxData,RxData;
	u8 counter=0;
	u8 logIn=0;
	LCD_init();
	LCD_writeString("Please Enter ");
	LCD_goToSpecificPosition(LCD_LINE_TWO,0);
	LCD_writeString("User Name followed by #:");
	while (1) 
    {
		UART_RxChar(&RxData);
		if(counter==0)
		{
			LCD_clear();
		}
		if (RxData!=0xff&&RxData!='B')
		{
			userName[counter]=RxData;
			LCD_sendChar(RxData);
			counter++;
		}
		else if (RxData=='B')
		{
			EEPROM_writePage(0,&userName,7);
			LCD_clear();
			EEPROM_readPage(0,&userNameData,7);
			if (userNameData==userName)
			{
				LCD_writeString("Loged In!");
				LCD_goToSpecificPosition(LCD_LINE_TWO,0);
				LCD_writeString(userNameData);
				DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
				logIn=0;
			}
		}
		
    }
}

