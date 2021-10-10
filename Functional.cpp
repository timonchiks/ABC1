#include "Functional.h"

//------------------------------------------------------------------------------
// Input parameters from file.
void In(Functional &t, FILE *file) {
    fscanf(file, "%100s", &t.name);
    fscanf(file, "%i", &t.year);
    fscanf(file, "%lf", &t.popularity);
    fscanf(file, "%i", &t.lazy);
    int oy;
    fscanf(file, "%i", &oy);
    if (oy == 1) {
        t.tip = Functional::strict;
    } else if (oy == 2) {
        t.tip = Functional::dinamic;
    } else {
        printf("Error\n");
    }
}

// Random parameters.
void InRnd(Functional &t) {
    int k = rand() % 2;
    if (k == 0) {
        t.tip = Functional::strict;
    } else {
        t.tip = Functional::dinamic;
    }
    t.popularity = dRandom();
    t.lazy = bRandom();
    t.year = yRandom();
    for (int i = 0; i < 100; i++) {
        t.name[i] = 'a' + rand() % 26;
    }
}

//------------------------------------------------------------------------------
// Output
void Out(Functional &t, FILE *file) {
    char *tips;
    if (t.tip == Functional::strict) {
        tips = "strict";
    } else if (t.tip == Functional::dinamic) {
        tips = "dinamic";
    } else {
        tips = "Error\n";
    }
    fprintf(file, "It is objective language: Have type = %s\n", tips);
    fprintf(file, ". Popularity = %lf\n", t.popularity);
    fprintf(file, ". Year = %i\n", t.year);
    fprintf(file, ". Lazy = %i\n", t.lazy);
    fprintf(file, ". Parameter = %lf\n", Average(t));
}

//------------------------------------------------------------------------------
// Get average of elements
double Average(Functional &t) {
    return (t.year * 1.0 / strlen(t.name));
}
