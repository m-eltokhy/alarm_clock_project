/*
 * timer0.h
 *
 *  Created on: Aug 13, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "timer_config.h"

void timer0_init(void);
void timer1_init(void);
void timer2_init(void);
void setcallback_T0_TOV(void (*ptf)(void));
void setcallback_T0_OCF(void (*ptf)(void));
void setcallback_T1_TOV(void (*ptf)(void));
void setcallback_T1_OCF(void (*ptf)(void));
void setcallback_T2_TOV(void (*ptf)(void));
void setcallback_T2_OCF(void (*ptf)(void));

#endif /* MCAL_TIMER_TIMER_H_ */
