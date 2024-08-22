#include <stdio.h>
#include <stdlib.h>

void printSparseMatrix(int **matrix, int nonZeroElements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= nonZeroElements; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}
int **transposeSparseMatrix(int **matrix, int nonZeroElements) {
    int **transpose = (int **)malloc((nonZeroElements + 1) * sizeof(int *));
    for (int i = 0; i <= nonZeroElements; i++) {
        transpose[i] = (int *)malloc(3 * sizeof(int));
    }
    transpose[0][0] = matrix[0][1];
    transpose[0][1] = matrix[0][0];
    transpose[0][2] = matrix[0][2];
    int k = 1; 
    for (int i = 0; i < matrix[0][1]; i++) {
        for (int j = 1; j <= nonZeroElements; j++) {
            if (matrix[j][1] == i) {
                transpose[k][0] = matrix[j][1];
                transpose[k][1] = matrix[j][0];
                transpose[k][2] = matrix[j][2];
                k++;
            }
        }
    }
    return transpose;
}

int main() {
    int rows, cols, nonZeroElements;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &nonZeroElements);
    // Allocate memory for the sparse matrix
    int **matrix = (int **)malloc((nonZeroElements + 1) * sizeof(int *));
    for (int i = 0; i <= nonZeroElements; i++) {
        matrix[i] = (int *)malloc(3 * sizeof(int));
    }
    // Initialize the sparse matrix
    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = nonZeroElements;

    printf("Enter the row index, column index, and value of the non-zero elements:\n");
    for (int i = 1; i <= nonZeroElements; i++) {
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }

    printf("Original Sparse Matrix:\n");
    printSparseMatrix(matrix, nonZeroElements);

    int **transpose = transposeSparseMatrix(matrix, nonZeroElements);

    printf("\nTranspose Sparse Matrix:\n");
    printSparseMatrix(transpose, nonZeroElements);

    return 0;
}
