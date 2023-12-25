/*
 * ADC_program.c
 *
 * Created: 10/15/2023 9:58:44 PM
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* MCAL */
#include "ADC_interface.h"
#include "ADC_private.h"


void ADC_init(u8 referenceVolt)
{
	switch(referenceVolt)
	{
		// Select Vref = AVCC
		case ADC_REFERENCE_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		// Select Vref = AREF
		case ADC_REFERENCE_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		// Select Vref = 2.56V internal
		case ADC_REFERENCE_INTERNAL:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	// Select Right AdjustmentS
	CLR_BIT(ADMUX,ADLAR);
	
	// Single Conversation Mode
	CLR_BIT(ADCSRA,ADATE);
	
	// Disable ADC Interrupt
	CLR_BIT(ADCSRA,ADIE);
	
	// Prescaler 128 For 16MHZ (125 KHZ)
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	// ADC Enable
	SET_BIT(ADCSRA,ADEN);
}


void ADC_getDigitalValue(u8 channelNum, u16* digitalValue)
{
	if((channelNum<32)&&(digitalValue!=NULL))
	{
		//Clear ADMUX Channel Bits
	    ADMUX &= 0xE0; //0b11100000
	        
	    // Select Channel Number
	    ADMUX |= channelNum;
		
	    // Start Conversition
		SET_BIT(ADCSRA,ADSC);
		
		// Busy wait
		while(0 == GET_BIT(ADCSRA,ADIF));
		
		// Clear Flag(write one to clear)
		SET_BIT(ADCSRA,ADIF);
		
		// Read digital value from ADC data reg.
		*digitalValue = ADC_u16;
	}
}