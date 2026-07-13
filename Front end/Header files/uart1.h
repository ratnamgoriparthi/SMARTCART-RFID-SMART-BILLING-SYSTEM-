#ifndef uart1_h
#define uart1_h

#include <lpc21xx.h>

#define TX1_PIN 0x00010000  //p0.8 -->TXD1
#define RX1_PIN 0x00040000  //p0.9 -->RXD1
#define word_length 3
#define DLAB 7
#define TEMT 6
#define DR 0

#define FOSC 12000000
#define CCLK (FOSC*5)
#define PCLK (CCLK/4)
#define BAUDRATE 9600
#define DIVISOR (PCLK/(16*BAUDRATE))

void uart1_init(void);
void uart1_tx(unsigned char ch);
char uart1_rx(void);
void uart1_str_tx(char *str);
void uart1_str_rx(char *str);

#endif
