/*
    Copyright 2022 by Michał Gibas
*/

#ifndef PWS_H
#define PWS_H

#include "io_control.h"

/* initialize all peripherials */
void init_all();

/* initialize gpio ports */
void init_gpio();

/* initialize clock with a selected prescaler */
void init_clk();

/* initialize pin change interrupts */
void init_pci();

/* define a specific irq handler for pin change interrupt */
#define DEFINE_PWS_PCINT_IRQ_HANDLER(vect, pin_reg, pin) \
ISR(vect) {                     \
    asm volatile("nop");        \
    if(pin_reg & (1 << pin)) {  \
        close_valve();          \
        turn_off_status_led();  \
        return;                 \
    }                           \
    open_valve();               \
    turn_on_status_led();       \
}


#endif //PWS_H