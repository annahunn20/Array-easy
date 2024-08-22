#include <stdio.h>
#include <stdlib.h>

void findLargestAndCount(int arr[], int n) {
    int max = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            count = 1;
        } else if (arr[i] == max) {
            count++;
        }
    }

    printf("The largest number is %d and it occurs %d times.\n", max, count);
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findLargestAndCount(arr, n);

    free(arr);
    return 0;
}
