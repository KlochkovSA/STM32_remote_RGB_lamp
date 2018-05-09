#include "STM32F0xx.h"

// Quick and dirty delay
static void delay (unsigned int time) {
    for (unsigned int i = 0; i < time; i++)
        for (volatile unsigned int j = 0; j < 2000; j++);
}

int main (void) {
    // Turn on the GPIOA peripheral
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // Put pin in general purpose output mode (B01)
    GPIOA->MODER |= GPIO_MODER_MODER4_0;

    while (1) {
        // Reset the bit for port A4
        GPIOA->BSRR = GPIO_BSRR_BR_4;

        delay(500);

        // Set the bit for port A4
        GPIOA->BSRR = GPIO_BSRR_BS_4;

        delay(500);
    }
}
