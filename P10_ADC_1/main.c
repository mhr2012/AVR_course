#include <io.h>
void main(void)
{
 DDRC = 0xFF;
 DDRD = 0xFF;
 PORTC = 0;
 PORTD = 0;

 // ADC initialization
 ADMUX = (0 << REFS1) |(1 << REFS0) | (0<<MUX4) |(0<<MUX3) | (0<<MUX2) |(0<<MUX1) |(0<<MUX0);
 ADCSRA = (1 << ADEN) | (1 << ADIF) | (1 << ADPS1) | (1 << ADPS0);
 while (1)
 {
    ADCSRA |= ((1 << ADSC) | (1 << ADIF));
    while ((ADCSRA & (1 << ADIF)) == 0); //1 << ADIF ---> 0x10,0b00010000;; 
    PORTD = (unsigned char)ADCW;
    PORTC = (ADCW >> 8);
 }
}