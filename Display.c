/*
 * Display.c
 *
 *  Created on: Jun 20, 2014
 *      Author: Administrator
 */
#include "Display.h"
#include "mcg.h"
#include "derivative.h"
#include "Systick.h"

void Display(int n)
{
    //if it's negative one than don't display anything.
	if(n==-1)
	{
		GPIOC_PSOR |= LED_1;
		GPIOA_PSOR |= LED_2;
		GPIOA_PSOR |= LED_3;
		GPIOC_PSOR |= LED_4;
		GPIOE_PSOR |= LED_5;
		GPIOE_PSOR |= LED_6;
		GPIOC_PSOR |= LED_7;
		GPIOD_PSOR |= LED_8;
	}
	if(n==0)
	{
		GPIOC_PCOR |= LED_1;
		GPIOA_PCOR |= LED_2;
		GPIOA_PCOR |= LED_3;
		GPIOE_PCOR |= LED_5;
		GPIOE_PCOR |= LED_6;
		GPIOC_PCOR |= LED_7;
		GPIOD_PCOR |= LED_8;
		GPIOC_PSOR = LED_4;
	}
	else if(n==1)
	{
		GPIOA_PCOR |= LED_3;
		GPIOE_PCOR |= LED_5;
		GPIOE_PCOR |= LED_6;
		GPIOC_PSOR = LED_1;
		GPIOA_PSOR = LED_2;
		GPIOC_PSOR = LED_4;
		GPIOD_PSOR = LED_8;
		GPIOC_PSOR = LED_7;
	}
	else if(n==2)
	{
		GPIOC_PCOR |= LED_1;
		GPIOA_PCOR |= LED_2;
		GPIOC_PCOR |= LED_4;
		GPIOE_PCOR |= LED_5;
		GPIOE_PCOR |= LED_6;
		GPIOC_PCOR |= LED_7;
		GPIOD_PSOR |= LED_8;
		GPIOA_PSOR |= LED_3;
	}
	else if(n==3)
	{
		GPIOA_PCOR |= LED_2;
		GPIOA_PCOR |= LED_3;
		GPIOC_PCOR |= LED_4;
		GPIOE_PCOR |= LED_5;
		GPIOE_PCOR |= LED_6;
		GPIOC_PCOR |= LED_7;
		GPIOC_PSOR |= LED_1;
		GPIOD_PSOR |= LED_8;
	}
	else if(n==4)
	{
		GPIOA_PCOR |= LED_3;
		GPIOC_PCOR |= LED_4;
		GPIOE_PCOR |= LED_5;
		GPIOE_PCOR |= LED_6;
		GPIOD_PCOR |= LED_8;
		GPIOC_PSOR |= LED_7;
		GPIOC_PSOR |= LED_1;
		GPIOA_PSOR |= LED_2;
	}
	else if(n==5)
	{
		GPIOA_PCOR |= LED_2;
		GPIOA_PCOR |= LED_3;
		GPIOC_PCOR |= LED_4;
		GPIOE_PCOR |= LED_5;
		GPIOC_PCOR |= LED_7;
		GPIOD_PCOR |= LED_8;
		GPIOE_PSOR |= LED_6;
		GPIOC_PSOR |= LED_1;
	}
	else if(n==6)
	{
		GPIOC_PCOR |= LED_1;
		GPIOA_PCOR |= LED_2;
		GPIOA_PCOR |= LED_3;
		GPIOC_PCOR |= LED_4;
		GPIOE_PCOR |= LED_5;
		GPIOC_PCOR |= LED_7;
		GPIOD_PCOR |= LED_8;
		GPIOE_PSOR |= LED_6;
	}
	else if(n==7)
	{
		GPIOA_PCOR |= LED_3;
		GPIOC_PCOR |= LED_4;
		GPIOE_PCOR |= LED_5;
		GPIOE_PCOR |= LED_6;
		GPIOC_PCOR |= LED_7;
		GPIOD_PCOR |= LED_8;
		GPIOC_PSOR = LED_1;
		GPIOA_PSOR = LED_2;
		GPIOC_PSOR = LED_4;
		GPIOD_PSOR = LED_8;
	}
	else if(n==8)
	{
		GPIOC_PCOR |= LED_1;
		GPIOA_PCOR |= LED_2;
		GPIOA_PCOR |= LED_3;
		GPIOC_PCOR |= LED_4;
		GPIOE_PCOR |= LED_5;
		GPIOE_PCOR |= LED_6;
		GPIOC_PCOR |= LED_7;
		GPIOD_PCOR |= LED_8;
	}
	else if(n>=9)
	{
		GPIOC_PSOR |= LED_1;
		GPIOA_PSOR |= LED_2;
		GPIOA_PCOR |= LED_3;
		GPIOC_PCOR |= LED_4;
		GPIOE_PCOR |= LED_5;
		GPIOE_PCOR |= LED_6;
		GPIOC_PCOR |= LED_7;
		GPIOD_PCOR |= LED_8;
	}
}

