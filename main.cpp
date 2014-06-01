/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"
#include <avr/interrupt.h>

ISR(USART_RX_vect)
{
    char data = Usart::USART_recv(); //UDRバッファを読み出さないとここが無限ループになる。USART_RXCの仕様か。
    Usart::USART_Transmit(data);
}

int main(void)
{
    int ubrr = Usart::getUBRR(9600);
    Usart::USART_init(ubrr);
    sei();
    Usart::putString("Initializing success.\n");//Stabilize serial communication

    for(;;){
    }
    return 0;   /* never reached */
}
