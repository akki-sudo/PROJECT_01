#include<lpc21xx.h>
#include"can_rx_header.h"
#define HEAD (3<<1)
#define LEFT (3<<13)
#define RIGHT (3<<15)
CAN1 m1;
unsigned int flag;
int main()
{
	
	IODIR0|=HEAD|LEFT|RIGHT;
	IOSET0|=HEAD|LEFT|RIGHT;
	can1_init();
	lcd_init();
	en_can1_interrupt();
	//lcd_cmd(0x0c);
	//uart0_init(9600);
	//uart0_tx_string("node B\r\n");
	while(1) 
	{
		 if(flag==1)
		 {
		 	//uart0_tx_string("data is received\r\n");
			L1:
		 	flag=0;
			if(m1.byteA==0x11) 
			{
					lcd_cmd(0x80);
					lcd_data(0);
					//lcd_cgram();
				  IOCLR0|=HEAD;//headlight ON
			}
			else if(m1.byteA==0x12)
			{
					lcd_cmd(0x80);
					lcd_string("      ");
				  IOSET0|=HEAD;	//Headlight OFF
			}
			else if(m1.byteA==0x13)	 //data frame left indicator
			{
				IOSET0|=RIGHT;	   //turn off right indicator
				 while(1)
				 {
				 		lcd_cmd(0xc0);
				 		lcd_string("<--");
				 	   IOCLR0|=LEFT;
					   delay_ms(100);
					   IOSET0|=LEFT;
					   delay_ms(100);
					   if(m1.byteA==0x14||m1.byteA==0x15||m1.byteA==0x16)
					   			goto L1;
						else if(m1.byteA==0x11) 
						{
						lcd_cmd(0x80);
						lcd_data(0);
					//	lcd_cgram();
					  	IOCLR0|=HEAD;//headlight ON
						}
						else if(m1.byteA==0x12)
						{
							
								lcd_cmd(0x80);
								lcd_string("      ");
							  IOSET0|=HEAD;	//Headlight OFF
						}
				 }
			}
			else if(m1.byteA==0x14)	//turn off left indicator
			{
				lcd_cmd(0xc0);
				lcd_string("                 ");
				IOSET0|=LEFT;
			}
			else if(m1.byteA==0x15)	 //data frame right indicator
			{
				 IOSET0|=LEFT;		//turn off left indicator
				 while(1)
				 {		lcd_cmd(0xCB );
				 		lcd_string("-->");
				 	   IOCLR0|=RIGHT;
					   delay_ms(100); 
					   IOSET0|=RIGHT;
					   delay_ms(100);
					   if(m1.byteA==0x16||m1.byteA==0x13||m1.byteA==0x14)//return if press right indicator
					   		   goto L1;
							else if(m1.byteA==0x11) 
						{
					
						lcd_cmd(0x80);
						lcd_data(0);
						//lcd_cgram();
					  	IOCLR0|=HEAD;//headlight ON
						}
					else if(m1.byteA==0x12)
					{
							
							lcd_cmd(0x80);
							lcd_string("      ");
						  IOSET0|=HEAD;	//Headlight OFF
					}
							
				 }
			}
			else if(m1.byteA==0x16)	 //turn off right indicator
			{
				 IOSET0|=RIGHT;
				 lcd_cmd(0xc0);
				lcd_string("                 ");
			}
		 }
	}
}

