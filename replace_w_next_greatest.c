#include <stdio.h>
#include <stdlib.h>

void rearrangeEvenOdd(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        // Move left index to the right while arr[left] is even
        while (arr[left] % 2 == 0 && left < right) {
            left++;
        }
        // Move right index to the left while arr[right] is odd
        while (arr[right] % 2 == 1 && left < right) {
            right--;
        }

        // If there is a mismatch, swap arr[left] and arr[right]
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
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

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    rearrangeEvenOdd(arr, n);

    printf("Array after rearranging even and odd elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
