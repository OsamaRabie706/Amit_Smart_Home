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