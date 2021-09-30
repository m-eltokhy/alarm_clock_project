/*
 * lcd.h
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "../../MCAL/DIO/dio.h"

void lcd_init(void);
void lcd_cmd(uint8);
void lcd_data(uint8);
void lcd_string(uint8*);
void lcd_show_clock(uint8*);

typedef enum{
	off,on
}alarm_status;


#endif /* HAL_LCD_LCD_H_ */
