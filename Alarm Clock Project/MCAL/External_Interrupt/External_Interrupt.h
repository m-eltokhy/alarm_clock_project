/*
 * External_Interrupt.h
 *
 *  Created on: Aug 6, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_

#include <avr/interrupt.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "Interrupt_Config.h"

void EXTI_init(void);
void call_back_INT0(void (*callback)(void));
void call_back_INT1(void (*callback)(void));
void call_back_INT2(void (*callback)(void));

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_ */
