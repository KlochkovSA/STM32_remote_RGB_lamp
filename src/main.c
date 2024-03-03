#include "stm32f0xx.h"

// Quick and dirty delay
static void delay (unsigned int time) {
    for (volatile unsigned int i = 0; i < time; i++)
        for (volatile unsigned int j = 0; j < 2000; j++);
}




void blink_red(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER6_0;
    while (1) {
        GPIOA->BSRR = GPIO_BSRR_BS_6;
        delay(500);
        GPIOA->BSRR = GPIO_BSRR_BR_6;
        delay(500);
    }
}

void blink_green() {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER7_0;
    while (1) {
        GPIOA->BSRR = GPIO_BSRR_BS_7;
        delay(500);
        GPIOA->BSRR = GPIO_BSRR_BR_7;
        delay(500);
    }
}

void blink_blue() {
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    GPIOB->MODER |= GPIO_MODER_MODER1_0;
    while (1) {
        GPIOB->BSRR = GPIO_BSRR_BS_1;
        delay(500);
        GPIOB->BSRR = GPIO_BSRR_BR_1;
        delay(500);
    }
}

void blink_RG(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER1_0;
    while (1) {
        GPIOA->BSRR = GPIO_BSRR_BS_7 + GPIO_BSRR_BR_6 + GPIO_BSRR_BS_1;
        delay(500);
        GPIOA->BSRR = GPIO_BSRR_BR_7 + GPIO_BSRR_BS_6 + GPIO_BSRR_BS_1;
        delay(500);
    }
}

void blink_RG_WC(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= // GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0 |
                        GPIO_MODER_MODER9_0 |
                        GPIO_MODER_MODER10_0 |
                        GPIO_MODER_MODER1_0;
    while (1) {
        GPIOA->BSRR = //GPIO_BSRR_BS_7 + GPIO_BSRR_BR_6 +
                     GPIO_BSRR_BS_9
                     + GPIO_BSRR_BR_10
                     + GPIO_BSRR_BS_1;
        delay(2000);
        GPIOA->BSRR = //GPIO_BSRR_BR_7 + GPIO_BSRR_BS_6 +
                     GPIO_BSRR_BR_9
                     + GPIO_BSRR_BS_10
                     + GPIO_BSRR_BS_1;
        delay(2000);
    }
}
    


void warm_light(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER10_0 | GPIO_MODER_MODER1_0;
    GPIOA->BSRR = GPIO_BSRR_BS_10 + GPIO_BSRR_BS_1;
}

//  не работает GPIO_MODER_MODER9_0 PA9 холодный цвет
void cold_light(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER9_0 | GPIO_MODER_MODER1_0;
    GPIOA->BSRR = GPIO_BSRR_BS_9 + GPIO_BSRR_BS_1;
}

int main (void) {
    
    
    // blink_RG();

    warm_light();
    //cold_light();

    // blink_RG_WC();

    // Return 0 to satisfy compiler
    return 0;
}
