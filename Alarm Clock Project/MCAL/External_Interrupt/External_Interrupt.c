/*
 * External_Interrupt.c
 *
 *  Created on: Aug 6, 2021
 *      Author: M.Eltokhy
 */

#include "External_Interrupt.h"

void (*ptf0)(void);
void (*ptf1)(void);
void (*ptf2)(void);

void EXTI_init(void){
//	if(EXTI_INT0){
//		SET_BIT(GICR,INT0);
//		MCUCR|=INT0_TRIG;
//	}else{
//		CLEAR_BIT(GICR,INT0);
//	}
#if EXTI_INT0 == ENABLED
	SET_BIT(GICR,INT0);
	MCUCR|=INT0_TRIG;
#else
	CLEAR_BIT(GICR,INT0);
#endif
//	if(EXTI_INT1){
//		SET_BIT(GICR,INT1);
//		MCUCR|=(INT1_TRIG<<2);
//	}else{
//		CLEAR_BIT(GICR,INT1);
//	}
#if EXTI_INT1 == ENABLED
	SET_BIT(GICR,INT1);
	MCUCR|=(INT1_TRIG<<2);
#else
	CLEAR_BIT(GICR,INT1);
#endif
//	if (EXTI_INT2) {
//		SET_BIT(GICR, INT2);
//		if (INT2_TRIG % 2) {
//			SET_BIT(MCUCSR, 6);
//		} else {
//			CLEAR_BIT(MCUCSR, 6);
//		}
//	} else {
//		CLEAR_BIT(GICR, INT2);
//	}
#if EXTI_INT2 == ENABLED
	SET_BIT(GICR,INT2);
#if (INT2_TRIG % 2) == 1
	SET_BIT(MCUCSR, 6);
#else
	CLEAR_BIT(GICR, INT2);
#endif
#else
	CLEAR_BIT(GICR,INT2);
#endif
}

void call_back_INT0(void (*callback)(void)){
	ptf0=callback;
}
void call_back_INT1(void (*callback)(void)){
	ptf1=callback;
}
void call_back_INT2(void (*callback)(void)){
	ptf2=callback;
}

ISR(INT0_vect){
	ptf0();
}
ISR(INT1_vect){
	ptf1();
}
ISR(INT2_vect){
	ptf2();
}
