#include <stdio.h>

int main() {
    int n, index;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter index to find element: ");
    scanf("%d", &index);

    if (index >= 0 && index < n)
        printf("Element at index %d: %d\n", index, arr[index]);
    else
        printf("Index out of bounds\n");

    return 0;
}
