#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED
#include <stdbool.h>
#include "sched.h"

void clear();

void gettime(int timestep);

void pseparator(bool edge);

void pheaders();

void print_job(job j);

#endif /* DRAW_H_INCLUDED */

