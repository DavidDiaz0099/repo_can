
#include "MPC5606B.h"
#include "led.h"
#include "pb_up.h"
#include "pb.h"
#include "pb_down.h"
#include "STM.h"
#include "opto.h"



int main(void) 
{

  volatile char i = 0;
  char j = 0;
 
  Config_clock_STM() ;
  led_sysclk_init_fnc();
  pb_sysclk_init_fnc();
  for (;;i++) 
  {  
	  pb_up();
	  //pb_down();
	  opto();
	  diez_pasos();
	  veinte_pasos();
	
  }
}


