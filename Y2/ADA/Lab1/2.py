num_jobs = int(input())
jobs = []
for i in range(num_jobs):
    jobs.append(list(map(int, input().split())))


def max_jobs(jobs):
    # Sort the jobs based on finish times
    sorted_jobs = sorted(jobs, key=lambda x: x[1])

    # Initialize variables
    max_jobs_count = 0
    previous_finish_time = 0

    # Iterate through sorted jobs
    for job in sorted_jobs:
        start_time, finish_time = job
        # Check if the current job conflicts with the previous one
        if start_time >= previous_finish_time:
            max_jobs_count += 1
            previous_finish_time = finish_time

    return max_jobs_count


print(max_jobs(jobs))