#include <stdio.h>
#include <stdlib.h>

struct Element {
    int value, freq;
};

int compare(const void *a, const void *b) {
    return ((struct Element *)b)->freq - ((struct Element *)a)->freq;
}

void sortByFrequency(int arr[], int n) {
    struct Element elements[101] = {0};
    for (int i = 0; i < n; i++) {
        elements[arr[i]].value = arr[i];
        elements[arr[i]].freq++;
    }
    qsort(elements, 101, sizeof(struct Element), compare);
    printf("Sorted by frequency: ");
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < elements[i].freq; j++)
            printf("%d ", elements[i].value);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 6, 2, 4, 4, 3, 2, 6, 6, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortByFrequency(arr, n);
    return 0;
}
