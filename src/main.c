#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "sched.h"
#include "draw.h"
#define DEFAULT_SIZE 10
#define DEFAULT_SLEEP_TIME 5

/* int main(int argc, char *argv[]) { */
int main(int argc, char* argv[]) {
    // Initialize Random
    srand(time(NULL) + getpid());

    // Parse user input for the amount of jobs;
    int size = DEFAULT_SIZE;
    if (argc > 1) {
        size = atoi(argv[1]);
    }

    // Define if timescale will run quickly or slowly
    char* env = getenv("SLEEP_TIME");
    int sleep_time;
    if (env != NULL) {
        sleep_time = atoi(env);
        if (sleep_time <= 0) {
            // Safety check for conversion failure.
            printf("\x1b[31m[ERROR]\x1b[00m %s\n", "Invalid sleep time");
            exit(1);
        }
    } else {
        sleep_time = DEFAULT_SLEEP_TIME;
    }

    // Create random jobs and sort by arrival time;
    job *jobs = (job *)malloc(size * sizeof(job));
    for (int i = 0; i < size; i++) {
        jobs[i] = create_job();
    }
    qsort(jobs, size, sizeof(job), compare_job);

    // Run scheduler
    int timestep = 0;
    int completed = 0;
    while (completed < size) {
        // Clear screen
        clear(); 

        // Print time
        gettime(timestep);

        // Schedule
        schedule(jobs, size, &timestep, &completed);

        // Print all jobs
        pheaders();

        /* printf("--- All jobs ---\n"); */
        for (int i = 0; i < size; i++) {
            print_job(jobs[i]);
        }

        pseparator(true);

        // Print currently completed jobs
        printf("| Completed: %02d/%02d |\n", completed, size);
        printf("--------------------\n");

        // Sleep
        if (completed < size) sleep(sleep_time);
    }

    // Free memory
    free(jobs);

    // Exit
    return 0;
}
