#include "interrupts.h"
#include "uart0.h"
//Buffer to store received UART1 data
char uart1_buf[20];
//Tracks current position in UART buffer
volatile int uart1_index=0;
//Flag indicating complete data received 
volatile int uart1_ready=0;
//Temporary character variable
char ch;
int i=0;
//Flags declared in another file
extern int entry_mode;
extern int delete_mode;
extern int exit_mode;

//Initialize UART and External Interrupts
void init_interrupt(){
	//Configure pins as EINT0, EINT1 and EINT2
	PINSEL0&=~((EINT1_INPUT_PIN)|(EINT2_INPUT_PIN));
	PINSEL1&=~(EINT0_INPUT_PIN);
	PINSEL0|=(EINT1_INPUT_PIN)|(EINT2_INPUT_PIN);
	PINSEL1|=(EINT0_INPUT_PIN);
	//Enable UART1 and External Interrupts in VIC
	VICIntEnable|=(1<<UART1_VIC_CHNO)|(1<<EINT0_VIC_CHNO)|(1<<EINT1_VIC_CHNO)|(1<<EINT2_VIC_CHNO);
	
	//Assign UART1 ISR
	VICVectCntl0=(1<<5)|UART1_VIC_CHNO;
	VICVectAddr0=(unsigned int)uart1_isr;
	
	// Assign Entry Button ISR
	VICVectCntl1=(1<<5)|EINT0_VIC_CHNO;
	VICVectAddr1=(unsigned int)entry_isr;
	
	//Assign Delete Button ISR
	VICVectCntl2=(1<<5)|EINT1_VIC_CHNO;
	VICVectAddr2=(unsigned int)delete_isr;
	
	//Assign Exit Button ISR
	VICVectCntl3=(1<<5)|EINT2_VIC_CHNO;
	VICVectAddr3=(unsigned int)exit_isr;
	
	//Configure all external interrupts as edge triggered 
	EXTMODE=(1<<0)|(1<<1)|(1<<2);
}

//UART1 Interrupt Service Routine
void uart1_isr(void)__irq{
	//Check if UART data is received
	if(U1IIR & 0x04){
		ch=U1RBR;
		 //Start of RFID data
		if(ch==0x02){ 
			uart1_index=0;
		}
		else if(ch==0x03){ //indicates end
			uart1_buf[uart1_index]='\0';
			uart1_ready=1;
			uart1_index=0;
		}
		//Store received character
		else{
			if(uart1_index < 19)
				uart1_buf[uart1_index++]=ch;
		}
	}
	//Inform VIC that ISR execution is completed
	VICVectAddr=0;
}

// Entry Button Interrupt 
void entry_isr(void)__irq{
	entry_mode=1;//Set entry mode flag
	EXTINT|=1<<0;//Clear interrupt flag
	VICVectAddr=0;//End of ISR
}

//Delete Button Interrupt
void delete_isr(void)__irq{
	delete_mode=1;//Set delete mode flag
	EXTINT|=1<<1;//Clear interrupt flag
	VICVectAddr=0;//End of ISR
}

//Exit Button Interrupt
void exit_isr(void)__irq{
	exit_mode=1;//Set exit mode flag
	EXTINT|=1<<2;//Clear interrupt flag
	VICVectAddr=0;// End of ISR
}
	
	
	
	
