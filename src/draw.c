#include <stdio.h>
#include <time.h>
#include "sched.h"
#ifdef _WIN32
#include <stdlib.h>
#define CLEAR() system("cls")
#else
#define CLEAR() printf("\x1b[2J\x1b[H"); /* ANSI Black magic */
#endif

void clear() {
    // Platform dependent clear commands
    CLEAR();
}

void gettime(int timestep){
    // Store time info
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime (&rawtime);
    printf(
        "Local Time: %d:%02d:%02d | Timestep: %d\n",
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, timestep
    );
    /* printf("Current local time and date: %s", asctime(timeinfo)); */
}

void pseparator(bool edge) {
    if (edge) {
        printf("----------------------------------------------------\n");
    } else {
        printf("|--------|-------------|-----------|---------------|\n");
    }
}

void pheaders() {
    // Prints headers
    pseparator(true);
    printf("|   ID   |   Arrival   |   Burst   |   Remaining   |\n");
    pseparator(false);
}

void print_job(job j) {
    char *state_color;
    switch (j.state) {
        case COMPLETED:
            state_color = "32m";
            break;
        case RUNNING:
            state_color = "34m";
            break;
        case STOPPED:
            state_color = "31m";
            break;
        case QUEUED:
            state_color = "33m";
            break;
        case UNQUEUED:
            state_color = "30m";
            break;
    }
    printf(
        "| \x1b[%sJob %02d | Arrival: %02d | Burst: %02d | Remaining: %02d \x1b[00m|\n", 
        state_color, j.id, j.arrival, j.burst, j.remaining
    );
}
