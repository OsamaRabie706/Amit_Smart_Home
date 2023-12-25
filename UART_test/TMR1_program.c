/*
 * TMR1_program.c
 *
 * Created: 10/29/2023 8:52:22 PM
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR1_interface.h"
#include "TMR1_config.h"
#include "TMR1_private.h"


void TMR1_init(void)
{
	// Select Mode = Fast PWM Mode(14)
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	// Select Non Inverting Mode
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	
	// Set Timer1 top = 4999 >> Periodic Time = 20ms >> Frequency = 50HZ
	ICR1_u16 = 4999;
}


void TMR1_start(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}


void TMR1_stop(void)
{
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
} 


void TMR1_setCompareMatchValueA(u16 compareValue)
{
	OCR1A_u16 = compareValue;
}