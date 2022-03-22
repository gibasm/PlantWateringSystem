/*
    Copyright 2022 by Michał Gibas
    ------------------------------
    PWS - Plant Watering System
*/

#define F_CPU 1200000L
#include <avr/io.h>
#include <avr/interrupt.h>

#include "pws.h"

const uint16_t THRESHOLD_VALUE = 0x0240;

ISR(ADC_vect) {
    uint16_t value = ADCL;
    value |= ((ADCH & 0x02) << 8);
    if(value >= THRESHOLD_VALUE) {
        turn_on_status_led();
        open_valve();
    } else {
        turn_off_status_led();
        close_valve();
    }
}

int main(void) {
    
    init_all();
    turn_off_status_led();

    while(1) {
        
    }
}