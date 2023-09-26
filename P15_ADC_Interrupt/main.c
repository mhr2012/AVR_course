#include <mega32.h>

#include <delay.h>
#include <alcd.h>
#include <stdio.h>


// Voltage Reference: AREF pin
#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))
unsigned int adc_data;
unsigned char buff[32];

// ADC interrupt service routine
interrupt [ADC_INT] void adc_isr(void)
{
    adc_data=ADCW;

}

void main(void)
{

// ADC initialization
// ADC Clock frequency: 62/500 kHz
// ADC Voltage Reference: AREF pin
// ADC Auto Trigger Source: Free Running
ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (1<<ADATE) | (0<<ADIF) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);


lcd_init(16);

ADCSRA |= (1<<ADSC);
#asm("sei")


while (1)
      {
      // Place your code here
      lcd_gotoxy(0,0);
      sprintf(buff,"ADC:%2.2f",(float)adc_data*5/1023);
      lcd_puts(buff);
      }
}