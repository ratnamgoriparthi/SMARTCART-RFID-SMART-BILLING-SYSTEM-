#ifndef interrupt_h
#define interrupt_h
#include <lpc21xx.h>
#include <string.h>

#define EINT0_INPUT_PIN 0x15400001 //P0.16
#define EINT1_INPUT_PIN 0x000000C0 //P0.3
#define EINT2_INPUT_PIN 0x0000C000 //P0.7

#define EINT0_VIC_CHNO 14 //External Interrupt 0 VIC channel
#define EINT1_VIC_CHNO 15 //External Interrupt 1 VIC channel
#define EINT2_VIC_CHNO 16 //External Interrupt 2 VIC channel
#define UART1_VIC_CHNO 7 //UART1 VIC channel

extern volatile int uart1_ready; //Set to 1 when complete RFID data is received 
extern char uart1_buf[20]; //Buffer used to store received RFID data

void init_interrupt(void);//Initialize UART1 and External Interrupts
void entry_isr(void)__irq;//ISR for Entry Button (EINT0)
void delete_isr(void)__irq;// ISR for Delete Button (EINT1)
void exit_isr(void)__irq;//ISR for Exit Button (EINT2)
void uart1_isr(void)__irq;//UART1 Receive Interrupt Service Routine
#endif
