extern void uart0_init(unsigned int);
extern void uart0_tx(unsigned char);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *);
extern void uart0_rx_string(char *,int);
extern void uart0_tx_integer(unsigned int);
extern void delay_ms(unsigned int);
extern void lcd_init(void);
extern void lcd_data(unsigned char);
extern void lcd_cmd(unsigned char);
extern void lcd_string(char *);
extern void lcd_integer(unsigned int);
extern void adc_init(void);
extern unsigned short int adc_read(unsigned char);
extern void uart0_tx_float(float);
extern void en_uart0_interrupt(void);
extern void config_vic(void);
extern void en_ext_interrupt(void);
typedef struct CAN1_MSG
{
	unsigned int id;
	unsigned int byteA;
	unsigned int byteB;
	unsigned char rtr;
	unsigned char dlc;
}CAN1;
void can2_init(void);
extern void can2_tx(CAN1);
extern void can2_rx(CAN1 *);

