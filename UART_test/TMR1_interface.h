/*
 * TMR1_interface.h
 *
 * Created: 10/29/2023 8:51:44 PM
 *  Author: Kareem Hussein
 */ 


#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_


              /*************** APIS PROTOTYPES ***************/


void TMR1_init                 (void);
void TMR1_start                (void);
void TMR1_stop                 (void); 
void TMR1_setCompareMatchValueA(u16 compareValue);


#endif /* TMR1_INTERFACE_H_ */