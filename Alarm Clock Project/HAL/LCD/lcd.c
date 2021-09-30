/*
 * lcd.c
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#include "lcd.h"

void lcd_init(void){
	_delay_ms(100);
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x06);

}

void lcd_cmd(uint8 cmd){
	dio_write(RS, low);
	PORTA=cmd;
	dio_write(E, high);
	_delay_ms(3);
	dio_write(E, low);
	_delay_ms(100);
}

void lcd_data(uint8 data){
	dio_write(RS, high);
	PORTA=data;
	dio_write(E, high);
	_delay_ms(3);
	dio_write(E, low);
	_delay_us(10);
}

void lcd_string(uint8 *str){
	uint8 ctr=0;
	while(str[ctr]!='\n'){
		lcd_data(str[ctr]);
		ctr++;
	}
}

void lcd_show_clock(uint8 *arr){
	for(uint8 i=0;i<3;i++){
		lcd_data((arr[i]/10)+'0');
		lcd_data((arr[i]%10)+'0');
		if(i!=2){
			lcd_data(':');
		}
	}
}
