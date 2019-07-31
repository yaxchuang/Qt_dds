#ifndef HENON_TOOLS_H
#define HENON_TOOLS_H
#include <stdint.h>

// Henon
#define alpha 1.4
#define beta 0.3

typedef union keys
{
    uint32_t henon_int;
    float henon_float;
} KEYS;

#endif // HENON_TOOLS_H