void Display_Digit(int m, unsigned int speed)
{
    //this function figure out which screen has to display what
    int a;
    int b;
    int c;
    int d;
	
    if(m<10)
    {
        a=m;
        b=-1;
        c=-1;
        d=-1;
        GPIOC_PSOR = LED_CONTROL;//turn on first control
        GPIOC_PCOR = LED_CONTROL2;//turn off second control
        GPIOA_PCOR = LED_CONTROL3;//turn off third control
        GPIOA_PCOR = LED_CONTROL4;//turn off fourth
        Display(a);
    }
    else
    {
        if(m<100)
        {
            a=m%10;
            b=m/10;
            c=-1;
            d=-1;
            GPIOC_PSOR = LED_CONTROL;//turn on first control
            GPIOC_PCOR = LED_CONTROL2;//turn off second control
            GPIOA_PCOR = LED_CONTROL3;//turn off third control
            GPIOA_PCOR = LED_CONTROL4;//turn off fourth
            Display(a);
            MuxingDelay(speed);//this should be 50 millisecond by the interrupt isn't going.
            GPIOC_PTOR = LED_CONTROL;//Turn off first one.
            GPIOC_PTOR = LED_CONTROL2;///Turn on second one.
            //third stays off
            Display(b);
            MuxingDelay(speed);
        }
        else
        {
            if(m<1000)
            {
                a=m%10;
                b=(m%100)/10;
                c=m/100;
                d=-1;
                GPIOC_PSOR = LED_CONTROL;//turn on first control
                GPIOC_PCOR = LED_CONTROL2;//turn off second control
                GPIOA_PCOR = LED_CONTROL3;//turn off third control
                GPIOA_PCOR = LED_CONTROL4;//turn off fourth
                Display(a);
                DMuxingDelay(speed-30);//this should be 50 millisecond by the interrupt isn't going.
                GPIOC_PTOR = LED_CONTROL;//Turn off first one.
                GPIOC_PTOR = LED_CONTROL2;///Turn on second one.
                //third stays off
                Display(b);
                MuxingDelay(speed-30);
                GPIOC_PTOR = LED_CONTROL2;//turn off the second
                GPIOA_PTOR = LED_CONTROL3;//turn on the third
                Display(c);
                MuxingDelay(speed-30);
                
            }
            else
            {
                a=m%10;
                b=(m%100)/10;
                c=(m%1000)/100;
                d=m/1000;
                GPIOC_PSOR = LED_CONTROL;//turn on first control
                GPIOC_PCOR = LED_CONTROL2;//turn off second control
                GPIOA_PCOR = LED_CONTROL3;//turn off third control
                GPIOA_PCOR = LED_CONTROL4;//turn off fourth
                Display(a);
                MuxingDelay(speed-20);//this should be 50 millisecond by the interrupt isn't going.
                GPIOC_PTOR = LED_CONTROL;//Turn off first one.
                GPIOC_PTOR = LED_CONTROL2;///Turn on second one.
                //third stays off
                Display(b);
                MuxingDelay(speed-20);
                GPIOC_PTOR = LED_CONTROL2;//turn off the second
                GPIOA_PTOR = LED_CONTROL3;//turn on the third
                Display(c);
                MuxingDelay(speed-30);
                GPIOA_PTOR = LED_CONTROL3;//turn off the third
                GPIOA_PTOR = LED_CONTROL4;//turn on the fourth
                Display(d);
                MuxingDelay(speed-60);
            }
        }
    }
}