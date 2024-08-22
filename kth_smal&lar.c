#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findKthElements(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    printf("The %dth smallest element is %d\n", k, arr[k-1]);
    printf("The %dth largest element is %d\n", k, arr[n-k]);
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    findKthElements(arr, n, k);

    free(arr);
    return 0;
}
