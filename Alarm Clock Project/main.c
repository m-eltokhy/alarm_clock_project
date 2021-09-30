/*
 * main.c
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#include "MCAL/DIO/dio.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/External_Interrupt/External_Interrupt.h"
#include "MCAL/Timer/timer.h"

uint8 time[3]={5,59,45},alarm_time[3]={6,0,0};
alarm_status alarm=off;

void alarm_toggle(void);
void print_lcd(void);
uint8 check_time(void);

int main(){
	dio_init();
	setcallback_T1_OCF(print_lcd);
	call_back_INT0(alarm_toggle);
	lcd_init();
	EXTI_init();
	timer1_init();
	sei();
	while(1){
		lcd_show_clock(time);
		lcd_string(" ALM:\n");
		(alarm)?lcd_string("ON \n"):lcd_string("OFF\n");
		lcd_cmd(0xC0);
		lcd_string("ALARM: \n");
		lcd_show_clock(alarm_time);
		if(check_time() && alarm){
			dio_write(led1, high);
		}
		if(dio_read(Button_1)){
			alarm_time[0]++;
			if(alarm_time[0]==24){
				alarm_time[0]=0;
			}
		}
		if(dio_read(Button_2)){
			alarm_time[1]++;
			if(alarm_time[1]==60){
				alarm_time[1]=0;
			}
		}
		if(dio_read(Button_3)){
			alarm_time[2]++;
			if(alarm_time[1]==60){
				alarm_time[1]=0;
			}
		}
		lcd_cmd(0x02);
	}
	return 0;
}

void alarm_toggle(void){
	alarm=!alarm;
}

void print_lcd(void){
	time[2]++;
	if(time[2]==60){
		time[2]=0;
		time[1]++;
	}
	if(time[1]==60){
		time[1]=0;
		time[0]++;
	}
	if(time[0]==24){
		time[0]=0;
	}
}

uint8 check_time(void){
	for(uint8 i=0;i<3;i++){
		if(time[i]!=alarm_time[i]){
			return 0;
		}
	}
	return 1;
}
