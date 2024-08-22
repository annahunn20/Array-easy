#include <stdio.h>

void nextGreatest(int arr[], int n) {
    int maxFromRight = arr[n-1];
    arr[n-1] = -1;

    for (int i = n-2; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = maxFromRight;
        if (temp > maxFromRight)
            maxFromRight = temp;
    }
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreatest(arr, n);

    printf("Array after replacement: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
