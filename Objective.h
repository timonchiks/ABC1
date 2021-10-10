//------------------------------------------------------------------------------
// Objective.h - contains description of objective language
//-----------------------------------------------------------------------------

#include <stdio.h>
#include "Rand.h"
#include <string.h>

//------------------------------------------------------------------------------
// Objective language
struct Objective {
    enum type {
        one,
        many,
        interface
    };
    type tip;
    double popularity;
    int year;
    char name[200];
};

// Input parameters from file.
void In(Objective &d, FILE *file);

// Random parameters.
void InRnd(Objective &d);

// Output parameters.
void Out(Objective &d, FILE *file);

// Get average
double Average(Objective &d);

