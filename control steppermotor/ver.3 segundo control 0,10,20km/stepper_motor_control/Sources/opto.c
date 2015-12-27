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

int opto_position_zero = 0;
int position_10km = 0;
int position_20km = 0;

void opto()//opto
{
	/*opto*/
	 if(read_pb(SW_1)== PUSHED )
		  {
		 opto_position_zero = 1;
		 SIU.GPDO[11].B.PDO = 1;
		 
		  }
}


void diez_pasos()//diezkm
{
	
	 if(read_pb(SW_3)== PUSHED && opto_position_zero == 1)
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
			
			position_10km = 1;
			
		  }
	  
}


void veinte_pasos()//diezkm
{
	
	 if(read_pb(SW_4)== PUSHED && opto_position_zero == 1)
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
			
			position_20km = 1;
			
		  }
	  
}

















