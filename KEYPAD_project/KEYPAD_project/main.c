/*
 * KEYPAD_project.c
 *
 * Created: 11/30/2023 10:30:19 AM
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
#include "KPD_interface.h"


int main(void)
{
	u8 TxData,RxData;
	TxData = 5;
	
	/*DIO_setPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT); // SS
	DIO_setPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT); // MOSI
	DIO_setPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);  // MISO
	DIO_setPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT); // SCK
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW); // SS >> LOW
	
	KPD_init();

	
	SPI_initMaster();*/
	
	u8 inputs=0;
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	UART_init();
	KPD_init();
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
    while (1) 
    {
		if(inputs==8)
		{
			DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
			continue;
		}
		
		KPD_getValue(&TxData);
		
		if(TxData != KPD_NOT_PRESSED)
		{
			UART_TxChar(TxData);
			inputs++;
		}
    }
}

