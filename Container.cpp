//------------------------------------------------------------------------------
// Container.cpp - Container handling functions.
//------------------------------------------------------------------------------

#include "Container.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Initialization of Container.
void Init(Container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Clear data from Container.
void Clear(Container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Input Container's data.
void In(Container &c, FILE *file) {
    while (!feof(file)) {
        if ((c.cont[c.len] = In(file)) != nullptr) {
            c.len++;
        }
    }


}

// Random input to Container.
void InRnd(Container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Output Container data.
void Out(Container &c, FILE *file) {
    fprintf(file, "%s%d%s", "Container contains ", c.len, " elements.");
    for (int i = 0; i < c.len; i++) {
        fprintf(file, "%s", "\n");
        Out(*(c.cont[i]), file);
    }
}

//------------------------------------------------------------------------------
// Shaker sort for container.
void ShakerSort(Container &c, int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (Average(*c.cont[i]) < Average(*c.cont[i + 1])) {
                Swap(*c.cont[i], *c.cont[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (Average(*c.cont[i]) < Average(*c.cont[i + 1])) {
                Swap(*c.cont[i], *c.cont[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}