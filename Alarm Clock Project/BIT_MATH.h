/*
 * BIT_MATH.h
 *
 *  Created on: Jul 17, 2021
 *      Author: M.Eltokhy
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(port,n) 	port|=(1<<n)
#define CLEAR_BIT(port,n) 	port&=~(1<<n)
#define TOGGLE_BIT(port,n) 	port^=(1<<n)
#define GET_BIT(port,n) 	(port&(1<<n))

#endif /* BIT_MATH_H_ */
