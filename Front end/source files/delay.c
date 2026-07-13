#include "delay.h"
//for microseconds delay
void delay_us(int dlyus){
	for(dlyus*=12;dlyus>0;dlyus--);
}
//for milliseconds delay
void delay_ms(int dlyms){
	for(dlyms*=12000;dlyms>0;dlyms--);
}
//for seconds delay
void delay_s(int dlys){
	for(dlys*=12000000;dlys>0;dlys--);
}
