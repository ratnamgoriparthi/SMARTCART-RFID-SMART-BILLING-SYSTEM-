#include <lpc21xx.h>
#define DATA_PINS 24 //p1.24
#define RS 17 //p0.17
#define EN 18 //p0.18
#define RW 19 //p0.19

void initlcd(void);
void cmdlcd(char cmd);
void datalcd(char data);
void charlcd(char ch);
void strlcd(char *str);
void integerlcd(int num);

