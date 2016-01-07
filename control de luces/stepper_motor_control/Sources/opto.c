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
int avanza_10km = 0;
int telltale1 = 1;
int telltale2 = 1;
int telltale3 = 1;
int telltale4 = 1;
int telltale5 = 1;
int telltale6 = 1;
int telltale7 = 1;
int telltale8 = 1;
int telltale9 = 1;
int telltale10 = 1;



void opto()//opto
{
	do{
		/*
		opto_position_zero = 0;
		SIU.GPDO[11].B.PDO = 1;		
		
		
		SIU.GPDO[1].B.PDO = 1;
			SIU.GPDO[2].B.PDO = 1;
			SIU.GPDO[0].B.PDO = 1;
			SIU.GPDO[3].B.PDO = 1;
			SIU.GPDO[4].B.PDO = 1;
			SIU.GPDO[5].B.PDO = 1;
			SIU.GPDO[6].B.PDO = 1;
			SIU.GPDO[7].B.PDO = 1;
			SIU.GPDO[8].B.PDO = 1;
			SIU.GPDO[9].B.PDO = 1;
			SIU.GPDO[10].B.PDO = 1;
			SIU.GPDO[12].B.PDO = 1;
			SIU.GPDO[13].B.PDO = 1;
			SIU.GPDO[14].B.PDO = 1;
			SIU.GPDO[15].B.PDO = 1;
			
			
			
			
			//portb
			SIU.GPDO[16].B.PDO = 1;
			SIU.GPDO[17].B.PDO = 1;
			SIU.GPDO[18].B.PDO = 1;
			SIU.GPDO[19].B.PDO = 1;
			SIU.GPDO[20].B.PDO = 1;
			SIU.GPDO[21].B.PDO = 1;
			SIU.GPDO[22].B.PDO = 1;
			SIU.GPDO[23].B.PDO = 1;
			SIU.GPDO[24].B.PDO = 1;
			SIU.GPDO[25].B.PDO = 1;
			SIU.GPDO[26].B.PDO = 1;
			SIU.GPDO[27].B.PDO = 1;
			SIU.GPDO[28].B.PDO = 1;
			SIU.GPDO[29].B.PDO = 1;
			SIU.GPDO[30].B.PDO = 1;
			SIU.GPDO[31].B.PDO = 1;
		
		*/
		if(vel1 == 1){
			SIU.GPDO[0].B.PDO = 1;
			
		}
		
		
		
	}while(read_pb(SW_1)== UNPUSHED);
	
	if(read_pb(SW_1)== PUSHED){
		/*
		opto_position_zero = 1;
		SIU.GPDO[11].B.PDO = 1;
		SIU.GPDO[1].B.PDO = 1;
		SIU.GPDO[2].B.PDO = 1;
		SIU.GPDO[0].B.PDO = 1;
		SIU.GPDO[3].B.PDO = 1;
		SIU.GPDO[4].B.PDO = 1;
		SIU.GPDO[5].B.PDO = 1;
		SIU.GPDO[6].B.PDO = 1;
		SIU.GPDO[7].B.PDO = 1;
		SIU.GPDO[8].B.PDO = 1;
		SIU.GPDO[9].B.PDO = 1;
		SIU.GPDO[10].B.PDO = 1;
		SIU.GPDO[12].B.PDO = 1;
		SIU.GPDO[13].B.PDO = 1;
		SIU.GPDO[14].B.PDO = 1;
		SIU.GPDO[15].B.PDO = 1;
		*/
	}
	
	
	
}



void diez_pasos()//diezkm
{


	
	
	 if(read_pb(SW_2)== PUSHED && opto_position_zero == 1)
		  {
		 
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


void veinte_pasos()//20km
{
	
	 if(read_pb(SW_3)== PUSHED && opto_position_zero == 1)
		  {
		 
		    
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














