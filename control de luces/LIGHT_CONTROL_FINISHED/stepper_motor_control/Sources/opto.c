/*
 * diezkm.c
 *
 *  Created on: Dec 26, 2015
 *      Author: HP 240
 */

#include "MPC5606B.h"
#include "opto.h"
#include "led.h"
#include "pb.h"



 

//porta [0..15] portb [16...31] 
//SIU.GPDO[11].B.PDO = 1;	

void opto()//opto
{

	int operacion = RIGHT_DOOR_OPEN;
	
	switch(operacion){
	
	case LEFT_DOOR_CLOSED: 
		
		SIU.GPDO[LEFT_DOOR].B.PDO = TURN_OFF;
			
		break;
		
	case LEFT_DOOR_OPEN: 
		
		SIU.GPDO[LEFT_DOOR].B.PDO = TURN_ON;
			
		break;
		
	case ENGINE_FAULT_OFF: 
			
		SIU.GPDO[ENGINE_FAULT].B.PDO = TURN_OFF;
				
		break;
			
	case ENGINE_FAULT_ON: 
			
		SIU.GPDO[ENGINE_FAULT].B.PDO = TURN_ON;
				
		break;
		
	case CHEST_CLOSED: 
			
		SIU.GPDO[CHEST].B.PDO = TURN_OFF;
				
		break;
			
	case CHEST_OPEN: 
			
		SIU.GPDO[CHEST].B.PDO = TURN_ON;
				
		break;
			
			
	case RIGHT_DOOR_CLOSED: 
			
		SIU.GPDO[RIGHT_DOOR].B.PDO = TURN_OFF;
				
		break;
			
			
	case RIGHT_DOOR_OPEN: 
			
		SIU.GPDO[RIGHT_DOOR].B.PDO =  TURN_ON;
				
		break;
		
	}

}



void diez_pasos()
{


	
	
}


void veinte_pasos()
{
	
	
	  
}














