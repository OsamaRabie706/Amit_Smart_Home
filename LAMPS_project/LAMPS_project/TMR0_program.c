/*
 * TMR0_program.c
 *
 * Created: 10/17/2023 10:24:38 PM
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR0_interface.h"
#include "TMR0_config.h"
#include "TMR0_private.h"


volatile static u16 private_ctcCounter;
static void(*private_pCallBackOVF)(void)=NULL;
static void(*private_pCallBackCTC)(void)=NULL;


void TMR0_init(void)
{
#if TMR0_MODE == TMR0_NORMAL_MODE
	// Select Mode = Normal Mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	// Init Timer With Preload Value
	TCNT0 = TMR0_PRELOAD_VALUE;
	
	// Enable OVF Interrupt
	SET_BIT(TIMSK,TOIE0); 
	
#elif TMR0_MODE == TMR0_CTC_MODE
	// Select Mode = CTC Mode
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	// Enable OC Interrupt
	SET_BIT(TIMSK,OCIE0);

#elif TMR0_MODE == TMR0_FAST_PWM_MODE
    // Select Mode = FAST PWM Mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	// Select Non Inverting PWM
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif
}


void TMR0_start(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}


void TMR0_stop(void)
{
	// Select Prescaler Value = 0
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}


void TMR0_setCompareMatchValue(u8 compareValue)
{
	OCR0 = compareValue;
}


void TMR0_setDelay_ms_usingCTC(u16 delay_ms)
{
	// under condition tick time 4 MS
	OCR0 = 249;
	private_ctcCounter = delay_ms;
}


void TMR0_setDutyCycle(u8 dytyCycle)
{
	if(dytyCycle<=100)
	{
		OCR0 = ((u16)(dytyCycle*256)/100)-1;
	}
}


void TMR0_setCallBackOVF(void(*ptrToFun)(void))
{
	if(ptrToFun!=NULL)
	{
		private_pCallBackOVF = ptrToFun;
	}
}


void TMR0_setCallBackCTC(void(*ptrToFun)(void))
{
	if(ptrToFun!=NULL)
	{
		private_pCallBackCTC= ptrToFun;
	}
}


// ISR timer0 over flow
void __vector_11 (void) __attribute__ ((signal));
void __vector_11 (void)
{
	static u16 ovfCounter = 0;
	ovfCounter++;
	
	if(TMR0_OVER_FLOW_COUNTER == ovfCounter)
	{
		// Set Preload Value
		TCNT0 = TMR0_PRELOAD_VALUE;
		
		// Clear Counter
		ovfCounter = 0;
		
		//call action
		if(private_pCallBackOVF!=NULL)
		{
			private_pCallBackOVF();
		}
	}
}


// ISR timer0 out compare match
void __vector_10 (void) __attribute__ ((signal));
void __vector_10 (void)
{
	static u16 ctcCounter=0;
	ctcCounter++;
	
	if(private_ctcCounter == ctcCounter)
	{
		// Clear Counter
		ctcCounter = 0;
		
		// Call Action
		if(private_pCallBackCTC!=NULL)
		{
			private_pCallBackCTC();
		}
	}
}