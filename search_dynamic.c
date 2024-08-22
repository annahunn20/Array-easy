#include <stdio.h>
#include <stdlib.h>

int searchElement(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int n = 5, key = 3;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    int index = searchElement(arr, n, key);

    if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found\n", key);

    free(arr);
    return 0;
}
