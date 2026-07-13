#include <lpc21xx.h>
#include "uart0.h"
#include "uart1.h"
#include "interrupts.h"
#include "lcd.h"
#include "delay.h"
#include "keypad.h"
#include "rfid_reader.h"
#include <string.h>
#include <stdlib.h>
char num;
int main()
{
    uart0_init();//Initialize UART0 for communication with Linux PC 
    uart1_init();//Initialize UART1 for RFID Reader communication 
    init_interrupt();// Configure UART and External Interrupts
        initlcd();//Initialize LCD display
        init_kpm();//Initialize 4x4 keypad
        cmdlcd(0x01);//Clear LCD screen
        cmdlcd(0x80);//Move cursor to first row, first column
        strlcd("smart billing");// Display welcome message 
    while(1){
      RFID();//Continuously monitor RFID scans
    }
}

