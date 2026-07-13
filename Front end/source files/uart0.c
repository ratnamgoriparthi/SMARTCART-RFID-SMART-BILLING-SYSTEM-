#include <lpc21xx.h>
#include "delay.h"
#include "uart0.h"

//Configure P0.0 as TXD0 and P0.1 as RXD0
void uart0_init(){
	PINSEL0&=~(15<<0);
	PINSEL0|=TX_PIN|RX_PIN;
	U0LCR|=(1<<DLAB)|word_length;//Enable access to baud rate registers 
	 //Load baud rate divisor
	U0DLM=(DIVISOR>>8);
	U0DLL=(DIVISOR);
	//Disable divisor access
	U0LCR&=~(1<<DLAB);
}

//UART0 Transmit Character
void uart0_tx(unsigned char ch){
	//Load character into transmit register
	U0THR=ch;
	//Wait until transmission is complete
	while(((U0LSR>>TEMT)&1)==0);
}

//UART0 Receive Character
char uart0_rx(){
	// Wait until data is available
	while(((U0LSR>>DR)&1)==0);
	return U0RBR;//Return received character
}

//UART0 Transmit String
void uart0_str_tx(char *str){
	while(*str){
		uart0_tx(*str++);
	}
}

//UART0 Receive String
void uart0_str_rx(char *str){
	char ch;
	int i=0;
	while(1){
		//Receive one character
		ch=uart0_rx();
		if(ch=='$'){//End of string marker
			str[i]='\0';
			break;
		}
		//Store received character
		if(i<19)
		{
		str[i++]=ch;
	}
}
	}




