#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning( disable : 4996 )

#include "matrix_op.h"

int main(){
    int i;
    int j;
    int terminate = 0;
    int op = 0; // 需要一個地方接收 op 的輸入，否則 op 永遠為 0，只會執行 default

    // 動態分配 a 和 b 矩陣的記憶體 (一次性分配，因為它們在 while 迴圈外)
    // 這裡我們假設 op 的輸入會在 main 迴圈中提供，以便測試 add/sub/mul
    int **a_ptr = (int **)malloc(SIZE * sizeof(int *));
    int **b_ptr = (int **)malloc(SIZE * sizeof(int *));

    if (a_ptr == NULL || b_ptr == NULL) {
        printf("Memory allocation failed for a_ptr or b_ptr.\n");
        return 1;
    }

    for (i = 0; i < SIZE; i++) {
        a_ptr[i] = (int *)malloc(SIZE * sizeof(int));
        b_ptr[i] = (int *)malloc(SIZE * sizeof(int));
        if (a_ptr[i] == NULL || b_ptr[i] == NULL) {
            printf("Memory allocation failed for matrix row.\n");
            // 清理已分配的記憶體
            for (int k = 0; k < i; k++) {
                free(a_ptr[k]);
                free(b_ptr[k]);
            }
            free(a_ptr);
            free(b_ptr);
            return 1;
        }
    }


    printf("Enter operation (1: Add, 2: Sub, 3: Mul, Other: End):\n");
    scanf("%d", &op); // 新增 op 輸入

    while(!terminate){
        printf("--- Entering Loop ---\n");
        
        // input
        printf("Enter matrix A (%dx%d):\n", SIZE, SIZE);
        for(i=0;i<SIZE;i++){
            for(j=0;j<SIZE;j++){
                if(scanf("%d", &a_ptr[i][j]) != 1) { terminate = 1; break; } // 檢查輸入
            }
            if(terminate) break;
        }
        
        printf("Enter matrix B (%dx%d):\n", SIZE, SIZE);
        for(i=0;i<SIZE;i++){
            for(j=0;j<SIZE;j++){
                if(scanf("%d", &b_ptr[i][j]) != 1) { terminate = 1; break; } // 檢查輸入
            }
            if(terminate) break;
        }
        
        if(terminate) break; // 如果輸入失敗則退出迴圈

        // processing
        switch (op)
        {
        case 1://add
            {
                printf("Result of A + B:\n");
                // 傳遞動態分配的指標
                int **res = add(a_ptr, b_ptr);
                
                for(i=0;i<SIZE;i++){
                    for(j=0;j<SIZE;j++){
                        printf("%d ", res[i][j]);
                    }
                    printf("\n");
                }
                // Free allocated memory for result matrix
                for(i=0; i<SIZE; i++) {
                    free(res[i]);
                }
                free(res);
            }
            break; // **重要：記得加上 break**

        case 2://sub
            {
                printf("Result of A - B:\n");
                // 傳遞動態分配的指標
                int **res = sub(a_ptr, b_ptr);
                
                for(i=0;i<SIZE;i++){
                    for(j=0;j<SIZE;j++){
                        printf("%d ", res[i][j]);
                    }
                    printf("\n");
                }
                // Free allocated memory for result matrix
                for(i=0; i<SIZE; i++) {
                    free(res[i]);
                }
                free(res);
            }
            break; // **重要：記得加上 break**
        
        case 3://mul
            {
                printf("Result of A * B:\n");
                // 傳遞動態分配的指標
                int **res = mul(a_ptr, b_ptr);
                
                for(i=0;i<SIZE;i++){
                    for(j=0;j<SIZE;j++){
                        printf("%d ", res[i][j]);
                    }
                    printf("\n");
                }
                // Free allocated memory for result matrix
                for(i=0; i<SIZE; i++) {
                    free(res[i]);
                }
                free(res);
            }
            break; // **重要：記得加上 break**
        
        default:
            printf("Ending program.\n");
            terminate = 1;
            break;
        }

        if (!terminate) {
            printf("\nEnter next operation (1: Add, 2: Sub, 3: Mul, Other: End):\n");
            if(scanf("%d", &op) != 1) {
                terminate = 1; // 如果無法讀取操作，則結束
            }
        }
    }

    // 程式結束前，釋放 a_ptr 和 b_ptr 的記憶體
    for (i = 0; i < SIZE; i++) {
        free(a_ptr[i]);
        free(b_ptr[i]);
    }
    free(a_ptr);
    free(b_ptr);

    return 0;
}