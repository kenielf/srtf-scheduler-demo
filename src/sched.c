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
    job* cur_job = &jobs[0];
    job* smallest = cur_job;
    job* last_stopped = cur_job;

    for (int i = 0; i < length; i++) {
        // Set the current job to check
        cur_job = &jobs[i];

        // Reset smallest if it is completed
        if (smallest->state == COMPLETED) {
            smallest = cur_job;
        }

        // Parse job state
        if (cur_job->state == COMPLETED) {
            // If the job is already completed, skip it.
            continue;
        }

        // If the job has already arrived
        if (cur_job->arrival <= *time_step) {
            // Set the job to queued if it is unqueued
            cur_job->state = QUEUED;
            /* if (cur_job->state == UNQUEUED) cur_job->state = QUEUED; */

            // Check if it is the smallest
            if (cur_job->remaining <= smallest->remaining) {
                // Set the last stopped job
                if (smallest->state == RUNNING) last_stopped = smallest;

                // Update smallest job
                smallest = cur_job;
            }
        }
    }

    if (last_stopped != smallest && last_stopped->remaining > 0) {
        // Set the last stopped job visible
        last_stopped->state = STOPPED;
    }

    // Run smallest
    if (smallest->remaining > 0) {
        smallest->state = RUNNING;
        smallest->remaining--;
    } else {
        smallest->state = COMPLETED;
        *completed += 1;
    }

    // Increment time step;
    *time_step += 1;
}
