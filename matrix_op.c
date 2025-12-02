#include <stdio.h>
#include <stdlib.h>
#include "matrix_op.h"

// 輔助函式：用於處理記憶體分配失敗並清理已分配的記憶體
static int **allocate_matrix_and_check() {
    int **result = (int **)malloc(SIZE * sizeof(int *));
    if (result == NULL) {
        // 分配失敗，返回 NULL
        return NULL;
    }
    
    for (int i = 0; i < SIZE; i++) {
        result[i] = (int *)malloc(SIZE * sizeof(int));
        if (result[i] == NULL) {
            // 單行分配失敗，清理前面已分配的指標和記憶體
            for (int k = 0; k < i; k++) {
                free(result[k]);
            }
            free(result);
            return NULL;
        }
    }
    return result;
}


int **add(int **a, int **b) {
    int **result = allocate_matrix_and_check();
    
    if (result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in add function.\n");
        return NULL; // 返回 NULL 表示操作失敗
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

int **sub(int **a, int **b) {
    int **result = allocate_matrix_and_check();
    
    if (result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in sub function.\n");
        return NULL; // 返回 NULL 表示操作失敗
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}


int **mul(int **a, int **b) {
    int **result = allocate_matrix_and_check();

    if (result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in mul function.\n");
        return NULL; // 返回 NULL 表示操作失敗
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}