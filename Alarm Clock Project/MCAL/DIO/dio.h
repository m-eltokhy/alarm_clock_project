/*
 * dio.h
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "dio_types.h"

void dio_init(void);
void dio_write(Dio_Pins,Dio_Status);
Dio_Status dio_read(Dio_Pins);

#endif /* MCAL_DIO_DIO_H_ */
