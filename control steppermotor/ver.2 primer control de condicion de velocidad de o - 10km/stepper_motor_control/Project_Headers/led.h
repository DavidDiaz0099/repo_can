/*
 * led.h
 *
 *  Created on: Dec 23, 2015
 *      Author: HP 240
 */


#ifndef LED_H_
#define LED_H_

#define LED_ON 		0
#define LED_OFF		1

#define LED_1		68
#define LED_2		69
#define LED_3		70
#define LED_4		71

void delay_for( int num);
void led_sysclk_init_fnc(void);
void led_change_status(char ch, char led_state);

#endif /* LED_H_ */
