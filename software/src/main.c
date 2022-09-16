/*
    Copyright 2022 by Michał Gibas
    ------------------------------
    PWS - Plant Watering System
*/

#if !(defined(__AVR_ATmega88PA__) || defined(__AVR_ATmega88P__))
#error "This project supports only atmega88p(a)!"
#endif /* __AVR_ATmega88PA__ */

#define F_CPU 1200000L
#include <avr/io.h>
#include <avr/interrupt.h>

#include "pws.h"

DEFINE_PWS_PCINT_IRQ_HANDLER(PCINT1_vect, PINC, 5)

int main(void) {
    
    init_all();
    close_valve();
    turn_off_status_led();

    while(1) {
        
    }
}