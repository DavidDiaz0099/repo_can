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
 extern uint8_t acteng_msb;  //B0
 extern uint8_t acteng_lsb;  //B1

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
 
 


/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/


/*-- Function Prototypes -----------------------------------------------------*/

void application();


#endif /* APPLICATION_H_ */
