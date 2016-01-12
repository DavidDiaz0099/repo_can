/*
 * pb.h
 *
 *  Created on: Dec 23, 2015
 *      Author: HP 240
 */


#ifndef PB_H_
#define PB_H_

#define PUSHED		1
#define UNPUSHED	0

#define SW_1		64
#define SW_2		65
#define SW_3		66
#define SW_4		67


void pb_sysclk_init_fnc(void);
char read_pb(char ch);

#endif /* PUSH_B_H_ */
