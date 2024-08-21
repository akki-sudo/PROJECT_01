TITLE : Vehicle control system using "CAN" protocol 
                                                    
"modern vehicle requires reliable communication btw various ECU's(electronic control unit) to manage the fuctions like lightning fuction(controlling headlight and indicators),engine control,body control etc".
IN this project i am using "TWO ECUS" 
1> BCM(body control module)
2> LCM(light control module)

1>BCM module : responsible for managing the overall vehicle body electronics,including sending the dataframes to other sub ECUs like here LCM module.

2>LCM module : respocible for controlling the lightning functions such as turning the headlights and indicators on and off based on the command which is recieved by bcm module.

                ******************working***************************************

In this project i used two LPC2129 ARM7 based microcontroller(one for BCM and other one for LCM) 
CAN protocol is used for commmunication between  ECUs.
about LPC2129 :
1> 32 bit microcontroller with 60MHz frequency. 
2> 48 GPIOS pins out of 48,2 are non programble pins. 
3> consist of on chip periperals like UART(2),CAN(2),SPI(2),I2C(1),Timers(2).
4> three switches,3 leds.
5>vector table with 16 slots etc

1>BCM(TX) : for this module i am using 3 switches as external intrerrupt(etx0,etx1,etx2,)
SW0(switch_0) ---> To sent LCM for headligth on/off related dataframes.
SW1 -------------> To sent LCM for Left indicator on/off 
SW12 -------------> To sent LCM for right indicator on/off 

2>LCM(RX) : As soon as when the data is received from BCM Interrupt will occur here i used rx_CAN intterupt 
            based on commands it will do action like turn on turn off the headlight and indicators for this i connected 6 leds to this microcontroller....... 
