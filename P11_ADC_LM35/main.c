#include <io.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>


#define Ref_Voltage (0<<REFS1) | (0<<REFS0)

unsigned int Read_ADC(char ADC_CH);
unsigned char a[6];





void main(void)
{
float Temp = 0;
unsigned char buff[32];
unsigned int ADC_Level = 0;
DDRC = 0xFF;
DDRD = 0xFF;
PORTC = 0;
PORTD = 0;

 // ADC initialization
 lcd_init(16); 
 a[2] = (0 << REFS1) |(1 << REFS0) | (0<<MUX4) |(0<<MUX3) | (0<<MUX2) |(0<<MUX1) |(0<<MUX0);
 ADMUX = (0 << REFS1) |(1 << REFS0) | (0<<MUX4) |(0<<MUX3) | (0<<MUX2) |(0<<MUX1) |(0<<MUX0);
 ADCSRA = (1 << ADEN) | (1 << ADIF) | (1 << ADPS2) |(1 << ADPS1) | (1 << ADPS0);
 while (1)     
 {
    
    ADC_Level = Read_ADC(0);        
    Temp = ((float)ADC_Level * 5 / 1024) ;
    sprintf(buff,"Temp:%2.2f",Temp*100);
    lcd_gotoxy(0,0);
    lcd_puts(buff);


 
 }
}

unsigned int Read_ADC(unsigned char ADC_CH){

    ADMUX = (0xff & Ref_Voltage) |  ADC_CH;
    a[2] |= (0xff & Ref_Voltage) |  ADC_CH;
    delay_us(15);
    ADCSR |= 0x40;//(1<<ADSC)start conversion
    while((ADCSRA & 0x10) == 0); // wait for complite conversion
    ADCSRA |= 0x10; //clear complite conversion flag for 
    return ADCW;
      

}

