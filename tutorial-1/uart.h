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

#ifndef __UART_H__
#define __UART_H__

#define UART_BASE 0x10000000

/**
 * @brief Put a character on uart data buffer
 *
 * @param c byte to be sent out
 */
void uart_putc(char c);

/**
 * @brief Get a character from uart data buffer
 *
 * @return int byte read from the uart data register
 */
int uart_getc(void);

/**
 * @brief Init the uart, set baud etc
 *
 */
void uart_init(void);

#endif
