#include <lpc21xx.h>
#define ROWS 16  //p1.16
#define COLS 20  //p1.20

void init_kpm(void);//Initialize keypad GPIO pins
char keyscan(void);//Scan keypad and return pressed key
int read_num(void);//Read multi-digit number from keypad 
