
#include <io.h>
#include <alcd.h>
#include <delay.h>
void main(void)
{

int jahat = 1;
int i = 0;
int x = 0;
int y = 0;
lcd_init(16);
while (1)
    {
     
        lcd_clear();  
        
        lcd_gotoxy(x,y);
        y = i / 16;
        x = i - y*16;  
        if(i == 31)jahat = -1;
        if(i == 0)jahat = 1;
        i = i + jahat;  
        lcd_puts("a");
        delay_ms(200);



    }
}
