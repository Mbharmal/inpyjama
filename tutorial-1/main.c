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

void main_func(void) {
    // Initialize the UART
    uart_init();

    // print "Hello World!"
    // TODO: Move to a better implementation
    uart_putc('H');
    uart_putc('e');
    uart_putc('l');
    uart_putc('l');
    uart_putc('o');
    uart_putc(' ');
    uart_putc('W');
    uart_putc('o');
    uart_putc('r');
    uart_putc('l');
    uart_putc('d');
    uart_putc('!');
    uart_putc('\n');
}
