#ifndef RANDOM_TOOLS_H
#define RANDOM_TOOLS_H

#include <stdint.h>

float random_float(float min, float max);
uint32_t random_int(uint32_t min, uint32_t max);
void print_bin(uint32_t x);

#endif //RANDOM_TOOLS_H