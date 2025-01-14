#include<lpc21xx.h>

void delay_sec(unsigned int sec)
{
	//int a[] = {15,60,30,15,15};
	//unsigned int pclk = a[VPBDIV]*1000000;
	
	T0PC = 0;//intial value where it's need to starts from
	T0PR = 15000000 -1;//the value at it's need to end
	T0TC = 0;
	
	T0TCR = 1; 
	while( T0TC  < sec);
	T0TCR = 0;
}
void delay_ms(unsigned int ms)
{
	//int a[] = {15,60,30,15,15};
	//unsigned int pclk = a[VPBDIV]*1000000;
	
	T0PC = 0;//intial value where it's need to starts from
	T0PR = 15000 -1;//the value at it's need to end
	T0TC = 0;
	
	T0TCR = 1;//start the timer 
	while( T0TC  < ms);
	T0TCR = 0;//stop the timer 
}
