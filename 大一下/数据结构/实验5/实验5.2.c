#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 排序算法的选择
typedef int ElemType;

typedef struct {
    ElemType *r;
    int len;
} SqTable;

// 函数声明
void InitList(SqTable *L, int len);
void RandomShuffleList(SqTable L);
void PrintList(SqTable L);
void BubbleSort(SqTable *L);
void QuickSort(SqTable *L);
void MergeSort(SqTable *L);
void HeapSort(SqTable *L);
void InsertSort(SqTable *L);
void Swap(ElemType *a, ElemType *b);
void Merge(ElemType *arr, int left, int mid, int right);
void QuickSortRec(ElemType *arr, int low, int high);
int Partition(ElemType *arr, int low, int high);
void Heapify(ElemType *arr, int n, int i);
void BuildHeap(ElemType *arr, int n);
int randb(int bound);

// 初始化顺序表
void InitList(SqTable *L, int len) {
    L->r = (ElemType*)malloc((len + 1) * sizeof(ElemType));  // 0号单元不用
    L->len = len;
}

// 生成一个随机整数
int randb(int bound) {
    return rand() % (bound + 1);
}

// 随机打乱顺序表
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

// 打印顺序表
void PrintList(SqTable L) {
    for (int i = 1; i <= L.len; i++) {
        printf("%d ", L.r[i]);
    }
    printf("\n");
}

// 冒泡排序
void BubbleSort(SqTable *L) {
    for (int i = 1; i < L->len; i++) {
        for (int j = 1; j < L->len - i + 1; j++) {
            if (L->r[j] > L->r[j + 1]) {
                Swap(&L->r[j], &L->r[j + 1]);
            }
        }
    }
}

// 快速排序
void QuickSort(SqTable *L) {
    QuickSortRec(L->r, 1, L->len);
}

void QuickSortRec(ElemType *arr, int low, int high) {
    if (low < high) {
        int pivotIndex = Partition(arr, low, high);
        QuickSortRec(arr, low, pivotIndex - 1);
        QuickSortRec(arr, pivotIndex + 1, high);
    }
}

int Partition(ElemType *arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        if (i < j) arr[i++] = arr[j];
        while (i < j && arr[i] <= pivot) i++;
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;
    return i;
}

// 归并排序
void MergeSort(SqTable *L) {
    MergeSortRec(L->r, 1, L->len);
}

void MergeSortRec(ElemType *arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSortRec(arr, left, mid);
        MergeSortRec(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void Merge(ElemType *arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    ElemType *temp = (ElemType *)malloc((right - left + 1) * sizeof(ElemType));
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
    free(temp);
}

// 堆排序
void HeapSort(SqTable *L) {
    BuildHeap(L->r, L->len);
    for (int i = L->len; i > 1; i--) {
        Swap(&L->r[1], &L->r[i]);
        Heapify(L->r, i - 1, 1);
    }
}

void BuildHeap(ElemType *arr, int n) {
    for (int i = n / 2; i >= 1; i--) {
        Heapify(arr, n, i);
    }
}

void Heapify(ElemType *arr, int n, int i) {
    int largest = i;
    int left = 2 * i, right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) largest = left;
    if (right <= n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        Swap(&arr[i], &arr[largest]);
        Heapify(arr, n, largest);
    }
}

// 插入排序
void InsertSort(SqTable *L) {
    for (int i = 2; i <= L->len; i++) {
        ElemType temp = L->r[i];
        int j = i - 1;
        while (j >= 1 && L->r[j] > temp) {
            L->r[j + 1] = L->r[j];
            j--;
        }
        L->r[j + 1] = temp;
    }
}

void Swap(ElemType *a, ElemType *b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

void RunSortAndMeasureTime(void (*sortFunc)(SqTable*), SqTable L, const char *sortName) {
    clock_t begin, end;
    double totalTime = 0;
    int numRuns = 5;  // 重复执行次数

    for (int i = 0; i < numRuns; i++) {
        SqTable L1;
        InitList(&L1, L.len);
        memcpy(L1.r, L.r, (L.len + 1) * sizeof(ElemType));

        begin = clock();
        sortFunc(&L1);
        end = clock();

        totalTime += (double)(end - begin) / CLOCKS_PER_SEC;
    }

    printf("%s 平均排序时间: %.6lf 秒\n", sortName, totalTime / numRuns);
}

int main() {
    int N_values[] = {10000, 100000, 1000000};
    int numN = sizeof(N_values) / sizeof(N_values[0]);
    SqTable L;

    for (int i = 0; i < numN; i++) {
        int N = N_values[i];
        printf("\n--- 测试数组大小 N = %d ---\n", N);
        InitList(&L, N);
        for (int j = 1; j <= N; j++) {
            L.r[j] = j;
        }
        RandomShuffleList(L);  // 每次都随机打乱数组

        // 测试各个排序算法
        RunSortAndMeasureTime(BubbleSort, L, "冒泡排序");
        RunSortAndMeasureTime(QuickSort, L, "快速排序");
        RunSortAndMeasureTime(MergeSort, L, "归并排序");
        RunSortAndMeasureTime(HeapSort, L, "堆排序");
        RunSortAndMeasureTime(InsertSort, L, "插入排序");
    }

    return 0;
}
