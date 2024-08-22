#include <stdio.h>
#include <stdlib.h>

int compareAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void sortRows(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        qsort(matrix[i], n, sizeof(int), compareAsc);
    }
}

void sortCols(int **matrix, int m, int n) {
    for (int j = 0; j < n; j++) {
        int *col = (int *)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) {
            col[i] = matrix[i][j];
        }
        qsort(col, m, sizeof(int), compareDesc);
        for (int i = 0; i < m; i++) {
            matrix[i][j] = col[i];
        }
        free(col);
    }
}

int main() {
    int m, n;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    sortRows(matrix, m, n);
    sortCols(matrix, m, n);

    printf("Matrix after sorting rows in ascending order and columns in descending order:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
