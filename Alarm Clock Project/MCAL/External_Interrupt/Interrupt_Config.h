/*
 * Interrupt_Config.h
 *
 *  Created on: Aug 6, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_INTERRUPT_CONFIG_H_
#define MCAL_EXTERNAL_INTERRUPT_INTERRUPT_CONFIG_H_


#define DISABLED 	0
#define ENABLED 	1

#define EXTI_INT0	ENABLED
#define EXTI_INT1	DISABLED
#define EXTI_INT2	DISABLED

#define Low_Level		0
#define Both_edges		1
#define Falling_edge	2
#define Rising_edge		3

#define INT0_TRIG	Rising_edge
#define INT1_TRIG	Both_edges
#define INT2_TRIG	Falling_edge

#endif /* MCAL_EXTERNAL_INTERRUPT_INTERRUPT_CONFIG_H_ */
