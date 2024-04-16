#include <stdlib.h>

int randrange(int min, int max) {
    // Generates a pseudo-random value between min and max
    return (max < min || max == 0)? 0: (rand() % ((max + 1) - min)) + min;
}

