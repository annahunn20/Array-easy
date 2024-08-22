#include <stdio.h>

int countStrictlyIncreasing(int arr[], int n) {
    int count = 0, len = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            len++;
        else {
            count += (len * (len - 1)) / 2;
            len = 1;
        }
    }
    if (len > 1) count += (len * (len - 1)) / 2;
    return count;
}
