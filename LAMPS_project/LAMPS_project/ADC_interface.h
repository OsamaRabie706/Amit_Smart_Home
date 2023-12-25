/*
 * ADC_interface.h
 *
 * Created: 10/15/2023 9:58:56 PM
 *  Author: Kareem Hussein
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/* Options for ADC channel single ended inputs*/
#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7


/* Options for max. voltage */
#define ADC_REFERENCE_AVCC      1
#define ADC_REFERENCE_AREF      2
#define ADC_REFERENCE_INTERNAL  3


              /*************** APIS PROTOTYPES ***************/

void ADC_init           (u8 referenceVolt);
void ADC_getDigitalValue(u8 channelNum, u16* digitalValue);


#endif /* ADC_INTERFACE_H_ */