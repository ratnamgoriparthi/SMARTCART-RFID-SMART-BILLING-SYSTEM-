#include <lpc21xx.h>
#include "lcd.h"
#include "delay.h"

 //Send Command to LCD
void cmdlcd(char cmd){
	IOCLR0=(1<<RS);//RS = 0 (Command Mode)
	IOCLR0=(1<<RW);//RW = 0 (Write Mode)
	IOCLR1=(255U<<DATA_PINS);//Clear data lines
	IOSET1=((unsigned int)cmd<<DATA_PINS);//Put command on data bus
	IOSET0=(1<<EN);//Enable HIGH
	delay_us(1);
	IOCLR0=(1<<EN);//Enable LOW (Latch command)
	delay_ms(2);
}
//Send Data to LCD
void datalcd(char data){
	IOSET0=(1<<RS);//RS = 1 (Data Mode)
	IOCLR0=(1<<RW);//RW = 0 (Write Mode)
	IOCLR1=(255U<<DATA_PINS);// Clear data lines
	IOSET1=((unsigned int)data<<DATA_PINS);// Put data on bus
	IOSET0=(1<<EN);//Enable HIGH
	delay_us(1);
	IOCLR0=(1<<EN);//Enable LOW (Latch data)
	delay_ms(2);
}
//Initialize LCD
void initlcd(){
	// Configure LCD data pins as output
	IODIR1|=(255U<<DATA_PINS);
	IODIR0|=(1<<RS)|(1<<RW)|(1<<EN);//Configure RS, RW, EN as output
	delay_ms(15);
	//LCD Initialization Sequence
	cmdlcd(0X30);
	delay_ms(5);
	cmdlcd(0X30);
	delay_us(100);
	cmdlcd(0x30);
	cmdlcd(0x38);// 8-bit mode, 2 lines
	cmdlcd(0x0E);// Display ON, Cursor ON
	cmdlcd(0x06);//Auto cursor increment
	cmdlcd(0x01);//Clear display
}
//Display Single Character
void charlcd(char ch){
	datalcd(ch);
}
//Display String on LCD
void strlcd(char *str){
	while(*str){
		datalcd(*str++);
	}
}
// Display Integer Number on LCD
void integerlcd(int num){
	int arr[10],i=0;
	//Special case for zero
	if(num==0){
		datalcd('0');
		return ;
	}
	//Extract digits
	while(num){
		arr[i++]=(num%10)+48;
		num=num/10;
	}
	//Display digits in correct order
	for(--i;i>=0;i--){
		datalcd(arr[i]);
	}
}

