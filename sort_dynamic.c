#include <stdio.h>
#include <stdlib.h>

void sortArray(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int));
    arr[0] = 5, arr[1] = 2, arr[2] = 8, arr[3] = 1, arr[4] = 3;

    sortArray(arr, n);

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
