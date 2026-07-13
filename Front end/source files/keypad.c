#include <lpc21xx.h>
#include "delay.h"
#include "keypad.h"
#include "lcd.h"

//Key mapping for 4x4 keypad 
char kpm_LUT[4][4]={{'0','1','2','A'},
                   {'3','4','5','B'},
									 {'6','7','8','C'},
									 {'9','0','=','#'}};
//Initialize Keypad
// Rows  -> Output Pins
//Columns -> Input Pins									 
void init_kpm(){
	IODIR1|=(15<<ROWS);// Configure rows as outputs
	IODIR1&=~(15<<COLS); // Configure columns as inputs
}

//Scan Keypad
char keyscan(){
	int rno,cno;
	while(1){
		// Scan each row one by one
		for(rno=0;rno<4;rno++){
			IOSET1=(15<<ROWS);//Make all rows HIGH 
		  IOCLR1=(1<<(ROWS+rno));//Make current row LOW
			//Check all columns
			for(cno=0;cno<4;cno++){
				//Key pressed if column becomes LOW
				if(((IOPIN1>>(COLS+cno))&1)==0){
					//Wait until key is released 
					while(((IOPIN1>>(COLS+cno))&1)==0);
					//Debouncing delay
					delay_ms(500);
					//Return corresponding key value
					return kpm_LUT[rno][cno];
				}
			}
		}
	}
}

int read_num(){
	int sum=0;
	char key;
	while(1){
		//Read key from keypad
		key=keyscan();
		//If numeric key is pressed 
	if(key>='0' && key<='9'){
		datalcd(key);
		//Convert ASCII digit to integer
		sum=(sum*10)+(key-'0');
	}
	//Backspace operation
	else if(key=='#'){
		if(sum>0){
		sum=sum/10;// Remove last digit
		cmdlcd(0X10);
		datalcd(' '); //Erase digit
		cmdlcd(0X10);//Move cursor back
	}
}
	//End of number entry
	else if(key=='='){
		break;
}
	// Clear LCD display
	else if(key=='C'){
		cmdlcd(0x01);
	}
}
	return sum;//Return entered number
}
	
