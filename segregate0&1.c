#include <stdio.h>
#include <stdlib.h>

void segregate0and1(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        while (arr[left] == 0 && left < right)
            left++;
        while (arr[right] == 1 && left < right)
            right--;

        if (left < right) {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array (0s and 1s only):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    segregate0and1(arr, n);

    printf("Array after segregation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
