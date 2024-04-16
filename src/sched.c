#include <stdio.h>
#include <stdlib.h>
#include "sched.h"
#include "rand.h"
#define MIN_ARRIVAL 0
#define MAX_ARRIVAL 30
#define MIN_BURST_TIME 2
#define MAX_BURST_TIME 16

int last_id = 0;

int compare_job(const void* a, const void* b) {
    job job_a = *((job*) a);
    job job_b = *((job*) b);

    if (job_a.arrival == job_b.arrival) return 0;
    else if (job_a.arrival < job_b.arrival) return -1;
    else return 1;
}

job create_job() {
    // Create job
    job j;

    // Set job attributes
    j.id = ++last_id;
    j.arrival = randrange(0, 20);
    int burst = randrange(MIN_BURST_TIME, MAX_BURST_TIME);
    j.burst = burst;
    j.remaining = burst;
    j.state = UNQUEUED;

    // Return job
    return j;
}

void schedule(job *jobs, int length, int *time_step, int *completed) {
    job *cur_job;
    job *smallest;

    /* job *stopped_job = NULL; */
    for (int i = 0; i < length; i++) {
        // Define job state
        cur_job = &jobs[i];
        if (smallest == NULL) {
            smallest = cur_job;
        }

        // Parse job state
        if (cur_job->state == COMPLETED) {
            /* If the job is already completed, skip it! */
            continue;
        }

        if (cur_job->arrival <= *time_step ||  cur_job->arrival == 0) {
            // Set each arrived job as queued
            cur_job->state = QUEUED;

            // if the job fits the scheduler criteria (shortest remaining), run it
            if (cur_job->remaining < smallest->remaining && cur_job->remaining > 0) {
                // Check if the job was stopped
                if (cur_job != smallest && smallest != NULL && time_step != 0) {
                    smallest->state = QUEUED;
                }

                // Set the new smallest job
                smallest = cur_job;
                smallest->state = RUNNING;
            }
        }
    }

    // Set completion state
    if (smallest->remaining > 0) {
        if (smallest->remaining - 1 == 0) {
            smallest->state = COMPLETED;
            *completed += 1;
        }
        smallest->remaining--;
    }

    // Increment time step;
    *time_step += 1;
}
