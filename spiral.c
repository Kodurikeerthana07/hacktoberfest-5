#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;
    int total = matrixSize * matrixColSize[0];
    int* result = (int*)malloc(sizeof(int) * total);
    int idx = 0;

    while (top <= bottom && left <= right) {
        // Traverse from left → right
        for (int j = left; j <= right; j++)
            result[idx++] = matrix[top][j];
        top++;

        // Traverse from top → bottom
        for (int i = top; i <= bottom; i++)
            result[idx++] = matrix[i][right];
        right--;

        // Traverse from right → left
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result[idx++] = matrix[bottom][j];
            bottom--;
        }

        // Traverse from bottom → top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[idx++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = idx;
    return result;
}
