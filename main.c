#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning( disable : 4996 )

#include "matrix_op.h"

int main(){
    int terminate = 0;
    int op=0;
    int a[SIZE][SIZE] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int b[SIZE][SIZE] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    while(!terminate){
        
        //input
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                scanf("%d", &b[i][j]);
            }
        }


        //processing
        switch (op)
        {
        case 1://add
            {
                int **res = add((int **)a, (int **)b);
                for(int i=0;i<SIZE;i++){
                    for(int j=0;j<SIZE;j++){
                        printf("%d ", res[i][j]);
                    }
                    printf("\n");
                }
                // Free allocated memory
                for(int i=0; i<SIZE; i++) {
                    free(res[i]);
                }
                free(res);
            }
        
        case 2://sub
            {
                int **res = sub((int **)a, (int **)b);
                for(int i=0;i<SIZE;i++){
                    for(int j=0;j<SIZE;j++){
                        printf("%d ", res[i][j]);
                    }
                    printf("\n");
                }
                // Free allocated memory
                for(int i=0; i<SIZE; i++) {
                    free(res[i]);
                }
                free(res);
            }
        
        case 3://mul
            {
                int **res = mul((int **)a, (int **)b);
                for(int i=0;i<SIZE;i++){
                    for(int j=0;j<SIZE;j++){
                        printf("%d ", res[i][j]);
                    }
                    printf("\n");
                }
                // Free allocated memory
                for(int i=0; i<SIZE; i++) {
                    free(res[i]);
                }
                free(res);
            }
        default:
            printf("Ending program.\n");
            terminate = 1;
            break;
        }
    }

    return 0;
}