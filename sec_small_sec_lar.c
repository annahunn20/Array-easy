#include <stdio.h>
#include <limits.h>

void findSecondSmallestAndLargest(int arr[], int n, int *secondSmallest, int *secondLargest) {
    if (n < 2) {
        *secondSmallest = -1;
        *secondLargest = -1;
        return;
    }

    int smallest = INT_MAX, largest = INT_MIN;
    int secondSmallestFound = 0, secondLargestFound = 0;
    *secondSmallest = INT_MAX;
    *secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            *secondSmallest = smallest;
            smallest = arr[i];
            secondSmallestFound = 1;
        } else if (arr[i] != smallest && arr[i] < *secondSmallest) {
            *secondSmallest = arr[i];
            secondSmallestFound = 1;
        }

        if (arr[i] > largest) {
            *secondLargest = largest;
            largest = arr[i];
            secondLargestFound = 1;
        } else if (arr[i] != largest && arr[i] > *secondLargest) {
            *secondLargest = arr[i];
            secondLargestFound = 1;
        }
    }

    if (!secondSmallestFound || *secondSmallest == INT_MAX) *secondSmallest = -1;
    if (!secondLargestFound || *secondLargest == INT_MIN) *secondLargest = -1;
}

int main() {
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int secondSmallest, secondLargest;

    findSecondSmallestAndLargest(arr, n, &secondSmallest, &secondLargest);

    if (secondSmallest != -1 && secondLargest != -1) {
        printf("Second Smallest: %d\n", secondSmallest);
        printf("Second Largest: %d\n", secondLargest);
    } else {
        printf("Array does not have enough unique elements to find second smallest or second largest.\n");
    }

    return 0;
}
