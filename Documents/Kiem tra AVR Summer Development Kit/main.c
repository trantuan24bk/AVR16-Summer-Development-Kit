#include <avr/io.h>
#include <util/delay.h>

#define sbi(x,y) (x |= _BV(y)) 					// set bit
#define cbi(x,y) (x &= ~(_BV(y))) 				// clear bit
#define tbi(x,y) (x ^= _BV(y)) 					// toggle bit
#define is_high(x,y) ((x & _BV(y)) == _BV(y)) 	// (for input) checks if the input is high (Logic 1)

void main (void)
{
    DDRA = 0xFF;			// Dir Output
	DDRB = 0xFF;			// Dir Output
    DDRC = 0xFF;			// Dir Output
    DDRD = 0xFF;			// Dir Output
    
    DDRD &= ~_BV(PD2);		// Input button
    
    while(1) 
    {
    	if(is_high(PIND,PD2))
    	{
			PORTA = 0x00;
			PORTB = 0x00;
			PORTC = 0x00;
			PORTD = 0x00;
			_delay_ms(300);
			
			PORTA = 0xff;
			PORTB = 0xff;
			PORTC = 0xff;
			PORTD = 0xff;
			_delay_ms(300);			
    	}
		else
		{
			PORTA = 0x00;
			PORTB = 0x00;
			PORTC = 0x00;
			PORTD = 0x00;
		}		
    }
}