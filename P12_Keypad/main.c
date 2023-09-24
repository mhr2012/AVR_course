

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
                
void keypad(void);

void main(void)
{
lcd_init(16);

DDRD = 0x0F;



keypad();
while (1)
    {

    }
}

void keypad(void){
    int row = 0;
    int colum = -1;
    //int position = 0;
    while(1){
        for(row = 0;row<4;row++){
            PORTD = shift[row]; // PORTD.4 = 1,PORTD.5 = 1,PORTD.6 = 1 , PORTD.7 = 1 , PORTD.0 = 0 , PORTD.1 = 1
            if(PIND.4 == 0){colum = 0;}
            if(PIND.5 == 0){colum = 1;}
            if(PIND.6 == 0){colum = 2;}
            if(PIND.7 == 0){colum = 3;}
            
            if(colum != -1){
                //position = row * 4 + colum;   
                //lcd_putchar(layout[position]);
                lcd_putchar(array[row][colum]);
                colum = -1;  
                while(PIND.4 == 0){};
                while(PIND.5 == 0){};
                while(PIND.6 == 0){};
                while(PIND.7 == 0){};
                
                delay_ms(50);
                
            }
            
            
        }
    
    
    }
    
    
    


}