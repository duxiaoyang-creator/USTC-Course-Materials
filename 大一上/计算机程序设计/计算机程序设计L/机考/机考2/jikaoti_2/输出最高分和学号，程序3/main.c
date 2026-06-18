#include  <stdio.h> 
#define    CLASS  3 
#define    STU    4 

/* 
82  75  73  69
67  88  76  89
95  90  80  90
*/

int FindMax(int *p, int m, int n, int *pRow, int *pCol);

int main(void) 
{  
    int score[CLASS][STU], i, j, maxScore, row, col; 
    printf("Please enter score:\n"); 
    for (i=0; i<CLASS; i++) 
    { 
        for (j=0; j<STU; j++) 
        {
		    scanf("%d", &score[i][j]);        // 输入学生成绩 
        } 
    } 
    // 计算最高分及其学生所在班号和学号 
    maxScore = FindMax(*score, CLASS, STU, &row, &col);  
    printf("maxScore = %d, class = %d, number = %d\n", maxScore, row+1, col+1);     
    return 0;                            
} 

// 函数功能：返回任意m 行n 列的二维数组中元素的最大值，并指出其所在的行列下标值 
int  FindMax(int *p, int m, int n, int *pRow, int *pCol)     
{ 
     int  i, j, maxScore; 
     maxScore = p[0];    // 置初值，假设第一个元素值最大 
     *pRow = 0;          // 整型指针变量pRow 指向数组元素最大值所在的行 
     *pCol = 0;          // 整型指针变量pCol，指向数组元素最大值所在的列 
     for (i=0; i<m; i++) 
     { 
        for (j=0; j<n; j++) 
        { 
            if (p[i*n+j] > maxScore)    
            { 
                maxScore = p[i*n+j];           // 记录当前最大值 
                *pRow = i;                     // 记录行下标 
                *pCol = j;                     // 记录列下标 
            }                                   
        }                                       
    }                                               
    return maxScore;                           // 返回最大值 
} 

