/*
 * main.c
 *
 * Created: 9/14/2022 3:37:41 PM
 *  Author: win-10
 */ 

#include <xc.h>
#include "Library/global.h"
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRD |= 0x1f;
	PORTD |= 0x00;
	cbi(DDRA,0);
	ADMUX |= (1<<MUX0);
	ADCSRA |= (1<<ADEN) | (1<<ADIF) | (1<<ADPS1) | (1<<ADPS0);
		
	uint16_t i=0;
    while(1)
    {
			sbi(ADCSRA,ADSC);
			while(CHECKBIT(ADCSRA,ADIF) != 1);
			sbi(ADCSRA,ADIF);
			i = ADCW;
		
		if(i > 193 && i<225){
			
			CHECKBIT(PORTD,4) ? (cbi(PORTD,4)) : (sbi(PORTD,4)) ;
			_delay_ms(300);
		
			
		}
		else if(i > 385 && i<433){
			
			CHECKBIT(PORTD,3) ? (cbi(PORTD,3)) : (sbi(PORTD,3)) ;
			_delay_ms(300);
			
			
		}
		else if(i > 585 && i<633){
			
			CHECKBIT(PORTD,2) ? (cbi(PORTD,2)) : (sbi(PORTD,2)) ;
			_delay_ms(300);
			
		}
		else if(i > 788 && i<822){
			
			CHECKBIT(PORTD,1) ? (cbi(PORTD,1)) : (sbi(PORTD,1)) ;
			_delay_ms(300);
			
		}
		else if(i > 1000){
			
			CHECKBIT(PORTD,0) ? (cbi(PORTD,0)) : (sbi(PORTD,0)) ;
			_delay_ms(300);
			
		}
    }
}