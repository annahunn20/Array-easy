#include <stdio.h>

void modifyMatrix(int mat[4][4], int row, int col) {
    int rowFlag[row], colFlag[col];
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (mat[i][j] == 0)
                rowFlag[i] = colFlag[j] = 1;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (rowFlag[i] || colFlag[j])
                mat[i][j] = 0;
}
