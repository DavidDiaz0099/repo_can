/*
 * application.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Frank
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** Variable types and common definitions */

#include "typedefs.h"
#include "Can.h"
#include "Can_Manager.h"


/*-- Variables ---------------------------------------------------------------*/
extern uint8_t Veh_speed_status;  //B0

extern uint8_t Increase_ACK;  //MSB B0
extern uint8_t Odometer_Value; //LSB B1

extern uint8_t TNK_MSB;   //MSB B0
extern uint8_t TNK_LSB;    // LSB  B1
extern uint8_t GAS_Status; // B2

extern uint8_t Door_Status;   //B0
extern uint8_t High_Beams_Status; //B1
extern uint8_t HandBrake_Status; //B2

extern uint8_t Seatbelt_Status; //B0
extern uint8_t Ign_Status;     //B0
extern uint8_t Gearbox_Status; //B0

extern uint8_t Rpm_status;
extern uint8_t Directional_Status;
extern uint8_t Temp_high_Status;

extern uint8_t Gas_low_Status;
extern uint8_t Oil_low_Status;
extern uint8_t High_beams_Status;
extern uint8_t Hand_break_Status;
extern uint8_t Battery_Status; 
extern uint8_t Door_open_Status;
extern uint8_t Seatbeltn_Status;
extern uint8_t Direction_left_Status;
extern uint8_t Direction_right_Status;


/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/


/*-- Function Prototypes -----------------------------------------------------*/
void t (int no);
void j(int num);

void application();




#endif /* APPLICATION_H_ */
