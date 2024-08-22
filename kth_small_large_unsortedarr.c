#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int kthSmallest(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    return arr[k - 1];
}

int kthLargest(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    return arr[n - k];
}
