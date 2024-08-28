#include <8051.h>

#define LED_PIN P1_0  
#define BUTTON_PIN P3_0 

void blink_led(void) {
    LED_PIN = 1; 
    delay(500);  
    LED_PIN = 0; 
    delay(500);  
}

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 500; j++); 
    }
}

void main(void) {
    P1 = 0x00; 
    P3 = 0xFF; 

    while (1) {
        if (BUTTON_PIN == 0) { 
            printf("Button pressed!\n");

            blink_led();
        } else {
            LED_PIN = 0;
        }
    }
}

