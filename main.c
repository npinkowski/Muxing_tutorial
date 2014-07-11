#include "derivative.h" /* include peripheral declarations */
#include "mcg.h"
#include "Systick.h"
#include "Display.h"


int main(void)
{
    //init the clock
	pll_init(8000000,LOW_POWER,CRYSTAL,4,24,MCGOUT);
    
    //gate the clocks
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTA_MASK |SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTB_MASK;
    
    //configure the pins
	PORTC_PCR13 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;//CONTROL!
	PORTC_PCR16= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;//LED1
	PORTA_PCR1= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;//LED2
	PORTA_PCR2= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;//LED3
	PORTC_PCR7= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;//LED4
	PORTE_PCR0= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;//LED5
	PORTE_PCR1= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;//LED6
	PORTC_PCR8= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;//LED7
	
    //set GPIO to output.
	GPIOC_PDDR |= LED_CONTROL;
	GPIOA_PDDR |= LED_2;// & INPUT1;
	GPIOA_PDDR |= LED_3;
	GPIOC_PDDR |= LED_1;
	GPIOC_PDDR |= LED_4;
	GPIOE_PDDR |= LED_5;
	GPIOE_PDDR |= LED_6;
	GPIOC_PDDR |= LED_7;
    
    //initialize the Sytick Timer that we will use.
	Init_Systick();
    
    
	for(;;)
	{
        //Each time Display onto the SSD array the time we want.
        //the first input is the time to display
        //the second
		Display_Digit(timing(),75);
	}
    
    
	
	return 0;
}
