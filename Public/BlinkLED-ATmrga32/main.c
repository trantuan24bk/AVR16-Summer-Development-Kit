#include <avr/io.h>
#include <util/delay.h>

int
main (void)
{
    DDRA |= _BV(DDA0); 
	DDRA |= _BV(DDA1); 
    
    while(1) 
    {
        PORTA ^= _BV(PA0);
		PORTA ^= _BV(PA1);
        _delay_ms(900);
    }
}