/*
 * timer0_config.h
 *
 *  Created on: Aug 13, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

#define TIMER0_init_val 0
#define TIMER0_OCR_val 	127
#define TIMER2_init_val 0
#define TIMER2_OCR_val 	127

#define disable	0
#define enable	1

#define timer0_OV_interrupt enable
#define timer0_OC_interrupt disable
#define timer2_OV_interrupt disable
#define timer2_OC_interrupt disable

#define normal 		0
#define pwm 		1
#define ctc			2
#define fast_pwm	3

#define timer0_mode normal
#define timer2_mode normal

#define disconnected 	0
#define toggle			1
#define clear			2
#define set				3

#define	timer0_match_output	disconnected
#define	timer2_match_output	disconnected

#define no_clk_source		0
#define no_prescaler		1
#define prescaler_8			2
#define prescaler_64		3
#define prescaler_256		4
#define prescaler_1024		5
#define T0_falling_edge		6
#define T0_rising_edge		7

#define timer0_prescaler_mode prescaler_1024
#define timer2_prescaler_mode prescaler_1024

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
