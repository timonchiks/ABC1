//------------------------------------------------------------------------------
// Objective.cpp - implementation of Objective.h.
//------------------------------------------------------------------------------

#include <stdexcept>
#include "Objective.h"

//------------------------------------------------------------------------------
// Input parameters from file.
void In(Objective &d, FILE *file) {
    fscanf(file, "%100s", &d.name);
    fscanf(file, "%i", &d.year);
    fscanf(file, "%lf", &d.popularity);
    int h;
    fscanf(file, "%i", &h);
    if (h == 1) {
        d.tip = Objective::one;
    } else if (h == 2) {
        d.tip = Objective::many;
    } else if (h == 3) {
        d.tip = Objective::interface;
    } else {
        printf("Error\n");
    }
}

// Random parameters.
void InRnd(Objective &d) {
    int k = rand() % 3;
    if (k == 0) {
        d.tip = Objective::one;
    } else if (k == 1) {
        d.tip = Objective::many;
    } else {
        d.tip = Objective::interface;
    }
    d.popularity = dRandom();
    d.year = yRandom();
    for(int i = 0; i < 100; i++){
        d.name[i] = 'a' + rand() % 26;
    }
}

//------------------------------------------------------------------------------
// Output parameters.
void Out(Objective &d, FILE *file) {
    char *tips;
    if (d.tip == Objective::one) {
        tips = "one";
    } else if (d.tip == Objective::many) {
        tips = "many";
    } else if (d.tip = Objective::interface) {
        tips = "interface";
    } else {
        tips = "Error\n";
    }
    fprintf(file, "It is objective language: Have type = %s\n", tips);
    fprintf(file, ". Popularity = %lf\n", d.popularity);
    fprintf(file, ". Year = %i\n", d.year);
    fprintf(file, ". Parameter = %lf\n", Average(d));
}

//------------------------------------------------------------------------------
// Get average
double Average(Objective &d) {
    return (d.year * 1.0 / strlen(d.name));
}
