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

	int operacion = LEFT_DOOR_OPEN;
	
	switch(operacion){
	
	case LEFT_DOOR_CLOSED : 
		
		SIU.GPDO[LEFT_DOOR_CLOSED].B.PDO = 0;
			
		break;
		
	case LEFT_DOOR_OPEN: 
		
		SIU.GPDO[LEFT_DOOR_OPEN].B.PDO = 1;
			
		break;
		
	case 2: 
			
				SIU.GPDO[2].B.PDO = 1;//engine fault
				
			break;
			
	case 3: 
			
				SIU.GPDO[3].B.PDO = 1;//Chest
				
			break;
		
	case 4: 
			
				SIU.GPDO[4].B.PDO = 1;//right door
				
			break;
			
	case 5: 
			
				SIU.GPDO[5].B.PDO = 1;//temperature
				
			break;
			
			
	case 6: 
			
				SIU.GPDO[6].B.PDO = 1;//high lights
				
			break;
			
			
	case 7: 
			
				SIU.GPDO[7].B.PDO = 1;//oil
				
			break;
		
	}

}



void diez_pasos()
{


	
	
}


void veinte_pasos()
{
	
	
	  
}














