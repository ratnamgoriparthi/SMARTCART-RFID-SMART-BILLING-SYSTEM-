#include <lpc21xx.h>
#include <string.h>
#include "interrupts.h"
#include "keypad.h"
#include "uart0.h"
#include "uart1.h"
#include "lcd.h"
#include "delay.h"
#include <stdlib.h>
#define PIN 9999;

int amount(int,int);
void uart0_tx_uart1(void);
void RFID(void);

