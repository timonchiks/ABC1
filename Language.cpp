//------------------------------------------------------------------------------
// Language.cpp - contains PROCEDURE language
//------------------------------------------------------------------------------

#include <stdexcept>
#include "Language.h"

//------------------------------------------------------------------------------
// Input parameters from file.
Language *In(FILE *file) {
    Language *mat;
    int k;
    fscanf(file, "%d", &k);
    switch (k) {
        case 1:
            mat = new Language;
            mat->k = Language::PROCEDURE;
            In(mat->c, file);
            return mat;
        case 2:
            mat = new Language;
            mat->k = Language::OBJECTIVE;
            In(mat->d, file);
            return mat;
        case 3:
            mat = new Language;
            mat->k = Language::FUNCTIONAL;
            In(mat->t, file);
            return mat;
        default:
            throw std::invalid_argument("Incorrect");
    }

}

// Random values
Language *InRnd() {
    Language *mat;
    int k = rand() % 2 + 1;
    switch (k) {
        case 1:
            mat = new Language;
            mat->k = Language::PROCEDURE;
            InRnd(mat->c);
            return mat;
        case 2:
            mat = new Language;
            mat->k = Language::OBJECTIVE;
            InRnd(mat->d);
            return mat;
        case 3:
            mat = new Language;
            mat->k = Language::FUNCTIONAL;
            InRnd(mat->t);
            return mat;
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Output Language.
void Out(Language &m, FILE *file) {
    switch (m.k) {
        case Language::PROCEDURE:
            Out(m.c, file);
            break;
        case Language::OBJECTIVE:
            Out(m.d, file);
            break;
        case Language::FUNCTIONAL:
            Out(m.t, file);
            break;
        default:
            fprintf(file, "%s", "Incorrect");
    }
}

//------------------------------------------------------------------------------
// Get average
double Average(Language &m) {
    switch (m.k) {
        case Language::PROCEDURE:
            return Average(m.c);
        case Language::OBJECTIVE:
            return Average(m.d);
        case Language::FUNCTIONAL:
            return Average(m.t);
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Swap function
void Swap(Language &m1, Language &m2) {
    Language temp;
    temp = m1;
    m1 = m2;
    m2 = temp;
}