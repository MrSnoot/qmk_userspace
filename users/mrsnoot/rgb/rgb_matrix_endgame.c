#include "mrsnoot.h"

#ifdef RGB_MATRIX_ENABLE

enum colors {
    LILAC = 0,
    ICEBLUE,
    GREEN,
    YELLOW,
    RED,
    ORANGE
};

uint8_t color_values[6][3] = {
    { 10, 0, 50 },  // Lila
    { 0, 40, 50 },  // Eisblau
    { 10, 50, 2 },  // Grün
    { 50, 40, 0 },  // Gelb
    { 50, 0, 0 },   // Rot
    { 50, 15.6, 0 } // Orange
};

#endif