/*
 * pb.c
 *
 *  Created on: Dec 23, 2015
 *      Author: HP 240
 */


#include "pb.h"
#include "MPC5606B.h"

char read_pb(char ch)
{
	char value = 0;
	value = SIU.GPDI[ch].B.PDI;  //GPDI - > General Pad Data In
	return value;
}

void pb_sysclk_init_fnc(void)
{
	char count;
	char count1;
	
	//	ME.MER.R = 0x0000001D;          	/* Enable DRUN, RUN0, SAFE, RESET modes */
		
		/* Initialize PLL before turning it on: */
		
		/* Use 1 of the next 2 lines depending on crystal frequency: */
		//CGM.FMPLL_CR.R = 0x02400100;    	/* 8 MHz xtal: Set PLL0 to 64 MHz */   
		/* CGM.FMPLL_R = 0x12400100;*/     	/* 40 MHz xtal: Set PLL0 to 64 MHz */   

		ME.RUN[0].R   = 0x001F0074;       	/* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL */
		ME.RUNPC[0].R = 0x00000010; 	  	/* Peri. Cfg. 0 settings: only run in RUN0 mode */
		ME.PCTL[64].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
		ME.PCTL[65].R = 0x0000;
		ME.PCTL[66].R = 0x0000;
		ME.PCTL[67].R = 0x0000;
//		ME.RUNPC[1].R = 0x00000010;     	/* Peri. Cfg. 1 settings: only run in RUN0 mode */
//		ME.PCTL[57].R = 0x01;       		/* MPC56xxB CTUL: select ME.RUNPC[1] */
//	  	ME.PCTL[68].R = 0x01;           	/* MPC56xxB/S SIUL:  select ME.RUNPC[1] */
//			
											/* Mode Transition to enter RUN0 mode: */
		ME.MCTL.R = 0x40005AF0;         	/* Enter RUN0 Mode & Key */
		ME.MCTL.R = 0x4000A50F;         	/* Enter RUN0 Mode & Inverted Key */  
//		while (ME.GS.B.S_MTRANS) {}     	/* Wait for mode transition to complete */    
//		                          			/* Note: could wait here using timer and/or I_TC IRQ */
//		while(ME.GS.B.S_CURRENTMODE != 4) {}/* Verify RUN0 is the current mode */
//		
//		while (ME.IS.B.I_MTC != 1) {}    /* Wait for mode transition to complete */    
//		ME.IS.R = 0x00000001;           /* Clear Transition flag */
		
		for(count = 64; count <= 67; count++)
		{
			SIU.PCR[count].R = 0x0101;	
		}

		
		
		/*  INIT OUTPUTS IN PORTA                    */
			for(count1 = 0; count1 <= 12; count1++)
					{
						SIU.PCR[count1].R = 0x0200;
						SIU.GPDO[count1].B.PDO = 0;
					}			
		
}

