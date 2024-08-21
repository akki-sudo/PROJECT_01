#include<lpc21xx.h>
#include"can_rx_header.h"
//unsigned int *ptr=(unsigned int*)0xE0038000;
void can1_init(void)
{
	 PINSEL1|=0x00040000;
	 VPBDIV=1;
	 C1MOD=1;
	 //ptr[0]=0x03AE03A0;
	 //SFF_sa=0;
	 //SFF_GRP_sa=0xc;
	 //EEF_sa=0xc;
	 //EEF_GRP_sa=0xc;
	 //ENDofTable=0xc;
	 AFMR=0x2;
	 C1BTR=0x001c001D;
	 
	 C1MOD=0;
}
#define TCS ((C1GSR>>3)&1)
void can1_tx(CAN1 v)
{
	C1TID1=v.id;
	C1TFI1=(v.dlc)<<16;
	if(v.rtr==0)
	{
		C1TDA1=v.byteA;
		C1TDB1=v.byteB;
	}
	else
	C1TFI1|=(1<<30);

	C1CMR=0x21;
	while(TCS==0);
}
#define RBS (C1GSR&1)
void can1_rx(CAN1 *ptr)
{
	while(RBS==0);
	ptr->id=C1RID;
	ptr->dlc=(C1RFS>>16)&0xF;
	ptr->rtr=(C1RFS>>30)&1;
	if(ptr->rtr==0)
	{
		ptr->byteA=C1RDA;
		ptr->byteB=C1RDB;
	}
	C1CMR=(1<<2);
}













