/**
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "uart.h"

#define UART_THR *((unsigned char *)(UART_BASE + 0x00))
#define UART_RBR *((unsigned char *)(UART_BASE + 0x00))
#define UART_LSR *((unsigned char *)(UART_BASE + 0x05))

#define TX_BUFF_FULL (!(UART_LSR & (1 << 5)))
#define NO_DATA (-1)
#define RX_BUFF_FULL (UART_LSR & 1)

void uart_putc(char c) {
  while (TX_BUFF_FULL)
    ;

  UART_THR = c;
}

int uart_getc(void) {
  if (RX_BUFF_FULL) return (int)UART_RBR;

  return NO_DATA;
}

void uart_init(void) { /* The default config works! */}
