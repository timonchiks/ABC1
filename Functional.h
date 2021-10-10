//------------------------------------------------------------------------------
// Functional.h - contains description of functional language
//------------------------------------------------------------------------------

#include <stdio.h>
#include "Rand.h"
#include <string.h>

//------------------------------------------------------------------------------

struct Functional {
    enum type{
        strict,
        dinamic
    };
    type tip;
    bool lazy;
    double popularity;
    int year;
    char name[200];
};

// Input parameters from file.
void In(Functional &t, FILE* file);

// Random parameters.
void InRnd(Functional &t);

// Output
void Out(Functional &t, FILE* file);

// Get average of elements
double Average(Functional &t);
