#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 100000  // Minimum size of the array

void parallel_count_and_separate(int *arr, int size, int *evens, int *odds, int *even_count, int *odd_count, int num_threads) {
    int local_even_count = 0, local_odd_count = 0;

    // Set number of threads
    omp_set_num_threads(num_threads);

    #pragma omp parallel
    {
        int *private_evens = (int *)malloc(size * sizeof(int));
        int *private_odds = (int *)malloc(size * sizeof(int));
        int private_even_count = 0, private_odd_count = 0;

        #pragma omp for nowait schedule(dynamic)
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) {
                private_evens[private_even_count++] = arr[i];
            } else {
                private_odds[private_odd_count++] = arr[i];
            }
        }

        // Merging local results into shared arrays
        #pragma omp critical
        {
            for (int i = 0; i < private_even_count; i++) {
                evens[local_even_count++] = private_evens[i];
            }
            for (int i = 0; i < private_odd_count; i++) {
                odds[local_odd_count++] = private_odds[i];
            }
        }

        free(private_evens);
        free(private_odds);
    }

    *even_count = local_even_count;
    *odd_count = local_odd_count;
}


int main(int argc, char *argv[]) {
    srand(time(0));
    int arr[N];

    // Fill array with random numbers
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0-9999
    }

    int *evens = (int *)malloc(N * sizeof(int));
    int *odds = (int *)malloc(N * sizeof(int));
    int even_count = 0, odd_count = 0;

    // Default to maximum threads if not provided
    int num_threads = omp_get_max_threads();
    if (argc > 1) {
        num_threads = atoi(argv[1]); // Get user-specified thread count
    }

    printf("Using %d threads for parallel execution.\n", num_threads);

    double start = omp_get_wtime();

    parallel_count_and_separate(arr, N, evens, odds, &even_count, &odd_count, num_threads);

    double end = omp_get_wtime();
    double time_taken = (end - start) * 1000;  // Convert to milliseconds

    printf("Parallel Execution Time: %.2f ms\n", time_taken);
    printf("Even Numbers: %d, Odd Numbers: %d\n", even_count, odd_count);

    free(evens);
    free(odds);
    return 0;
}

