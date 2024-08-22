#include <stdio.h>
#include <stdlib.h>

void findElementsBetween(int *arr, int n, int a, int b) {
    int count = 0;
    printf("Elements between %d and %d: ", a, b);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= a && arr[i] <= b) {
            printf("%d ", arr[i]);
            count++;
        }
    }
    printf("\nCount: %d\n", count);
}

int main() {
    int arr[] = {1, 2, 2, 7, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a = 2, b = 5;

    findElementsBetween(arr, n, a, b);

    return 0;
}
