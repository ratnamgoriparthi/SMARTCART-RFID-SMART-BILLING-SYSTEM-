#include <lpc21xx.h>
#include "uart1.h"
#include "lcd.h"
#include "delay.h"

//UART1 Initialization
void uart1_init(){
	//Configure P0.8 as TXD1 and P0.9 as RXD1
	PINSEL0&=~(15<<16);
	PINSEL0|=(TX1_PIN)|(RX1_PIN);
	//Enable access to baud rate registers
	U1LCR=(1<<DLAB)|word_length;
	//Load baud rate divisor
	U1DLM=(DIVISOR>>8);
	U1DLL=(DIVISOR);
	//Disable divisor latch access
	U1LCR&=~(1<<DLAB);
	//Enable UART1 Receive Interrupt
	U1IER=0X01;
}

//UART1 Transmit Character
void uart1_tx(unsigned char ch){
	U1THR = ch;
	//Wait until transmission completes
	while(((U1LSR>>TEMT)&1)==0);
}

//UART1 Receive Character
char uart1_rx(){
	 //Wait for data arrival 
	while(((U1LSR>>DR)&1)==0);
	return U1RBR;
}

// UART1 Transmit String
void uart1_str_tx(char *str){
	while(*str){
		uart1_tx(*str++);
	}
}

//UART1 Receive String
void uart1_str_rx(char *str){
	char ch;
	int i=0;
	while(1){
		//Receive one character 
		ch = uart1_rx();
		//End of message 
		if(ch=='\r' || ch=='\n'){
			str[i]='\0';
			break;
		}
		//Store character in buffer
		str[i++] = ch;
	}
}


