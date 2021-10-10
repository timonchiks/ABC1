//--------------------------------------------------------------------------
// Procedure.h - contains description of common matrix.
//--------------------------------------------------------------------------

#include <stdio.h>
#include "Rand.h"
#include <string.h>


//--------------------------------------------------------------------------
// Procedure language
struct Procedure { //procedure
    bool abstract_type;
    double popularity;
    int year;
    char name[200];
};

// Input parameters from file.
void In(Procedure &c, FILE *file);

// Random parameters.
void InRnd(Procedure &c);

// Output parameters.
void Out(Procedure &c, FILE *file);

// Get average
double Average(Procedure &c);
