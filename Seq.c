#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000  // Minimum array size

void separateEvenOdd(int arr[], int size, int even[], int *evenCount, int odd[], int *oddCount) {
    *evenCount = 0;
    *oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[(*evenCount)++] = arr[i];
        } else {
            odd[(*oddCount)++] = arr[i];
        }
    }
}

int main() {
    int arr[SIZE], even[SIZE], odd[SIZE];
    int evenCount, oddCount;
    
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000;  // Generating random numbers
    }

    clock_t start = clock();
    separateEvenOdd(arr, SIZE, even, &evenCount, odd, &oddCount);
    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sequential Execution Time: %f seconds\n", timeTaken);
    printf("Even Count: %d, Odd Count: %d\n", evenCount, oddCount);

    return 0;
}
