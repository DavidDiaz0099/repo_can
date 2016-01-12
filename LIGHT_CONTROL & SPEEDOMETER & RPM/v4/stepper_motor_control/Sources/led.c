/*
 * LED.c
 *
 *  Created on: Oct 5, 2015
 *      Author: Jorge
 */
#include "LED.h"
#include "MPC5606B.h"

void led_sysclk_init_fnc(void)
{
	//	ME.MER.R = 0x0000001D;          	/* Enable DRUN, RUN0, SAFE, RESET modes */
		
		/* Initialize PLL before turning it on: */
		
		/* Use 1 of the next 2 lines depending on crystal frequency: */
		//CGM.FMPLL_CR.R = 0x02400100;    	/* 8 MHz xtal: Set PLL0 to 64 MHz */   
		/* CGM.FMPLL_R = 0x12400100;*/     	/* 40 MHz xtal: Set PLL0 to 64 MHz */   
		char count = 68;
		ME.RUN[0].R   = 0x001F0074;       	/* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL */
		ME.RUNPC[0].R = 0x00000010; 	  	/* Peri. Cfg. 0 settings: only run in RUN0 mode */
		ME.PCTL[68].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
		ME.PCTL[69].R = 0x0000;
		ME.PCTL[70].R = 0x0000;
		ME.PCTL[71].R = 0x0000;
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
		
		for(count = 68; count <= 71; count++)
		{
			SIU.PCR[count].R = 0x0201;
			SIU.GPDO[count].B.PDO = 1;
		}
}
//for delay
void delay_for( int num)
{
	  int j;
	for(j=0; j<=num; j++)
	{
		
	}
}

void t(int no){
	int t;
	for(t=0; t<=no; t++)
	{	
	}
}

void led_change_status(char ch, char led_state)
{
	SIU.GPDO[ch].B.PDO = led_state;
}


