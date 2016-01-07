
#include "MPC5606B.h"
#include "led.h"
#include "pb.h"
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
	  opto();
	  //diez_pasos();
	  //veinte_pasos();
	  
  }
}


