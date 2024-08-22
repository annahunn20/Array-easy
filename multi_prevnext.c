#include <stdio.h>
#include <stdlib.h>

void multiplyPrevNext(int arr[], int n) {
    if (n <= 1) return;

    int prev = arr[0];
    arr[0] = arr[0] * arr[1];

    for (int i = 1; i < n - 1; i++) {
        int curr = arr[i];
        arr[i] = prev * arr[i + 1];
        prev = curr;
    }

    arr[n-1] = prev * arr[n-1];
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

    multiplyPrevNext(arr, n);

    printf("Array after replacing with multiplication of previous and next elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
