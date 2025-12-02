#include <stdio.h>
#include <stdlib.h>
#include "matrix_op.h"

int **add(int **a, int **b) {
    int **result = (int **)malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        result[i] = (int *)malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

int **sub(int **a, int **b) {
    int **result = (int **)malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        result[i] = (int *)malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}


int **mul(int **a, int **b) {
    int **result = (int **)malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        result[i] = (int *)malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}