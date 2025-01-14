#include<lpc21xx.h>
#include"can1_header.h"
void can2_init(void)
{
	 PINSEL1|=0x00014000;//23,24
	 VPBDIV=1;//60mhz
	 C2MOD=1;//reset
	 AFMR=0x2;//accept all msgs
	 C2BTR=0x001c001D;//125
	 C2MOD=0;//reset
}
#define TCS ((C2GSR>>3)&1)
void can2_tx(CAN1 v)
{
	C2TID1=v.id;
	C2TFI1=(v.dlc)<<16;
	if(v.rtr==0)
	{
		C2TDA1=v.byteA;
		C2TDB1=v.byteB;
	}
	else
	C2TFI1|=(1<<30);

	C2CMR=0x21;//select buff
	while(TCS==0);
}
#define RBS (C2GSR&1)
void can2_rx(CAN1 *ptr)
{
	while(RBS==0);
	ptr->id=C2RID;
	ptr->dlc=(C2RFS>>16)&0xF;
	ptr->rtr=(C2RFS>>30)&1;
	if(ptr->rtr==0)
	{
		ptr->byteA=C2RDA;
		ptr->byteB=C2RDB;
	}
	C2CMR=(1<<2);
}

