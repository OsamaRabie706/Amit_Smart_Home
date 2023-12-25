/*
 * LCD_interface.h
 *
 * Created: 10/3/2023 7:31:30 PM
 *  Author: AMIT
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Macros For LCD Line Id */
#define LCD_LINE_ONE            1
#define LCD_LINE_TWO            2

/* Macros For LCD Shifting Direction */
#define LCD_SHIFT_LEFT          1
#define LCD_SHIFT_RIGHT         2


void LCD_init                (void);
void LCD_sendCmnd            (u8 cmnd);
void LCD_sendChar            (u8 data);
void LCD_writeString         (u8* string);
void LCD_clear               (void);
void LCD_goToSpecificPosition(u8 lineNumber, u8 Position);
void LCD_shift               (u8 shiftDirection);


/*
void LCD_writeNumber         (u32 number); //convert int to string
*/


#endif /* LCD_INTERFACE_H_ */