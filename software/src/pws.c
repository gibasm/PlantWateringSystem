/*
    Copyright 2022 by Michał Gibas
*/

#include "pws.h"
#include <avr/interrupt.h>
#include <avr/power.h>

void turn_on_status_led() {
    CONTROL_PORT |= (1 << STATUS_LED_PIN);
}

void turn_off_status_led() {
    CONTROL_PORT &= ~(1 << STATUS_LED_PIN);
}

void close_valve() {
    CONTROL_PORT &= ~(1 << VALVE_CONTROL_PIN);
}

void open_valve() {
    CONTROL_PORT |= (1 << VALVE_CONTROL_PIN);
}

void init_all() {
    init_ports();
    init_adc_and_timers();
    // enable interrupts
    sei();
}

void init_adc_and_timers() {
    // disable power saving
    power_adc_enable();
    // choose VREF as reference voltage
    ADMUX |= (1 << REFS0);
    // enable: 1. ADC auto trigger 2. ADC itself 3. ADC interrupts 4. Choose a clock prescaler
    ADCSRA |= (1 << ADATE) | (1 << ADEN) | (1 << ADIE) | (1 << ADPS2);
    // choose timer0 as trigger source
    ADCSRB |= (1 << ADTS2);

    // confiugre timer0
    TCCR0B |= (1 << CS00);
    TIMSK0 |= (1 << TOIE0);
}

void init_ports() {
    DDRB |= (1 << STATUS_LED_PIN) | (1 << VALVE_CONTROL_PIN);
}
