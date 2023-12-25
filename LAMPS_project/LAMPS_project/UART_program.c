/*
 * UART_program.c
 *
 * Created: 10/31/2023 11:01:35 PM
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "UART_interface.h"
#include "UART_private.h"


void UART_init(void)
{
	// Set Buad Rate = 9600
	UBRRL = 103;
	CLR_BIT(UCSRA,U2X);
	
	/* writing the UCSRC
	select UART MODE = Asynchronous
	configure no parity
	configure stop bits = 1
	configure data bits = 8
	configure no polarity */
	UCSRC = 0X86; //0b10000110
	CLR_BIT(UCSRB,UCSZ2);

	//Enable Tx
	SET_BIT(UCSRB,TXEN);
	
	//Enable Rx
	SET_BIT(UCSRB,RXEN);
}


void UART_TxChar(u8 TxData)
{
	UDR = TxData;
	
	// Busy Wait on Data Register empty flag
	while(0 == GET_BIT(UCSRA,UDRE));
}


void UART_RxChar(u8* RxData)
{
	if(RxData != NULL)
	{
		// Busy Wait on Receive Compelete flag
		while(0 == GET_BIT(UCSRA,RXC));
		
		*RxData = UDR;
	}
}


void UART_TxString(u8* TxString)
{
	u8 counter=0;
	while(TxString[counter]!='\0')
	{
		UART_TxChar(TxString[counter]);
		counter++;
	}
}


void UART_RxString(u8* RxString)
{
	u8 counter=0;
	while(1)
	{
		UART_RxChar(&RxString[counter]);
		if (RxString[counter] == '#')
		{
			break;
		}
		else
		{
			counter++;
		}
	}
	RxString[counter]='\0';
}