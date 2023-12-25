/*
 * TWI_interface.h
 *
 * Created: 11/7/2023 10:17:16 PM
 *  Author: Kareem Hussein
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


void TWI_initMaster                   (void);
void TWI_sendStartCondition           (void);
void TWI_sendRepStartCondition        (void);
void TWI_sendStopCondition            (void);
void TWI_sendSlaveAddWithWrite        (u8 slaveAdd);
void TWI_sendSlaveAddWithRead         (u8 slaveAdd);
void TWI_sendMasterDataByte           (u8 TxData);
void TWI_receiveMasterDataByteWithAck (u8* RxData); 
void TWI_receiveMasterDataByteWithNack(u8* RxData); 


#endif /* TWI_INTERFACE_H_ */