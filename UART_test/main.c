/*
 * UART_test.c
 *
 * Created: 10/31/2023 11:00:56 PM
 * Author : Kareem Hussein
 */ 

#include <string.h>

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "UART_interface.h"
#include "DIO_interface.h"
#include "TMR1_interface.h"

/* HAL */
#include "LCD_interface.h"


int main(void)
{
    DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT); // Tx .> O/P
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);  // Rx .> I/P
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	UART_init();
	
	char user[9];
	char pass[9];
	u8 logIn=0;
	char cmd;
	u8 cmdEntered=0;
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT); // OC0 >> O/P
	TMR1_init();
	TMR1_setCompareMatchValueA(374);
	TMR1_start();
	
	/*
	499    90
	249   -90
	374    0
	*/
	
    while (1) 
    {
		if (logIn==0)
		{
			UART_TxString((u8*)"Enter User Name:(Followed by #):\r\n");
			UART_RxString(user);
			UART_TxString((u8*)"\r\n");
			UART_TxString((u8*)"Enter Password:(Followed by #):\r\n");
			UART_RxString(pass);
			UART_TxString((u8*)"\r\n");
			
			if ((strcmp(user,"osama123")==0)&&(strcmp(pass,"12345678")==0))
			{
				UART_TxString((u8*)"Log In Done!\r\n");
				DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
				logIn=1;
			}
		}
		
		if (cmdEntered!=1)
		{
			UART_TxString((u8*)"Enter 0 to close the door 1 to pull it 2 to push it:\r\n");
			UART_RxChar(&cmd);
			UART_TxString((u8*)"\r\n");
			if (cmd=='0')
			{
				UART_TxString((u8*)"Door closed\r\n");
				TMR1_setCompareMatchValueA(374);
			}
			else if (cmd=='1')
			{
				UART_TxString((u8*)"Door Pulled\r\n");
				TMR1_setCompareMatchValueA(499);
			}
			else if (cmd=='2')
			{
				UART_TxString((u8*)"Door Pushed\r\n");
				TMR1_setCompareMatchValueA(249);
			}
				
		}
		
    }
}



