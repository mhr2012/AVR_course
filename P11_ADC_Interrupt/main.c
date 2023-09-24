#include <mega32.h>
#include <stdio.h>

#include <delay.h>
#include <alcd.h>
#include <delay.h>

// Voltage Reference: AREF pin
#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))
unsigned int adc_data;

// ADC interrupt service routine
interrupt [ADC_INT] void adc_isr(void)
{
// Read the AD conversion result
adc_data=ADCW;
// Place your code here

}

void main(void)
{

char buff[32];
lcd_init(16);


// ADC initialization
// ADC Clock frequency: 62/500 kHz
// ADC Voltage Reference: AREF pin
// ADC Auto Trigger Source: ADC Stopped
ADMUX=ADC_VREF_TYPE ;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);


// Global enable interrupts
#asm("sei")

while (1)
      {
        
        sprintf(buff,"ADC:%2.2f",(float)adc_data);
        lcd_puts(buff); 
        lcd_gotoxy(0,0);
        
      
      
      }
}



