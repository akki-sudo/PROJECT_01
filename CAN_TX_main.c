#include<lpc21xx.h>
#include"can1_header.h"
CAN1 v;
int main()
{
//	PINSEL0|=0xA0000000;
//	PINSEL1|=0x1;
	en_ext_interrupt();
	 can2_init();
	 v.id=0x3AE;
	 v.rtr=0;
	 v.dlc=1;
	 v.byteA=0;
	 v.byteB=0;
	 while(1)
	 {

	 }
}

