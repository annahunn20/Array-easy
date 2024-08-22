#include <stdio.h>

// Insertion of one element in the given array
void insertElement(int arr[], int size, int capacity, int pos, int element) {
    if (size == capacity) {
        printf("Array is full\n");
        return;
    }
    if (pos < 0 || pos > size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
}

// Deleting one element in the given array
void deleteElement(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0; // Set the last element to 0 after shifting
}

// Searching one element in the given array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Printing the sum of elements in the array
int sumElements(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Printing the array
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 10;
    int arr[capacity];
    int size = 0;
    while (1) {
        printf("Menu:\n");
        printf("1. Insert element at a given position\n");
        printf("2. Delete element at a given position\n");
        printf("3. Search for an element\n");
        printf("4. Find the sum of elements\n");
        printf("5. Print the array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter position: ");
                int pos;
                scanf("%d", &pos);
                printf("Enter element: ");
                int element;
                scanf("%d", &element);
                if (size < capacity) {
                    insertElement(arr, size, capacity, pos, element);
                    size++;
                } else {
                    printf("Array is full, cannot insert element.\n");
                }
                break;
            }
            case 2: {
                printf("Enter position: ");
                int pos;
                scanf("%d", &pos);
                if (size > 0) {
                    deleteElement(arr, size, pos);
                    size--;
                } else {
                    printf("Array is empty, cannot delete element.\n");
                }
                break;
            }
            case 3: {
                printf("Enter element to search: ");
                int element;
                scanf("%d", &element);
                int index = searchElement(arr, size, element);
                if (index != -1) {
                    printf("Element found at position %d\n", index);
                } else {
                    printf("Element not found\n");
                }
                break;
            }
            case 4: {
                if (size > 0) {
                    int sum = sumElements(arr, size);
                    printf("Sum of elements is %d\n", sum);
                } else {
                    printf("Array is empty\n");
                }
                break;
            }
            case 5: {
                printArray(arr, size);
                break;
            }
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
