#include "io_control.h"

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