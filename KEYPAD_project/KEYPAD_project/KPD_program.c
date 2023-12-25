/*
 * KPD_program.c
 *
 * Created: 10/8/2023 8:22:35 PM
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
 
/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"


void KPD_init(void)
{
	//COLS >> output
	DIO_setPinDirection(KPD_COL0_PORT, KPD_COL0_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL1_PORT, KPD_COL1_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL2_PORT, KPD_COL2_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL3_PORT, KPD_COL3_PIN, DIO_PIN_OUTPUT);
	
	//ROWS >> input
	DIO_setPinDirection(KPD_ROW0_PORT, KPD_ROW0_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW1_PORT, KPD_ROW1_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW2_PORT, KPD_ROW2_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW3_PORT, KPD_ROW3_PIN, DIO_PIN_INPUT);
	
	//active internal pull up (ROWS initial value are ones)
	DIO_activePinInPullUpResistance(KPD_ROW0_PORT, KPD_ROW0_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW1_PORT, KPD_ROW1_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW2_PORT, KPD_ROW2_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW3_PORT, KPD_ROW3_PIN);
	
	//COLS >> output
	DIO_setPinDirection(KPD_COL4_PORT, KPD_COL4_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL5_PORT, KPD_COL5_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL6_PORT, KPD_COL6_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL7_PORT, KPD_COL7_PIN, DIO_PIN_OUTPUT);
	
	//ROWS >> input
	DIO_setPinDirection(KPD_ROW4_PORT, KPD_ROW4_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW5_PORT, KPD_ROW5_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW6_PORT, KPD_ROW6_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW7_PORT, KPD_ROW7_PIN, DIO_PIN_INPUT);
	
	//active internal pull up (ROWS initial value are ones)
	DIO_activePinInPullUpResistance(KPD_ROW4_PORT, KPD_ROW4_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW5_PORT, KPD_ROW5_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW6_PORT, KPD_ROW6_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW7_PORT, KPD_ROW7_PIN);
	
	//COLS >> output
	DIO_setPinDirection(KPD_COL8_PORT, KPD_COL8_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL9_PORT, KPD_COL9_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL10_PORT, KPD_COL10_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL11_PORT, KPD_COL11_PIN, DIO_PIN_OUTPUT);
	
	//ROWS >> input
	DIO_setPinDirection(KPD_ROW8_PORT, KPD_ROW8_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW9_PORT, KPD_ROW9_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW10_PORT, KPD_ROW10_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW11_PORT, KPD_ROW11_PIN, DIO_PIN_INPUT);
	
	//active internal pull up (ROWS initial value are ones)
	DIO_activePinInPullUpResistance(KPD_ROW8_PORT, KPD_ROW8_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW9_PORT, KPD_ROW9_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW10_PORT, KPD_ROW10_PIN);
	DIO_activePinInPullUpResistance(KPD_ROW11_PORT, KPD_ROW11_PIN);
} 


void KPD_getValue(u8* returnedValue)
{
	if(returnedValue != NULL)
	{
		*returnedValue = KPD_NOT_PRESSED;
		
		u8 colsPorts[4]={KPD_COL0_PORT, KPD_COL1_PORT, KPD_COL2_PORT, KPD_COL3_PORT};
		u8 colsPins [4]={KPD_COL0_PIN , KPD_COL1_PIN , KPD_COL2_PIN , KPD_COL3_PIN};
		u8 rowsPorts[4]={KPD_ROW0_PORT, KPD_ROW1_PORT, KPD_ROW2_PORT, KPD_ROW3_PORT};
		u8 rowsPins [4]={KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};
		u8 kpdKeys[4][4] = KPD_KEYS;
		
		u8 colsPorts1[4]={KPD_COL4_PORT, KPD_COL5_PORT, KPD_COL6_PORT, KPD_COL7_PORT};
		u8 colsPins1 [4]={KPD_COL4_PIN , KPD_COL5_PIN , KPD_COL6_PIN , KPD_COL7_PIN};
		u8 rowsPorts1[4]={KPD_ROW4_PORT, KPD_ROW5_PORT, KPD_ROW6_PORT, KPD_ROW7_PORT};
		u8 rowsPins1 [4]={KPD_ROW4_PIN , KPD_ROW5_PIN , KPD_ROW6_PIN , KPD_ROW7_PIN};
		u8 kpdKeys1[4][4] = KPD_KEYS1;
		
		u8 colsPorts2[4]={KPD_COL8_PORT, KPD_COL9_PORT, KPD_COL10_PORT, KPD_COL11_PORT};
		u8 colsPins2 [4]={KPD_COL8_PIN , KPD_COL9_PIN , KPD_COL10_PIN , KPD_COL11_PIN};
		u8 rowsPorts2[4]={KPD_ROW8_PORT, KPD_ROW9_PORT, KPD_ROW10_PORT, KPD_ROW11_PORT};
		u8 rowsPins2 [4]={KPD_ROW8_PIN , KPD_ROW9_PIN , KPD_ROW10_PIN , KPD_ROW11_PIN};
		u8 kpdKeys2[4][4] = KPD_KEYS2;
		
		u8 colsCounter,rowsCounter;
		u8 pinValue;
		
		for(colsCounter=0;colsCounter<4;colsCounter++)
		{
			//Activate Each Coloumn
			DIO_setPinValue(colsPorts[colsCounter],colsPins[colsCounter],DIO_PIN_LOW);
			
			
			for(rowsCounter=0;rowsCounter<4;rowsCounter++)
			{
				//Read Each Row 
				DIO_getPinValue(rowsPorts[rowsCounter],rowsPins[rowsCounter],&pinValue);
				
				//Is Pressed?
				if(0 == pinValue)
				{
					while(0 == pinValue)
					{
						DIO_getPinValue(rowsPorts[rowsCounter],rowsPins[rowsCounter],&pinValue);
					}
					
					*returnedValue = kpdKeys[rowsCounter][colsCounter];
					return;
				}
			}
			
			//Deactivate Current Coloumn 
			DIO_setPinValue(colsPorts[colsCounter],colsPins[colsCounter],DIO_PIN_HIGH);
		}
		
		for(colsCounter=0;colsCounter<4;colsCounter++)
		{
			//Activate Each Coloumn
			DIO_setPinValue(colsPorts1[colsCounter],colsPins1[colsCounter],DIO_PIN_LOW);
			
			
			for(rowsCounter=0;rowsCounter<4;rowsCounter++)
			{
				//Read Each Row
				DIO_getPinValue(rowsPorts1[rowsCounter],rowsPins1[rowsCounter],&pinValue);
				
				//Is Pressed?
				if(0 == pinValue)
				{
					while(0 == pinValue)
					{
						DIO_getPinValue(rowsPorts1[rowsCounter],rowsPins1[rowsCounter],&pinValue);
					}
					
					*returnedValue = kpdKeys1[rowsCounter][colsCounter];
					return;
				}
			}
			
			//Deactivate Current Coloumn
			DIO_setPinValue(colsPorts1[colsCounter],colsPins1[colsCounter],DIO_PIN_HIGH);
		}
		
		for(colsCounter=0;colsCounter<4;colsCounter++)
		{
			//Activate Each Coloumn
			DIO_setPinValue(colsPorts2[colsCounter],colsPins2[colsCounter],DIO_PIN_LOW);
			
			
			for(rowsCounter=0;rowsCounter<4;rowsCounter++)
			{
				//Read Each Row
				DIO_getPinValue(rowsPorts2[rowsCounter],rowsPins2[rowsCounter],&pinValue);
				
				//Is Pressed?
				if(0 == pinValue)
				{
					while(0 == pinValue)
					{
						DIO_getPinValue(rowsPorts2[rowsCounter],rowsPins2[rowsCounter],&pinValue);
					}
					
					*returnedValue = kpdKeys2[rowsCounter][colsCounter];
					return;
				}
			}
			
			//Deactivate Current Coloumn
			DIO_setPinValue(colsPorts2[colsCounter],colsPins2[colsCounter],DIO_PIN_HIGH);
		}
	}
}