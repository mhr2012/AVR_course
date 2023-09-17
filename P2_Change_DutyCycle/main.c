
#include <mega8.h>
#include <delay.h>
#define Up PINC.0 
#define Down PINC.1 
void main(void)
{

int Ton = 50;
int Toff = 50;
int T = 100;
DDRC.0 = 0;
DDRC.1 = 0;

DDRB.0 = 1;

while (1)
      {
        if(Up == 0 && Ton < 90){
                Ton = Ton + 1;
        }
        if(Down == 0 && Ton >10){
                Ton = Ton - 1; 
        } 
        
        Toff = T- Ton;
        
        PORTB.0 = 1;
        delay_ms(Ton);
        PORTB.0 = 0;
        delay_ms(Toff);
        
        
      }
}
