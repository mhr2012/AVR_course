 
 #include <mega32a.h>

 
 
interrupt [EXT_INT0] void ext_int0_isr(void)
{
 
    PORTA.0 = !PORTA.0;
 }


void main(void){

DDRA.0 = 1;


GICR = (0<<INT1) | (1<<INT0) | (0<<INT2);

MCUCR = (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
#asm("sei")
while (1){

}
}