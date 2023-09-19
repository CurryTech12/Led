//main.c
#include <SI_EFM8BB1_Register_Enums.h>
void InitDevice(void)
{
//Disable Watchdog Timer with key sequence
WDTCN = 0xDE; //First key
WDTCN = 0xAD; //Second key

//Setup Defaults for P1
P1MDOUT = P1MDOUT_B0__OPEN_DRAIN | P1MDOUT_B1__OPEN_DRAIN
| P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__OPEN_DRAIN
| P1MDOUT_B4__PUSH_PULL | P1MDOUT_B5__OPEN_DRAIN
| P1MDOUT_B6__OPEN_DRAIN | P1MDOUT_B7__OPEN_DRAIN;
//Enable Weak Pullups
XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;
//Disable Interrupts
IE = IE_EA__DISABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
| IE_ESPI0__DISABLED | IE_ET0__DISABLED | IE_ET1__DISABLED
| IE_ET2__ENABLED | IE_ES0__DISABLED;
}


main(void){
	
	unsigned char x,y,z,w;
	unsigned char var = 0x01;
	InitDevice();
	
		while(1){
			for(w = 0;w<7;w++){// for loop runs seven times so that we can shift it seven times
				if(P0&0x04){//assign 0x04 to specfiy the button is not pushed on port P0.2 and controls the delay and inverted or not
				P1 = ~var;//invert the var global value
				for(x = 0;x<255;x++){
					for(y = 0;y<255;y++){
						for(z = 0;z<3;z++){
						}
					}
				}
				var = var << 1;//shifts to left by one if button is not pressed
				P1 = var;//assign to P1
			}else{// button is pushed non-zero number
				P1 = var;//assign var to be opposite number
				for(x = 0;x<255;x++){
					for(y = 0;y<255;y++){
					}
				}
				var = var <<1;//shifts to left inverted
				P1 = var;//assigns it to P1
			}
			}
			for(w = 0;w<7;w++){//for loop seven times to shift to right seven times everything under the for loop 
				if(P0&0x04){//if not pushed we run with this delay specfied
				P1 = ~var;//inverts it
				for(x = 0;x<255;x++){
					for(y = 0;y<255;y++){
						for(z = 0;z<3;z++){
						}
					}
				}
				var = var >>1;//then shift it inside the if statement
				P1 = var;//then assign it to P1
			}else{// button is pressed invert and delay is shorter
				P1 = var;//inverts the other way all on one off that shifts with a speed up delay or can be longer delay 
				for(x = 0;x<255;x++){
					for(y = 0;y<255;y++){
					}
				}
				var = var >>1;// shifts the inverter to the right by 1
				P1 = var;//assigns P1 to the shifted var output
			}
			}
	}
}
		
	
	
	
	
