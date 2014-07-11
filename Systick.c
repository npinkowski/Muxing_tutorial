#include "Systick.h"
#include "Derivative.h"
#include "mcg.h"


static volatile unsigned int Time[3]={0,0,0};
//Time[0] --> ticks up every 1/1000th of a second
//Time[1] --> This is the time that is displayed on the LED
//Time[2] --> This is the ticker used for the multiplexing delay.

void Init_Systick()
{
	SYST_RVR =  CORE_CLOCK/1000u; //CORE_CLOCK IS 48000000
	SYST_CVR = 0;
    //now we set the control status register.
	SYST_CSR = 0x7; //Set the last three bits to 111.
}


void MuxingDelay(unsigned int a)
{
	//this function is used to delay the program.
	Time[2] = 0;
	while(Time[2]<a)
	{
        //this loop does nothing...
	}
}


int timing()
{
    //this is a getter function;
    //returns the time that will be displayed.
    return Time[1];
}

void SysTick_Handler()
{
    //we broke the timer down so that it generates an
    //interrupt in here once every 1/1000th of a second.
    Time[0]++;  //counts the ticker up!
    Time[2]++; //this always goes up and is used for muxing.
    
    
    if(Time[0]==1000)
    {
        Time[1]++; //this increases the time that we will display.
        Time[0]=0;
    }
    
    //we only have four SSD's
    if(Time[1]==10000)
    {
        Time[1]==0;
    }
    
}