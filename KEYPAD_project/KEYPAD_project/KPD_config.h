/*
 * KPD_config.h
 *
 * Created: 10/8/2023 8:22:57 PM
 *  Author: Kareem Hussein
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_COL0_PORT         DIO_PORTA
#define KPD_COL0_PIN          DIO_PIN0
#define KPD_COL1_PORT         DIO_PORTA
#define KPD_COL1_PIN          DIO_PIN1
#define KPD_COL2_PORT         DIO_PORTA
#define KPD_COL2_PIN          DIO_PIN2
#define KPD_COL3_PORT         DIO_PORTA
#define KPD_COL3_PIN          DIO_PIN3


#define KPD_ROW0_PORT         DIO_PORTA    
#define KPD_ROW0_PIN          DIO_PIN4
#define KPD_ROW1_PORT         DIO_PORTA  
#define KPD_ROW1_PIN          DIO_PIN5
#define KPD_ROW2_PORT         DIO_PORTA  
#define KPD_ROW2_PIN          DIO_PIN6
#define KPD_ROW3_PORT         DIO_PORTA  
#define KPD_ROW3_PIN          DIO_PIN7

#define KPD_COL4_PORT         DIO_PORTC
#define KPD_COL4_PIN          DIO_PIN0
#define KPD_COL5_PORT         DIO_PORTC
#define KPD_COL5_PIN          DIO_PIN1
#define KPD_COL6_PORT         DIO_PORTC
#define KPD_COL6_PIN          DIO_PIN2
#define KPD_COL7_PORT         DIO_PORTC
#define KPD_COL7_PIN          DIO_PIN3


#define KPD_ROW4_PORT         DIO_PORTC
#define KPD_ROW4_PIN          DIO_PIN4
#define KPD_ROW5_PORT         DIO_PORTC
#define KPD_ROW5_PIN          DIO_PIN5
#define KPD_ROW6_PORT         DIO_PORTC
#define KPD_ROW6_PIN          DIO_PIN6
#define KPD_ROW7_PORT         DIO_PORTC
#define KPD_ROW7_PIN          DIO_PIN7

#define KPD_COL8_PORT         DIO_PORTB
#define KPD_COL8_PIN          DIO_PIN0
#define KPD_COL9_PORT         DIO_PORTB
#define KPD_COL9_PIN          DIO_PIN1
#define KPD_COL10_PORT        DIO_PORTD
#define KPD_COL10_PIN         DIO_PIN2
#define KPD_COL11_PORT        DIO_PORTD
#define KPD_COL11_PIN         DIO_PIN3


#define KPD_ROW8_PORT         DIO_PORTD
#define KPD_ROW8_PIN          DIO_PIN4
#define KPD_ROW9_PORT         DIO_PORTD
#define KPD_ROW9_PIN          DIO_PIN5
#define KPD_ROW10_PORT        DIO_PORTD
#define KPD_ROW10_PIN         DIO_PIN6
#define KPD_ROW11_PORT        DIO_PORTD
#define KPD_ROW11_PIN         DIO_PIN7


#define KPD_KEYS          {{'1','2','3','A'},\
		                    {'4','5','6','A'},\
							{'7','8','9','A'},\
							{'A','0','B','A'}}
#define KPD_KEYS1          {{'C','D','E','A'},\
	                        {'F','G','H','A'},\
                            {'I','J','K','A'},\
                            {'L','M','N','A'}}
#define KPD_KEYS2          {{'O','P','Q','A'},\
                            {'R','S','T','A'},\
                            {'U','V','W','A'},\
                            {'X','Y','Z','A'}}


#endif /* KPD_CONFIG_H_ */