#include <stdio.h>

int findSingleOccurrence(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
