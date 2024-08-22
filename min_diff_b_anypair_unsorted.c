#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Include limits.h to use INT_MAX

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int findMinDifference(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare); // Sort the array
    int minDiff = INT_MAX; // Use INT_MAX instead of __INT_MAX__
    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

int main() {
    int arr[] = {1, 5, 3, 19, 18, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum difference: %d\n", findMinDifference(arr, n));
    return 0;
}
