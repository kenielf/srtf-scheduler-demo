#ifndef SCHED_H_INCLUDED
#define SCHED_H_INCLUDED
#include <stdbool.h>

typedef enum job_state {
    COMPLETED,
    RUNNING,
    STOPPED,
    QUEUED,
    UNQUEUED
} job_state;

typedef struct job {
    int id;
    int arrival;
    int burst;
    int remaining;
    int completed;
    job_state state;
} job;

int compare_job(const void* a, const void* b);

job create_job();

void schedule(job *jobs, int length, int *time_step, int *completed);

#endif /* SCHED_H_INCLUDED */
