

#include <mega8.h>
#include <delay.h>


void main(void)
{

DDRB.0 = 1;     // PORTB.0 is Output
DDRC.2 = 1;     // PORTC.2 is Output
DDRC.6 = 1;     // PORTC.2 is Output

while (1)
      {
                
        PORTB.0 = 0;    // PORTB.0 is High  
        PORTC.2 = 1;    // PORTB.0 is High   
        PORTC.6 = 0;    // PORTB.0 is High  

        delay_ms(1000);
        PORTB.0 = 1;    // PORTB.0 is High   
        PORTC.2 = 0;    // PORTB.0 is High 
        PORTC.6 = 1;    // PORTB.0 is High  
        delay_ms(1000);

      
      
      }
}
