/*
 * LAMPS_project.c
 *
 * Created: 12/7/2023 7:30:06 AM
 * Author : osama
 */ 

#include <string.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "UART_interface.h"
#include "ADC_interface.h"
#include "TMR0_interface.h"


int main(void)
{
	//Setting Lamps
    DIO_setPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	
	//Setting Switches
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN1,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);
	
	//checkLogin
	DIO_setPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_INPUT);
	u8 checkValue=0;
	u8 checkValue1=0;
	u8 btn1,btn2,btn3,btn4,btn5,btn6;
	u8 temperature;
	u16 analogValue;
	u16 digitalValue1;
	char * user;
	u8 c;
	ADC_init(ADC_REFERENCE_INTERNAL);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT); //H_EN1
	DIO_setPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT); //H_A1
	DIO_setPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT); //H_A2
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT); //RX
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);//TX
	u8 reachTemp=0;
	
	//UART_init();
	
    while (1) 
    {
		
		DIO_getPinValue(DIO_PORTD,DIO_PIN4,&checkValue);
		DIO_getPinValue(DIO_PORTD,DIO_PIN5,&checkValue1);
		
		if(checkValue!=1&&checkValue1!=1)
		{
			continue;
		}
		/*UART_RxChar(&c);
		user = "Osama";
		if (c!='0')
		{
			UART_TxChar('D')
		}*/
		
		
		
		
		ADC_getDigitalValue(ADC_CHANNEL0,&digitalValue1);
		
		analogValue = (u32)((digitalValue1*2.56*1000)/1024);
		
		temperature=analogValue/10;
		
		DIO_getPinValue(DIO_PORTA,DIO_PIN6,&btn1);
		DIO_getPinValue(DIO_PORTA,DIO_PIN7,&btn2);
		DIO_getPinValue(DIO_PORTC,DIO_PIN0,&btn3);
		DIO_getPinValue(DIO_PORTC,DIO_PIN1,&btn4);
		DIO_getPinValue(DIO_PORTD,DIO_PIN2,&btn5);
		DIO_getPinValue(DIO_PORTD,DIO_PIN3,&btn6);
		if (temperature>28)
		{
			if (reachTemp==0)
			{
				DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
				DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
				reachTemp=1;
			}
		}
		else if (temperature>=21)
		{
			reachTemp=0;
		}
		else
		{
			DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
			reachTemp=0;
		}
		
		if (btn1==DIO_PIN_HIGH)
		{
			DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		} 
		else
		{
			DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		}
		if (btn2==DIO_PIN_HIGH)
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
		}
		else
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		}
		if (btn3==DIO_PIN_HIGH)
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
		}
		else
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		}
		if (btn4==DIO_PIN_HIGH)
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
		}
		else
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		}
		if (btn5==DIO_PIN_HIGH)
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		}
		else
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		}
		if (btn6==DIO_PIN_HIGH)
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		}
		else
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		}
    }
}

