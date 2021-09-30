/*
 * dio_types.h
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

#include "../../STD_TYPES.h"

typedef enum {
	low,high
}Dio_Status;

typedef enum {
	input,output
}Dio_Direction;

typedef enum {
	port_A,port_B,port_C,port_D
}Dio_Ports;

typedef enum {
	D0,D1,D2,D3,D4,D5,D6,D7,RS,RW,E,led1=12,Button_1,Button_2,Button_3
}Dio_Pins;

typedef struct {
	Dio_Ports port;
	unsigned char pin;
	Dio_Direction direction;
}Dio_init_types;


#endif /* MCAL_DIO_DIO_TYPES_H_ */
