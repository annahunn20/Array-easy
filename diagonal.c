#include <stdio.h>
#include <stdlib.h>

int countNonZeroElements(int **A, int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != 0)
                count++;
    return count;
}

int sumAboveLeadingDiagonal(int **A, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            sum += A[i][j];
    return sum;
}

void displayBelowMinorDiagonal(int **A, int n) {
    printf("Elements below the minor diagonal:\n");
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            printf("%d ", A[i][j]);
    printf("\n");
}

int productOfDiagonalElements(int **A, int n) {
    int product = 1;
    for (int i = 0; i < n; i++)
        product *= A[i][i];
    return product;
}

int main() {
    int n = 3;
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    // Initialize the matrix A with some values
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 0; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

    printf("Number of nonzero elements: %d\n", countNonZeroElements(A, n));
    printf("Sum above leading diagonal: %d\n", sumAboveLeadingDiagonal(A, n));
    displayBelowMinorDiagonal(A, n);
    printf("Product of diagonal elements: %d\n", productOfDiagonalElements(A, n));

    for (int i = 0; i < n; i++)
        free(A[i]);
    free(A);

    return 0;
}
