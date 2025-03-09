#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 1000  // Minimum size of the array

int main(int argc, char *argv[]) {
    srand(time(0));
    int arr[N];

    // Fill array with random numbers
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0-9999
    }

    printf("Random array of size %d generated successfully.\n", N);
    return 0;
}
