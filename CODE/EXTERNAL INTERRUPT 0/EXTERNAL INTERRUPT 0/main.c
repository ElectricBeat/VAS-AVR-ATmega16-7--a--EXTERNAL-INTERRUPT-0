/*
 * EXTERNAL INTERRUPT 0.c
 *
 * Created: 29-07-2024 10:55:23
 * Author : SRIDHAR
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*Interrupt Service Routine for INT0*/
ISR(INT0_vect)
{
	PORTC	=	PORTC ^ (1<<0);		/* Toggle PORTC */
	_delay_ms(50);					/* Software debouncing control delay */
}

int main(void)
{
	DDRC	=	DDRC | (1<<0);		/* Make PORTC as output PORT*/
	PORTC	=	PORTC | (0<<0);		/* Make pull down low */

	DDRD	=	DDRD & (~(1<<2));	/* PORTD as input */
	PORTD	=	PORTD | (1<<2);		/* Make pull up high */
	
	GICR	=	1<<INT0;			/* Enable INT0*/
	MCUCR	=	1<<ISC01 | 1<<ISC00;/* Trigger INT0 on rising edge */
	
	sei();							/* Enable Global Interrupt */
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

