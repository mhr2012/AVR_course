

#include <io.h>
#include <alcd.h>
#include <delay.h>

flash char shift[4] = {0xFE,0xFD,0xFB,0xF7};
flash char layout[16] = {  '7' , '8' , '9' , '/',
                '4' , '5' , '6' , '*',
                '1' , '2' , '3' , '-',
                'c' , '0' , '=' , '+'
            }; 
            
flash char array[4][4] = { 
                        {'7' , '8' , '9' , '/'},
                        {'4' , '5' , '6' , '*'},
                        {'1' , '2' , '3' , '-'},
                        {'c' , '0' , '=' , '+'}
                    }; 
                    

char keypad(void);
                    
interrupt [EXT_INT2] void ext_int2_isr(void)
{
    char c;
    
    c = keypad();
    lcd_putchar(c);
    PORTD = 0xF0;
    

}

           
                

void main(void)
{
lcd_init(16);

DDRD = 0x0F;
PORTD = 0xF0;
GICR|=(0<<INT1) | (0<<INT0) | (1<<INT2);
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);
GIFR=(0<<INTF1) | (0<<INTF0) | (1<<INTF2);


#asm("sei")
while (1)
    {

    }
}

char keypad(void){
    int row = 0;
    int colum = -1;
    //int position = 0;
        for(row = 0;row<4;row++){
            PORTD = shift[row]; // PORTD.4 = 1,PORTD.5 = 1,PORTD.6 = 1 , PORTD.7 = 1 , PORTD.0 = 0 , PORTD.1 = 1
            if(PIND.4 == 0){colum = 0;}
            if(PIND.5 == 0){colum = 1;}
            if(PIND.6 == 0){colum = 2;}
            if(PIND.7 == 0){colum = 3;}
            
            if(colum != -1){
                //position = row * 4 + colum;   
                //lcd_putchar(layout[position]);
                //lcd_putchar(array[row][colum]);
                
                  
                while(PIND.4 == 0){};
                while(PIND.5 == 0){};
                while(PIND.6 == 0){};
                while(PIND.7 == 0){};
                return array[row][colum];
                
                delay_ms(50);
                
            }
            
            
        }
    
    
    
    
    
    


}