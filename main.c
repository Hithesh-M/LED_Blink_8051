#include <reg51.h> 

#define P1 (*(volatile unsigned char *)0x90)  
#define P3 (*(volatile unsigned char *)0xB0)  

void blink_led(void);
void delay(unsigned int);

void main() {

    P1 = 0x00;  
    P3 = 0xFF;

    while (1) {
        if ((P3 & 0x01) == 0) {  
            blink_led(); 
        } else {
            P1 &= ~0x01;
        }
    }
}

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 500; j++) {
        }
    }
}

void blink_led(void)
{
    P1 |= 0x01;
    delay(500);
    P1 &= ~0x01;
    delay(500);
}
