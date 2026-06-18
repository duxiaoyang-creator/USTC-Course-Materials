#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int ElemType;

typedef struct {
    ElemType *r;
    int len;
} SqTable;

// 初始化列表
void InitList(SqTable *L, int len) {
    L->r = (ElemType*)malloc((len+1) * sizeof(ElemType));
    L->len = len;
}

// 复制列表
void CopyList(SqTable L, SqTable *newL) {
    newL->r = (ElemType*)malloc((L.len+1) * sizeof(ElemType));
    newL->len = L.len;
    memcpy(newL->r, L.r, (L.len+1) * sizeof(ElemType));
}

// 生成随机整数
int randb(int bound) {
    return rand() % (bound + 1);
}

// 随机打乱数组
void RandomShuffleList(SqTable L) {
    ElemType* array = L.r + 1;
    int n = L.len;
    for (int i = n - 1; i > 0; --i) {
        int j = randb(i);
        ElemType tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

// 交换两个元素
void Swap(ElemType *a, ElemType *b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

// 冒泡排序
void BubbleSort(SqTable L) {
    for (int i = 1; i < L.len; ++i) {
        for (int j = L.len; j > i; --j) {
            if (L.r[j] < L.r[j - 1]) {
                Swap(&L.r[j], &L.r[j - 1]);
            }
        }
    }
}

// 快速排序
void QuickSortRec(SqTable L, int low, int high) {
    if (low < high) {
        int pivot = L.r[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && L.r[j] >= pivot) --j;
            if (i < j) L.r[i++] = L.r[j];
            while (i < j && L.r[i] <= pivot) ++i;
            if (i < j) L.r[j--] = L.r[i];
        }
        L.r[i] = pivot;
        QuickSortRec(L, low, i - 1);
        QuickSortRec(L, i + 1, high);
    }
}

void QuickSort(SqTable L) {
    QuickSortRec(L, 1, L.len);
}

// 合并两个子数组
void Merge(SqTable L, int low, int mid, int high) {
    ElemType* temp = (ElemType*)malloc((high - low + 1) * sizeof(ElemType));
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (L.r[i] <= L.r[j]) temp[k++] = L.r[i++];
        else temp[k++] = L.r[j++];
    }
    while (i <= mid) temp[k++] = L.r[i++];
    while (j <= high) temp[k++] = L.r[j++];
    for (i = low, k = 0; i <= high; ++i, ++k) L.r[i] = temp[k];
    free(temp);
}

// 归并排序
void MergeSortRec(SqTable L, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSortRec(L, low, mid);
        MergeSortRec(L, mid + 1, high);
        Merge(L, low, mid, high);
    }
}

void MergeSort(SqTable L) {
    MergeSortRec(L, 1, L.len);
}

// 插入排序
void InsertionSort(SqTable L) {
    for (int i = 2; i <= L.len; ++i) {
        ElemType key = L.r[i];
        int j = i - 1;
        while (j >= 1 && L.r[j] > key) {
            L.r[j + 1] = L.r[j];
            --j;
        }
        L.r[j + 1] = key;
    }
}

// 选择排序
void SelectionSort(SqTable L) {
    for (int i = 1; i < L.len; ++i) {
        int minIndex = i;
        for (int j = i + 1; j <= L.len; ++j) {
            if (L.r[j] < L.r[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Swap(&L.r[i], &L.r[minIndex]);
        }
    }
}

// 打印菜单
void PrintMenu() {
    printf("请选择排序算法:\n");
    printf("1. 冒泡排序\n");
    printf("2. 快速排序\n");
    printf("3. 归并排序\n");
    printf("4. 插入排序\n");
    printf("5. 选择排序\n");
    printf("6. 退出\n");
    printf("请输入数字（1-6）: ");
}

int main() {
    srand(time(NULL));

    int N = 100000;
    SqTable L;
    InitList(&L, N);

    for (int i = 1; i <= N; ++i) {
        L.r[i] = i;
    }

    int choice;
    do {
        // 打乱列表
        RandomShuffleList(L);

        // 提示用户选择排序算法
        PrintMenu();
        scanf("%d", &choice);

        clock_t begin, end;
        SqTable L1;
        CopyList(L, &L1);

        switch (choice) {
            case 1:
                begin = clock();
                BubbleSort(L1);
                end = clock();
                printf("冒泡排序运行时间: %f 秒\n", (float)(end - begin) / CLOCKS_PER_SEC);
                break;
            case 2:
                begin = clock();
                QuickSort(L1);
                end = clock();
                printf("快速排序运行时间: %f 秒\n", (float)(end - begin) / CLOCKS_PER_SEC);
                break;
            case 3:
                begin = clock();
                MergeSort(L1);
                end = clock();
                printf("归并排序运行时间: %f 秒\n", (float)(end - begin) / CLOCKS_PER_SEC);
                break;
            case 4:
                begin = clock();
                InsertionSort(L1);
                end = clock();
                printf("插入排序运行时间: %f 秒\n", (float)(end - begin) / CLOCKS_PER_SEC);
                break;
            case 5:
                begin = clock();
                SelectionSort(L1);
                end = clock();
                printf("选择排序运行时间: %f 秒\n", (float)(end - begin) / CLOCKS_PER_SEC);
                break;
            case 6:
                printf("退出程序.\n");
                break;
            default:
                printf("无效的选择!\n");
                break;
        }
    } while (choice != 6); // 当选择不是6时，继续循环操作

    // 释放内存
    free(L.r);
    return 0;
}
