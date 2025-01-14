#include<lpc21xx.h>
#include"can1_header.h"
extern CAN1 v;

void ext0_interrupt_handler(void)__irq
{
	 static int flag1=0;
	 flag1^=1;
	 if(flag1)
	 {
	 	  v.id=0x3A0;
		  v.byteA=0x15;
		  can2_tx(v);
	 }
	 else
	 {
	 	v.id=0x3A0;
		  v.byteA=0x16;
		  can2_tx(v);
	 }
	 EXTINT=7;
	 VICVectAddr=0;
}
void ext1_interrupt_handler(void)__irq
{
	 static int flag2=0;
	 flag2^=1;
	 if(flag2)
	 {
	 	  v.id=0x3A0;
		  v.byteA=0x13;
		  can2_tx(v);
	 }
	 else
	 {
	 	v.id=0x3A0;
		  v.byteA=0x14;
		  can2_tx(v);
	 }
	 EXTINT=7;
	 VICVectAddr=0;
}
void ext2_interrupt_handler(void)__irq
{
	 static int flag3=0;
	 flag3^=1;
	 if(flag3)
	 {
	 	  v.id=0x3A0;
		  v.byteA=0x11;
		  can2_tx(v);
	 }
	 else
	 {
	 	v.id=0x3A0;
		  v.byteA=0x12;
		  can2_tx(v);
	 }
	 EXTINT=7;
	 VICVectAddr=0;
}
void en_ext_interrupt(void)
{
	PINSEL0|=0xA0000000;
	PINSEL1|=0x1;
	  EXTMODE=7;
	  EXTPOLAR=0;
	  VICIntSelect=0;
	  VICVectCntl0=16|(1<<5);
	  VICVectCntl1=15|(1<<5);
	  VICVectCntl2=14|(1<<5);
	  VICVectAddr0=(unsigned int)ext0_interrupt_handler;
	  VICVectAddr1=(unsigned int)ext1_interrupt_handler;
	  VICVectAddr2=(unsigned int)ext2_interrupt_handler;
	  VICIntEnable|=(1<<14)|(1<<15)|(1<<16);
}


