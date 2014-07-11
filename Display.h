/*
 * Display.h
 *
 *  Created on: Jun 20, 2014
 *      Author: Administrator
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#define LED_CONTROL (1<<13)//ptd3
#define LED_1 (1<<16)//ptc16
#define LED_2 (1<<1)//pta1
#define LED_3 (1<<2)//pta2
#define LED_4 (1<<7)//ptc7
#define LED_5 (1<<0)//ptc0
#define LED_6 (1<<1)//ptd4
#define LED_7 (1<<8)//ptc8
#define LED_8 (1<<3)//ptD2
#define INPUT1 (1<<16)//INPUT ONE in ptb8

void Display(int);
void Display_Digit(int, unsigned int speed);


#endif /* DISPLAY_H_ */