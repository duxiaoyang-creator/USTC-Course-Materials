#include  <stdio.h> 
#include  <stdlib.h> 

/* 
82  75  73  69
67  88  76  89
95  90  80  90
*/

int FindMax(int *p, int m, int n, int *pRow, int *pCol);    

int main(void) 
{  
    int  *pScore, i, j, m, n, maxScore, row, col; 
    printf("Please enter array size m,n:"); 
    scanf("%d%d", &m, &n);                        // 输入班级数m 和学生数n 
    pScore = (int *) calloc(m*n, sizeof (int));   // 申请内存 
    if (pScore == NULL)  
    { 
        printf("No enough memory!\n"); 
        exit(0);  
    } 
    printf("Please enter the score:\n"); 
    for (i=0; i<m; i++) 
    { 
        for (j=0; j<n; j++) 
        { 
            scanf("%d", &pScore [i*n+j]);          // 输入学生成绩 
        } 
    } 
    maxScore = FindMax(pScore, 3, 4, &row, &col);  // 调用函数FindMax     
    // 输出最高分max 及其所在的班级和学号                             
    printf("maxScore = %d, class = %d, number = %d\n", maxScore, row+1, col+1);   
    free(pScore);                             // 释放向系统申请的存储空间  
    return 0; 
} 

// 函数功能：返回任意m 行n 列的二维数组中元素的最大值，并指出其所在行列下标值 
int  FindMax(int *p, int m, int n, int *pRow, int *pCol)     
{ 
    int  i, j, max; 
    max = p[0];          // 置初值，假设第一个元素值最大 
    *pRow = 0;           // 整型指针变量pRow 指向数组元素最大值所在的行 
    *pCol = 0;           // 整型指针变量pCol 指向数组元素最大值所在的列 
    for (i=0; i<m; i++) 
    { 
        for (j=0; j<n; j++) 
        { 
            if (p[i*n+j] > max)         
            { 
                max = p[i*n+j];                // 记录当前最大值 
                *pRow = i;                     // 记录行下标 
                *pCol = j;                     // 记录列下标 
            }                             
        }                                   
    }                                           
    return max;                                // 返回最大值 
}

