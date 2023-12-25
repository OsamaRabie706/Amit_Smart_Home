/*
 * UART_interface.h
 *
 * Created: 10/31/2023 11:01:52 PM
 *  Author: Kareem Hussein
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_init  (void);
void UART_TxChar(u8 TxData);
void UART_RxChar(u8* RxData);


#endif /* UART_INTERFACE_H_ */