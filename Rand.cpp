//------------------------------------------------------------------------------
// Rand.cpp - Random functions.
//------------------------------------------------------------------------------

#include <stdlib.h>
#include "Rand.h"

// Random bool
bool bRandom() {
    return rand() % 2;
}

// Random double from 0.00 to 100.00
double dRandom() {
    return ((rand() % 10000) / 100.0);
}

//Random year from 1900 to 2021
int yRandom() {
    return (1900 + rand() % 122);
}
