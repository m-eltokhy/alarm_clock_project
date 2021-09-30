/*
 * dio.c
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#include "dio.h"

void dio_init(void) {
	DDRA = 0xFF;
	DDRB = 0x07;
	SET_BIT(DDRB,4);
}

void dio_write(Dio_Pins Pin, Dio_Status status) {
	Dio_Ports port = Pin / 8;
	uint8 T_pin = Pin % 8;
	switch (port) {
	case port_A:
		if (status) {
			SET_BIT(PORTA, T_pin);
		} else {
			CLEAR_BIT(PORTA, T_pin);
		}
		break;
	case port_B:
		if (status) {
			SET_BIT(PORTB, T_pin);
		} else {
			CLEAR_BIT(PORTB, T_pin);
		}
		break;
	case port_C:
		if (status) {
			SET_BIT(PORTC, T_pin);
		} else {
			CLEAR_BIT(PORTC, T_pin);
		}
		break;
	case port_D:
		if (status) {
			SET_BIT(PORTD, T_pin);
		} else {
			CLEAR_BIT(PORTD, T_pin);
		}
		break;
	}
}

Dio_Status dio_read(Dio_Pins Pin){
	Dio_Ports port = Pin / 8;
	uint8 T_pin = Pin % 8;
	switch (port) {
		case port_A:
			return GET_BIT(PINA,T_pin);
			break;
		case port_B:
			return GET_BIT(PINB,T_pin);
			break;
		case port_C:
			return GET_BIT(PINC,T_pin);
			break;
		case port_D:
			return GET_BIT(PIND,T_pin);
			break;
		}
	return 0;
}
