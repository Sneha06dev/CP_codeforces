#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int testSizes[] = {10, 50, 100, 150, 200, 250, 300, 500, 1000};
    int numTests = sizeof(testSizes) / sizeof(testSizes[0]);

    FILE *file = fopen("binary_search_results.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int t = 0; t < numTests; t++) {
        int n = testSizes[t];
        int arr[n];

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int target = n;

        clock_t start = clock();
        int result = binarySearch(arr, n, target);
        clock_t end = clock();

        double elapsedTime = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(file, "%d %.10f\n", n, elapsedTime);
    }

    fclose(file);
    printf("Execution times saved to binary_search_results.txt\n");

    return 0;
}
