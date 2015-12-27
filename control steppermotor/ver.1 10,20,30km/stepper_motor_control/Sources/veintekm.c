/*
 * veintekm.c
 *
 *  Created on: Dec 26, 2015
 *      Author: HP 240
 */



#include "MPC5606B.h"
#include "veintekm.h"
#include "led.h"
#include "pb.h"


void veintekm()
{
	
	 if(read_pb(SW_3)== PUSHED)
		  {
		 
		     /*1*/
		     delay_for(1400);
			 led_change_status(LED_1, LED_ON);
			 SIU.GPDO[0].B.PDO = 1;
			 delay_for(1000000);
			 led_change_status(LED_1, LED_OFF);
			 SIU.GPDO[0].B.PDO = 0;
			 
			 delay_for(1400);
			 led_change_status(LED_2, LED_ON);
			 SIU.GPDO[1].B.PDO = 1;
			 delay_for(1000000);
			 led_change_status(LED_2, LED_OFF);
			 SIU.GPDO[1].B.PDO = 0;
			 
			 delay_for(1400);
			 led_change_status(LED_3, LED_ON);
			 SIU.GPDO[2].B.PDO = 1;
			 delay_for(1000000);
			 led_change_status(LED_3, LED_OFF);
			 SIU.GPDO[2].B.PDO = 0;
			 
			 delay_for(1400);
			led_change_status(LED_4, LED_ON);
			SIU.GPDO[3].B.PDO = 1;
			delay_for(1000000);
			led_change_status(LED_4, LED_OFF);
			SIU.GPDO[3].B.PDO = 0;
			
			
			  /*2*/
					     delay_for(1400);
						 led_change_status(LED_1, LED_ON);
						 SIU.GPDO[0].B.PDO = 1;
						 delay_for(1000000);
						 led_change_status(LED_1, LED_OFF);
						 SIU.GPDO[0].B.PDO = 0;
						 
						 delay_for(1400);
						 led_change_status(LED_2, LED_ON);
						 SIU.GPDO[1].B.PDO = 1;
						 delay_for(1000000);
						 led_change_status(LED_2, LED_OFF);
						 SIU.GPDO[1].B.PDO = 0;
						 
						 delay_for(1400);
						 led_change_status(LED_3, LED_ON);
						 SIU.GPDO[2].B.PDO = 1;
						 delay_for(1000000);
						 led_change_status(LED_3, LED_OFF);
						 SIU.GPDO[2].B.PDO = 0;
						 
						 delay_for(1400);
						led_change_status(LED_4, LED_ON);
						SIU.GPDO[3].B.PDO = 1;
						delay_for(1000000);
						led_change_status(LED_4, LED_OFF);
						SIU.GPDO[3].B.PDO = 0;
			 
		  }
	  
}


