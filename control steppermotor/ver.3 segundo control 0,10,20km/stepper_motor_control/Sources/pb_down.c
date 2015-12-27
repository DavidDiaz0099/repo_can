/*
 * pb_down.c
 *
 *  Created on: Dec 23, 2015
 *      Author: HP 240
 */

#include "led.h"
#include "pb.h"
#include "pb_down.h"
#include "MPC5606B.h"

int co = 0 ;
int valid = 0;
int count_ms;
int band_vpress = 0;
int count2;

void pb_down()
{
	
	if(read_pb(SW_1)== PUSHED)
		  	  {
		
		  		co = 1;
		  		SIU.GPDO[8].B.PDO = 1;
		  	  }
	
	if(read_pb(SW_1)== UNPUSHED && co==1)
			  	  {
		
			  		 valid = 1;
			  		
			  	  }
	if(valid == 1 && read_pb(SW_1)== PUSHED )
				  	  {
		                delay_for(4000000000);
		                co = 2;
				  		SIU.GPDO[9].B.PDO = 1;
				  		
				  	  }
}



	
					/*
	                  do
					  {
						  if(read_pb(SW_1)== PUSHED)
						  {
							  count_ms++;
							  count2++;
							  STM.CNT.R = 0;                         //Reset the counter
							  STM.CH[0].CIR.B.CIF = 1;              //Clean channel 0
						  }
						  
					  }while(read_pb(SW_1)== PUSHED && count_ms<10);
					  
					  if(count_ms >= 10){
						  band_vpress = 1;
					
					  }
					  if( band_vpress==1 && read_pb(SW_1)== UNPUSHED)
					  {
						  SIU.GPDO[9].B.PDO = 1;
					 }
					  */
	                 
	  

