/*
    Copyright 2022 by Michał Gibas
*/

#ifndef PWS_H
#define PWS_H

#include <avr/io.h>

// define port and ddr registers
#define CONTROL_PORT PORTB
#define CONTROL_DDR DDRB

// define pin numbers for each circuit part
#define STATUS_LED_PIN 1
#define VALVE_CONTROL_PIN 0

void turn_on_status_led();
void turn_off_status_led();

void close_valve();
void open_valve();

void init_all();

void init_adc_and_timers();
void init_ports();


#endif //PWS_H