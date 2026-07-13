#ifndef uart0_h
#define uart0_h
#include <lpc21xx.h>
#include <string.h>

#define TX_PIN 0x00000001 //p0.0
#define RX_PIN 0x00000004 //p0.1
#define word_length 3
#define DLAB 7
#define TEMT 6
#define DR 0

#define FOSC 12000000
#define CCLK (FOSC*5)
#define PCLK (CCLK/4)
#define BAUDRATE 9600
#define DIVISOR (PCLK/(16*BAUDRATE))

void uart0_init(void);
void uart0_tx(unsigned char ch);
char uart0_rx(void);
void uart0_str_rx(char *str);
void uart0_str_tx(char *str);
#endif

