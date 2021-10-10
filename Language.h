//------------------------------------------------------------------------------
// Language.h - contains definition languages
//------------------------------------------------------------------------------

#include "Procedure.h"
#include "Objective.h"
#include "Functional.h"

//------------------------------------------------------------------------------
// Structure summarizing all shapes.
struct Language {
    // Values of keys for different languages.
    enum key {PROCEDURE, OBJECTIVE, FUNCTIONAL};
    key k; // Key.
    union {
        Procedure c;
        Objective d;
        Functional t;
    };
};

// Input
Language *In(FILE* file);

// Random input
Language *InRnd();

// Output
void Out(Language &m, FILE* file);

// Get square
double Average(Language &m);

// Swap function
void Swap(Language &m1, Language &m2);
