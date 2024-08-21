#include<lpc21xx.h>
#include"can_rx_header.h"
extern CAN1 m1;
extern unsigned int flag;
void can1_rx_handler(void)__irq
{
	 flag=1;
	 m1.id=C1RID;
	 m1.dlc=(C1RFS>>16)&0xF;
	 m1.rtr=(C1RFS>>30)&1;
	 if(m1.rtr==0)
	 {
	 	m1.byteA=C1RDA;
		m1.byteB=C1RDB;
	 }
	 C1CMR=(1<<2);//clear the int 
	 VICVectAddr=0;
}
void en_can1_interrupt(void)
{
	VICIntSelect=0;
   VICVectAddr4=(unsigned int)can1_rx_handler;
   VICVectCntl4=26|(1<<5);
   VICIntEnable|=(1<<26);
   C1IER=1;
}
