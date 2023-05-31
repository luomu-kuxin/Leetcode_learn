// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，
// 且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);   
    
    int **matrix = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        matrix[i] =  (int*)malloc(sizeof(int) * n);

        (*returnColumnSizes)[i] = n; // 一定要加括号，’[]’的优先级比’*‘高 ，不要问我怎么知道的
    }
    
    //起始位置
    int sx = 0, sy = 0;// matrix[sy][sx]
    //循环数
    int num = 1; // 初始值
    int loop = n / 2; // 取整会舍弃掉小数部分，1.5 -> 1；n = 5 -> loop = 2
    int offset = 1; // 每行每列要少加的数，第一次循环每次为 n -1 ; 第二次为 n - 2;
    while(loop){
        int j = sx;
        int i = sy;
        for(j = sx; j < n - offset + sx; j++){
            matrix[i][j] = num;
            num++;
        }
        printf("第 %d 行完成\n",i);
        for(i = sy; i < n - offset + sy; i++){
            matrix[i][j] = num;
            num++;
        }
        printf("第 %d 列完成\n",j);
        for(; j >  sx ; j--){
            matrix[i][j] = num;
            num++;
        }
        printf("第 %d 行完成\n",i);
        for(; i >  sy ; i--){
            matrix[i][j] = num;
            num++;
        }
        printf("第 %d 列完成\n",j);
        sy++;
        sx++;
        offset += 2;
        loop--;
    }
    //判断是否为奇数，是的话则给最中间赋值n^2
    if(n % 2){
        int mid = n / 2; // 中间数，n为奇数时，中间单独填，n = 3, [1][1] = 9;
        matrix[mid][mid] = num; 
    }

    return matrix;

}

void printmatrix(int matrixsize, int *ColumenSize,int (*matrix)[matrixsize]){

    for(int i = 0; i < matrixsize; i++){
        for(int j = 0; j < ColumenSize[j]; j++){
            printf("%d  ",matrix[i][j]);
        }
        printf("\n");
    }
}
void printmatrix1(int matrixsize, int *ColumenSize,int **matrix){

    for(int i = 0; i < matrixsize; i++){
        for(int j = 0; j < ColumenSize[j]; j++){
            printf("%d  ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main(void){

    // int matrixsize = 4;
    // int ColumnSizes[4] = {4,4,4,4};
    // int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // printmatrix(matrixsize,ColumnSizes,matrix);
    int size;
    int *columeSize; 
    int** matrix = generateMatrix(5,&size,&columeSize);
    printmatrix1(size,columeSize,matrix);
    return 0;
}
