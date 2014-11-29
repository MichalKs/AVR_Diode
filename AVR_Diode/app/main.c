/**
 * @file: 	main.c
 * @brief:	LED test
 * @date: 	9 kwi 2014
 * @author: Michal Ksiezopolski
 *
 *
 * @verbatim
 * Copyright (c) 2014 Michal Ksiezopolski.
 * All rights reserved. This program and the
 * accompanying materials are made available
 * under the terms of the GNU Public License
 * v3.0 which accompanies this distribution,
 * and is available at
 * http://www.gnu.org/licenses/gpl.html
 * @endverbatim
 */

#include <stdio.h>
#include <string.h>

#include <led.h>
#include <util/delay.h>

#define SYSTICK_FREQ 1000 ///< Frequency of the SysTick set at 1kHz.
#define COMM_BAUD_RATE 115200UL ///< Baud rate for communication with PC

void softTimerCallback(void);

//#define DEBUG

#ifdef DEBUG
#define print(str, args...) printf("MAIN--> "str"%s",##args,"\r")
#define println(str, args...) printf("MAIN--> "str"%s",##args,"\r\n")
#else
#define print(str, args...) (void)0
#define println(str, args...) (void)0
#endif

#include <avr/io.h>

int main(void) {
	
	LED_Init(LED0); // Add an LED
	LED_Init(LED1);

	while (1) {

	  LED_ChangeState(LED0, LED_ON);
	  LED_ChangeState(LED1, LED_OFF);
	  _delay_ms(1000);
	  LED_ChangeState(LED0, LED_OFF);
	  LED_ChangeState(LED1, LED_ON);
	  _delay_ms(1000);
	}
}

/**
 * @brief Callback function called on every soft timer overflow
 */
void softTimerCallback(void) {

//  static uint8_t counter;
//
//  switch (counter % 3) {
//
//  case 0:
//    LED_ChangeState(LED1, LED_OFF);
//    LED_ChangeState(LED2, LED_OFF);
//    break;
//
//  case 1:
//    LED_ChangeState(LED1, LED_ON);
//    LED_ChangeState(LED2, LED_OFF);
//    break;
//
//  case 2:
//    LED_ChangeState(LED1, LED_OFF);
//    LED_ChangeState(LED2, LED_ON);
//    break;
//
//  }
//
////  println("Test string sent from STM32F4!!!"); // Print test string
//	counter++;
}
