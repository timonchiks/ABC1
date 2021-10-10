//------------------------------------------------------------------------------
// Procedure.cpp - implementation of Procedure.h.
//------------------------------------------------------------------------------

#include "Procedure.h"

//------------------------------------------------------------------------------
// Input parameters from file.
void In(Procedure &c, FILE *file) {
    fscanf(file, "%100s", &c.name);
    fscanf(file, "%i", &c.year);
    fscanf(file, "%lf", &c.popularity);
    fscanf(file, "%i", &c.abstract_type);
}

// Random parameters.
void InRnd(Procedure &c) {
    c.abstract_type = bRandom();
    c.popularity = dRandom();
    c.year = yRandom();
    int k = 0;
    for(char i = 'a'; i < 'z'; i++){
        c.name[k] = i;
        k++;
    }
}

//------------------------------------------------------------------------------
// Output
void Out(Procedure &c, FILE *file) {
    if (c.abstract_type){

    }
    fprintf(file, "It is Procedure language: Have abstract type %i\n", c.abstract_type);
    fprintf(file, ". Popularity = %lf\n", c.popularity);
    fprintf(file, ". Year = %i\n", c.year);
    fprintf(file, ". Parameter = %lf", Average(c));
}

//------------------------------------------------------------------------------
// Get average
double Average(Procedure &c) {
    return (c.year * 1.0 / strlen(c.name));
}
