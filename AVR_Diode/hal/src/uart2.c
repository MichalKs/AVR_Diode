/**
 * @file:   uart2.c
 * @brief:  Controlling UART
 * @date:   12 kwi 2014
 * @author: Michal Ksiezopolski
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

#include <uart2.h>

/**
 * @addtogroup USART2
 * @{
 */

void    (*rxCallback)(uint8_t);   ///< Callback function for receiving data
uint8_t (*txCallback)(uint8_t*);  ///< Callback function for transmitting data

/**
 * @brief Initialize USART2
 * @param baud
 * @param rxCb
 * @param txCb
 */
void UART2_Init(uint32_t baud, void(*rxCb)(uint8_t), uint8_t(*txCb)(uint8_t*) ) {

  // assign the callbacks
  rxCallback = rxCb;
  txCallback = txCb;

  // Enable clocks for peripherals


  // USART2 TX on PA2


  // USART2 RX on PA3


  // USART initialization (standard 8n1)


  // Enable USART2

  // Enable RXNE interrupt
  // Disable TXE interrupt - we enable it only when there is
  // data to send

  // Enable USART2 global interrupt

}
/**
 * @brief Enable transmitter.
 * @details This function has to be called by the higher layer
 * in order to start the transmitter.
 */
void UART2_TxEnable(void) {

}

/**
 * @brief IRQ handler for USART2
 */
void USART2_IRQHandler(void) {

  // If transmit buffer empty interrupt
  if(1) {

    uint8_t c;

    if (txCallback) { // if not NULL
      // get data from higher layer using callback
      if (txCallback(&c)) {
        ; // Send data
      } else { // if no more data to send disable the transmitter
        ;
      }
    }
  }

  // If RX buffer not empty interrupt
  if(1) {

    uint8_t c = 0; // Get data from UART

    if (rxCallback) { // if not NULL
      rxCallback(c); // send received data to higher layer
    }
  }
}

/**
 * @}
 */
