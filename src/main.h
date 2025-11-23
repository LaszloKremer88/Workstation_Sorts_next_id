#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>

void seq_count_setup();
void seq_count_loop();
void read_serial();

void wr_next_station(uint8_t id);

#endif