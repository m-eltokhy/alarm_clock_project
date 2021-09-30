/*
 * timer0.c
 *
 *  Created on: Aug 13, 2021
 *      Author: M.Eltokhy
 */

#include "timer.h"

//void pointers to isr functions
void (*ptf_t0_OVF)(void);
void (*ptf_t0_OCF)(void);
void (*ptf_t1_OVF)(void);
void (*ptf_t1_OCF)(void);
void (*ptf_t2_OVF)(void);
void (*ptf_t2_OCF)(void);

//timer0 initialization
void timer0_init(void) {

	TCCR0 |= timer0_prescaler_mode;

	TCNT0 = TIMER0_init_val;
//	OCR0=TIMER0_OCR_val;

#if timer0_OV_interrupt
	SET_BIT(TIMSK, TOIE0);
#else
	CLEAR_BIT(TIMSK,TOIE0);
#endif

#if timer0_OC_interrupt
	SET_BIT(TIMSK,OCIE0);
#else
	CLEAR_BIT(TIMSK, OCIE0);
#endif

#if timer0_mode == normal
	CLEAR_BIT(TCCR0, WGM00);
	CLEAR_BIT(TCCR0, WGM01);
#elif timer0_mode == pwm
	SET_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
#elif timer0_mode == ctc
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#elif timer0_mode == fast_pwm
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#endif

#if timer0_match_output == disconnected
	CLEAR_BIT(TCCR0, COM00);
	CLEAR_BIT(TCCR0, COM01);
#elif timer0_match_output == toggle
	SET_BIT(TCCR0,COM00);
	CLEAR_BIT(TCCR0,COM01);
#elif timer0_match_output == clear
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif timer0_match_output == set
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif

}

void timer1_init(void) {
	// set up timer with prescaler = 1024 & ctc mode
	TCCR1B |= (1 << WGM12);
	TCCR1B |= 5;

	// initialize counter
	TCNT1 = 0;

	//set ctc value to 1 sec to fire
	OCR1A = 15625;

	// enable output compare A interrupt
	TIMSK |= (1 << OCIE1A);

	//Set OC1A on compare match
	TCCR1A |=(3 << COM1A0);
}

//timer2 initialization
void timer2_init(void) {

	TCCR2 |= timer0_prescaler_mode;

	TCNT2 = TIMER0_init_val;
//	OCR2=TIMER0_OCR_val;

#if timer2_OV_interrupt
	SET_BIT(TIMSK,TOIE2);
#else
	CLEAR_BIT(TIMSK, TOIE2);
#endif

#if timer2_OC_interrupt
	SET_BIT(TIMSK,OCIE2);
#else
	CLEAR_BIT(TIMSK, OCIE2);
#endif

#if timer2_mode == normal
	CLEAR_BIT(TCCR0, WGM20);
	CLEAR_BIT(TCCR0, WGM21);
#elif timer2_mode == pwm
	SET_BIT(TCCR0,WGM20);
	CLEAR_BIT(TCCR0,WGM21);
#elif timer2_mode == ctc
	CLEAR_BIT(TCCR0,WGM20);
	SET_BIT(TCCR0,WGM21);
#elif timer2_mode == fast_pwm
	SET_BIT(TCCR0,WGM20);
	SET_BIT(TCCR0,WGM21);
#endif

#if timer2_match_output == disconnected
	CLEAR_BIT(TCCR0, COM20);
	CLEAR_BIT(TCCR0, COM21);
#elif timer2_match_output == toggle
	SET_BIT(TCCR0,COM20);
	CLEAR_BIT(TCCR0,COM21);
#elif timer2_match_output == clear
	CLEAR_BIT(TCCR0,COM20);
	SET_BIT(TCCR0,COM21);
#elif timer2_match_output == set
	SET_BIT(TCCR0,COM20);
	SET_BIT(TCCR0,COM21);
#endif

}

//callback function for overflow of timer0
void setcallback_T0_TOV(void (*ptf)(void)) {
	ptf_t0_OVF = ptf;
}

//callback function for compare match of timer0
void setcallback_T0_OCF(void (*ptf)(void)) {
	ptf_t0_OCF = ptf;
}

//callback function for overflow of timer1
void setcallback_T1_TOV(void (*ptf)(void)) {
	ptf_t1_OVF = ptf;
}

//callback function for compare match of timer1
void setcallback_T1_OCF(void (*ptf)(void)) {
	ptf_t1_OCF = ptf;
}

//callback function for overflow of timer2
void setcallback_T2_TOV(void (*ptf)(void)) {
	ptf_t2_OVF = ptf;
}

//callback function for compare match of timer2
void setcallback_T2_OCF(void (*ptf)(void)) {
	ptf_t2_OCF = ptf;
}

ISR(TIMER0_OVF_vect) {
	ptf_t0_OVF();
}

ISR(TIMER0_COMP_vect) {
	ptf_t0_OCF();
}

ISR(TIMER1_OVF_vect) {
	ptf_t1_OVF();
}

ISR(TIMER1_COMPA_vect) {
	ptf_t1_OCF();
}

ISR(TIMER2_OVF_vect) {
	ptf_t2_OVF();
}

ISR(TIMER2_COMP_vect) {
	ptf_t2_OCF();
}
