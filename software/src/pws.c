/*
    Copyright 2022 by Michał Gibas
*/

#include "pws.h"
#include <avr/interrupt.h>
#include <avr/power.h>

void init_all() {
    init_clk();
    init_gpio();
    init_pci();

    // enable interrupts
    sei();
}

void init_clk() {
    /* CLK/64 prescaler */
    CLKPR |= (1 << CLKPCE) | (1 << CLKPS2) | (1 << CLKPS1);
}

void init_gpio() {
    DDRB |= (1 << STATUS_LED_PIN) | (1 << VALVE_CONTROL_PIN);
}

void init_pci() {
    /* configure PC5 pin for PCINT1 irq */
    PCMSK1 |= (1 << 5);
    PCICR |= (1 << PCIE1);
}