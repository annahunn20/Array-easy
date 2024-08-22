#include <stdio.h>

int maxIndexDiff(int arr[], int n) {
    int maxDiff = -1;
    int i, j;

    int LMin[n], RMax[n];

    LMin[0] = arr[0];
    for (i = 1; i < n; i++)
        LMin[i] = arr[i] < LMin[i - 1] ? arr[i] : LMin[i - 1];

    RMax[n - 1] = arr[n - 1];
    for (j = n - 2; j >= 0; j--)
        RMax[j] = arr[j] > RMax[j + 1] ? arr[j] : RMax[j + 1];

    i = 0, j = 0;
    while (j < n && i < n) {
        if (LMin[i] < RMax[j]) {
            maxDiff = (maxDiff > (j - i)) ? maxDiff : (j - i);
            j = j + 1;
        } else
            i = i + 1;
    }

    return maxDiff;
}

int main() {
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxDiff = maxIndexDiff(arr, n);
    printf("Maximum j - i: %d\n", maxDiff);
    return 0;
}
