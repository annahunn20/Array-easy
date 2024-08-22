#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to move zeros to the end of the array by swapping
void moveZerosToEnd(int arr[], int n) {
    int count = 0;  // Count of non-zero elements
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(&arr[count++], &arr[i]);  // Swap non-zero element with element at index count
        }
    }
}

// Function to push zeros to the end by shifting non-zero elements forward
void pushZerosToEnd(int arr[], int n) {
    int count = 0;  // Count of non-zero elements
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];  // Move non-zero element to the front
        }
    }
    // Fill the remaining positions with zeros
    while (count < n) {
        arr[count++] = 0;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Using moveZerosToEnd function
    moveZerosToEnd(arr, n);
    printf("Array after moving zeros to end: ");
    printArray(arr, n);

    // Resetting the array to the original state
    int arr2[] = {0, 1, 0, 3, 12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Using pushZerosToEnd function
    pushZerosToEnd(arr2, n2);
    printf("Array after pushing zeros to end: ");
    printArray(arr2, n2);

    return 0;
}