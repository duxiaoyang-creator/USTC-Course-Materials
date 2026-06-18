#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef int ElemType;  // 数组元素类型可以根据需要调整

// 顺序表结构
typedef struct {
    ElemType *r;
    int len;
} SqTable;

// 初始化顺序表
void InitList(SqTable &L, int size) {
    L.r = (ElemType *)malloc((size + 1) * sizeof(ElemType));  // 索引从1开始
    L.len = size;
}

// 复制顺序表
void CopyList(SqTable &L, SqTable &L_copy) {
    InitList(L_copy, L.len);
    for (int i = 1; i <= L.len; i++) {
        L_copy.r[i] = L.r[i];
    }
}

// 随机打乱顺序表
void RandomShuffleList(SqTable &L) {
    srand(time(NULL));
    for (int i = 1; i <= L.len; i++) {
        int j = rand() % L.len + 1;
        ElemType temp = L.r[i];
        L.r[i] = L.r[j];
        L.r[j] = temp;
    }
}

// 打印顺序表
void PrintList(SqTable &L) {
    for (int i = 1; i <= L.len; i++) {
        printf("%d ", L.r[i]);
    }
    printf("\n");
}

// 快速排序
void QuickSort(SqTable &L, int low, int high) {
    if (low < high) {
        int pivot = L.r[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && L.r[j] >= pivot) j--;
            if (i < j) L.r[i++] = L.r[j];
            while (i < j && L.r[i] <= pivot) i++;
            if (i < j) L.r[j--] = L.r[i];
        }
        L.r[i] = pivot;
        QuickSort(L, low, i - 1);
        QuickSort(L, i + 1, high);
    }
}

// 堆排序
void Heapify(SqTable &L, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && L.r[left] > L.r[largest]) largest = left;
    if (right < n && L.r[right] > L.r[largest]) largest = right;
    
    if (largest != i) {
        ElemType temp = L.r[i];
        L.r[i] = L.r[largest];
        L.r[largest] = temp;
        Heapify(L, n, largest);
    }
}

void HeapSort(SqTable &L) {
    int n = L.len;
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(L, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        ElemType temp = L.r[0];
        L.r[0] = L.r[i];
        L.r[i] = temp;
        Heapify(L, i, 0);
    }
}

// 归并排序
void Merge(SqTable &L, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    ElemType *L1 = (ElemType*)malloc((n1 + 1) * sizeof(ElemType));
    ElemType *L2 = (ElemType*)malloc((n2 + 1) * sizeof(ElemType));

    for (int i = 0; i < n1; i++) L1[i] = L.r[left + i];
    for (int i = 0; i < n2; i++) L2[i] = L.r[mid + 1 + i];
    L1[n1] = L2[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (L1[i] <= L2[j]) {
            L.r[k] = L1[i++];
        } else {
            L.r[k] = L2[j++];
        }
    }
    free(L1);
    free(L2);
}

void MergeSort(SqTable &L, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(L, left, mid);
        MergeSort(L, mid + 1, right);
        Merge(L, left, mid, right);
    }
}

// 冒泡排序
void BubbleSort(SqTable &L) {
    int n = L.len;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (L.r[j] > L.r[j + 1]) {
                ElemType temp = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = temp;
            }
        }
    }
}

// 选择排序
void SelectionSort(SqTable &L) {
    int n = L.len;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (L.r[j] < L.r[minIndex]) {
                minIndex = j;
            }
        }
        ElemType temp = L.r[i];
        L.r[i] = L.r[minIndex];
        L.r[minIndex] = temp;
    }
}

// 测量排序时间
void MeasureSortTime(SqTable &L, void (*sortFunc)(SqTable&)) {
    clock_t begin, end;
    begin = clock();
    sortFunc(L);
    end = clock();
    printf("排序时间: %g 秒\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

// 包装函数：快速排序（包装成适合 MeasureSortTime 的格式）
void QuickSortWrapper(SqTable &L) {
    QuickSort(L, 1, L.len);  // 调用实际的快速排序，范围从 1 到 len
}

// 包装函数：归并排序（包装成适合 MeasureSortTime 的格式）
void MergeSortWrapper(SqTable &L) {
    MergeSort(L, 1, L.len);  // 调用实际的归并排序，范围从 1 到 len
}

// 包装函数：堆排序（包装成适合 MeasureSortTime 的格式）
void HeapSortWrapper(SqTable &L) {
    HeapSort(L);  // 堆排序没有额外的参数
}

// 包装函数：选择排序（包装成适合 MeasureSortTime 的格式）
void SelectionSortWrapper(SqTable &L) {
    SelectionSort(L);  // 选择排序没有额外的参数
}

// 包装函数：冒泡排序（包装成适合 MeasureSortTime 的格式）
void BubbleSortWrapper(SqTable &L) {
    BubbleSort(L);  // 冒泡排序没有额外的参数
}

// 主函数
int main() {
    int N;
    printf("请输入元素个数: ");
    scanf("%d", &N);

    SqTable L;
    InitList(L, N);

    for (int i = 1; i <= N; i++) {
        L.r[i] = i;
    }

    RandomShuffleList(L);

    int choice;
    while (1) {
        printf("\n排序算法菜单:\n");
        printf("1. 冒泡排序\n");
        printf("2. 快速排序\n");
        printf("3. 堆排序\n");
        printf("4. 归并排序\n");
        printf("5. 选择排序\n");
        printf("6. 退出\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        SqTable L_copy;
        CopyList(L, L_copy);

        switch (choice) {
            case 1:
                MeasureSortTime(L_copy, BubbleSortWrapper);
                break;
            case 2:
                MeasureSortTime(L_copy, QuickSortWrapper);
                break;
  			case 3:
                MeasureSortTime(L_copy, HeapSortWrapper);
                break;
            case 4:
                MeasureSortTime(L_copy, MergeSortWrapper);
                break;
            case 5:
                MeasureSortTime(L_copy, SelectionSortWrapper);
                break;
            case 6:
                printf("退出程序。\n");
                free(L.r);  // 释放分配的内存
                return 0;
            default:
                printf("无效的选择，请重新输入。\n");
        }
    }
}
