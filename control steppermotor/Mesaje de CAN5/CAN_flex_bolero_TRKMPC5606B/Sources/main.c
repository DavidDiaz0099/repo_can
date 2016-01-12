/*~A*/
/*~+:Import*/
#include    "GPIO.h"
#include    "PIT.h"
#include    "bspi.h"
#include    "MemAlloc_Cfg.h"
#include    "SchM_Cfg.h"
#include    "Can.h"
#include    "Can_Cfg.h"
#include    "sysinit.h"
#include 	"Exceptions.h"
#include "IntcInterrupts.h"
#include "application.h"

/*~E*/
/*~A*/
/*~+:Main Code*/
int main(void) 

{
	/* Mode initializations */
	sysinit_InitMode();
	/* Clock initializations */
	sysinit_InitSysClock();
	/* Memory Allocation Initialization NOT RELEVANT FOR YOUR SCHEDULER */
	MemAllocInit(&MemAllocConfig);
	/*Initialize LEDs on TRK-MPC560xB board */
	vfnGPIO_LED_Init(); 
	
	GPIO_config();
	/* SBC (System Basis Chip (the transceiver, you know)) dependencies */
	/* The SBC is initialized by SPI */
	InitDSPI_1();
	/* SBC configuration */
	ConfigureMZC33905DSPI_1();
    /* CAN Initialization */
	CAN_Initialization(&can_driver_config);
	/* Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	/* SchM Initialization */
	SchM_Init(&SchMConfig);
    /* Enable External Interrupts*/
    INTC_EnableInterrupts();
    /* SchM Start */
    SchM_Start();
	/* Infinite loop - Should never reach this point */
    
	for (;;) 
	{

	}
}
/*~E*/
