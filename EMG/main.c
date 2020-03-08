#include "LBTY_int.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "GIE_int.h"
#include "TIM0_int.h"
#include "USART_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

u16 r;
u8 *str , *s1=" mV\n";

void EMG_Sample()
{
	TIM0_SetTCNT0(100);
	r=(( ADC_u16ReadADC() * (5 / 1023))*1000);
	USART_TransmitString(itoa(r,str,10));
	USART_TransmitString(s1);
}

int main()
{
	DIO_void_Intialization();
	ADC_voidInit();
	ADC_voidEnable();
	GIE_void_enable();
	TIM0_init();
	TIM0_enableOverflowinterrupt();
	TIM0_SetTCNT0(124);
	TIM0_SetCallBackOvf(EMG_Sample);
	USART_Init();
	while(1);
	return 0;
}

/*
 if(val == 0)
		{
			DIO_void_SetPinValue(24,1);
			DIO_void_SetPinValue(25,0);
			DIO_void_SetPinValue(26,0);
			DIO_void_SetPinValue(27,0);
			DIO_void_SetPinValue(28,0);
			DIO_void_SetPinValue(29,0);
			DIO_void_SetPinValue(30,0);
			DIO_void_SetPinValue(31,0);
		}
		else if(val >= 0 && val<=1.28 ){
			DIO_void_SetPinValue(24,1);
			DIO_void_SetPinValue(25,1);
			DIO_void_SetPinValue(26,0);
			DIO_void_SetPinValue(27,0);
			DIO_void_SetPinValue(28,0);
			DIO_void_SetPinValue(29,0);
			DIO_void_SetPinValue(30,0);
			DIO_void_SetPinValue(31,0);
		}
		else if(val >1.28 && val<=2.57 ){
			DIO_void_SetPinValue(24,1);
			DIO_void_SetPinValue(25,1);
			DIO_void_SetPinValue(26,1);
			DIO_void_SetPinValue(27,0);
			DIO_void_SetPinValue(28,0);
			DIO_void_SetPinValue(29,0);
			DIO_void_SetPinValue(30,0);
			DIO_void_SetPinValue(31,0);
		}
		else if(val >2.57 && val<=3.855 ){
			DIO_void_SetPinValue(24,1);
			DIO_void_SetPinValue(25,1);
			DIO_void_SetPinValue(26,1);
			DIO_void_SetPinValue(27,1);
			DIO_void_SetPinValue(28,0);
			DIO_void_SetPinValue(29,0);
			DIO_void_SetPinValue(30,0);
			DIO_void_SetPinValue(31,0);
		}
		else if(val >3.855 && val<=5.14 ){
			DIO_void_SetPinValue(24,1);
			DIO_void_SetPinValue(25,1);
			DIO_void_SetPinValue(26,1);
			DIO_void_SetPinValue(27,1);
			DIO_void_SetPinValue(28,1);
			DIO_void_SetPinValue(29,0);
			DIO_void_SetPinValue(30,0);
			DIO_void_SetPinValue(31,0);
		}
		else if(val >5.14 && val<=6.425){
			DIO_void_SetPinValue(24,1);
			DIO_void_SetPinValue(25,1);
			DIO_void_SetPinValue(26,1);
			DIO_void_SetPinValue(27,1);
			DIO_void_SetPinValue(28,1);
			DIO_void_SetPinValue(29,1);
			DIO_void_SetPinValue(30,0);
			DIO_void_SetPinValue(31,0);
		}
		else if(val >6.425 && val<=7.71 ){
			DIO_void_SetPinValue(24,1);
			DIO_void_SetPinValue(25,1);
			DIO_void_SetPinValue(26,1);
			DIO_void_SetPinValue(27,1);
			DIO_void_SetPinValue(28,1);
			DIO_void_SetPinValue(29,1);
			DIO_void_SetPinValue(30,1);
			DIO_void_SetPinValue(31,0);
		}
		else if(val >7.71 && val<=9 ){
			DIO_void_SetPinValue(24,1);
			DIO_void_SetPinValue(25,1);
			DIO_void_SetPinValue(26,1);
			DIO_void_SetPinValue(27,1);
			DIO_void_SetPinValue(28,1);
			DIO_void_SetPinValue(29,1);
			DIO_void_SetPinValue(30,1);
			DIO_void_SetPinValue(31,1);
		}

 */
