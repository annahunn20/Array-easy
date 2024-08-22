#include <stdio.h>

void findSmallestAndLargest(int arr[], int n, int *smallest, int *largest) {
    *smallest = *largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *smallest) *smallest = arr[i];
        if (arr[i] > *largest) *largest = arr[i];
    }
}

int main() {
    int arr[] = {3, 5, 1, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int smallest, largest;

    findSmallestAndLargest(arr, n, &smallest, &largest);

    printf("Smallest: %d, Largest: %d\n", smallest, largest);
    return 0;
}
