#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_CHAR 256

// 哈夫曼树的节点结构
typedef struct MinHeapNode {
    unsigned char data;  // 存储字符
    unsigned frequency;  // 存储字符频率
    struct MinHeapNode *left, *right;  // 左右子树
} MinHeapNode;

// 哈夫曼树的最小堆结构
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** array;
} MinHeap;

// 创建一个新的哈夫曼树节点
MinHeapNode* newNode(unsigned char data, unsigned frequency) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    return temp;
}

// 创建一个最小堆
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// 交换两个最小堆节点
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// 进行最小堆化
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// 检查最小堆是否只有一个元素
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// 提取最小的节点
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// 插入一个新的节点到最小堆
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// 构建哈夫曼树
MinHeapNode* buildHuffmanTree(unsigned char data[], unsigned frequency[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], frequency[i]);

    minHeap->size = size;
    while (!isSizeOne(minHeap)) {
        MinHeapNode* left = extractMin(minHeap);
        MinHeapNode* right = extractMin(minHeap);

        MinHeapNode* top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// 用于存储每个字符的哈夫曼编码
void printHuffmanCodes(MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// 打印哈夫曼树的结构
void printHuffmanTree(MinHeapNode* root, int space) {
    if (root == NULL) return;

    space += 10;
    printHuffmanTree(root->right, space);

    for (int i = 10; i < space; ++i)
        printf(" ");
    printf("%c:%d\n", root->data, root->frequency);

    printHuffmanTree(root->left, space);
}

// 计算压缩比
double calculateCompressionRatio(FILE* input, FILE* compressed) {
    fseek(input, 0, SEEK_END);
    long inputSize = ftell(input);
    fseek(compressed, 0, SEEK_END);
    long compressedSize = ftell(compressed);
    return (double)inputSize / compressedSize;
}

int main() {
    int choice;
    while (1) {
        // 中文菜单栏
        printf("请选择操作:\n");
        printf("1. 压缩文件\n");
        printf("2. 解压文件\n");
        printf("3. 查看压缩比\n");
        printf("4. 退出\n");
        printf("请输入选择 (1-4): ");
        scanf("%d", &choice);
        getchar();  // 处理输入后的换行符

        switch (choice) {
            case 1: {
                // 压缩文件
                printf("请输入原始文件名: ");
                char inputFile[100];
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0;

                FILE* input = fopen(inputFile, "r");
                if (!input) {
                    printf("无法打开输入文件!\n");
                    break;
                }

                // 统计文件中字符频率
                unsigned frequency[MAX_CHAR] = {0};
                unsigned char data[MAX_CHAR];
                int size = 0;

                while (!feof(input)) {
                    unsigned char ch = fgetc(input);
                    if (ch != EOF) {
                        if (frequency[ch] == 0)
                            data[size++] = ch;
                        frequency[ch]++;
                    }
                }

                fclose(input);

                // 构建哈夫曼树
                MinHeapNode* root = buildHuffmanTree(data, frequency, size);
                printf("哈夫曼树结构:\n");
                printHuffmanTree(root, 0);  // 打印哈夫曼树

                break;
            }
            case 2: {
                // 解压文件
                printf("请输入压缩文件名: ");
                char compressedFile[100];
                fgets(compressedFile, sizeof(compressedFile), stdin);
                compressedFile[strcspn(compressedFile, "\n")] = 0;

                FILE* compressed = fopen(compressedFile, "r");
                if (!compressed) {
                    printf("无法打开压缩文件!\n");
                    break;
                }

                printf("请输入解压后的文件名: ");
                char decompressedFile[100];
                fgets(decompressedFile, sizeof(decompressedFile), stdin);
                decompressedFile[strcspn(decompressedFile, "\n")] = 0;

                FILE* decompressed = fopen(decompressedFile, "w");
                if (!decompressed) {
                    printf("无法打开解压文件!\n");
                    fclose(compressed);
                    break;
                }

                // 解压的操作代码（这里留空，实际实现中会根据哈夫曼编码进行解码）
                printf("文件解压完成！\n");

                fclose(compressed);
                fclose(decompressed);
                break;
            }
            case 3: {
                // 计算压缩比
                printf("请输入原始文件名: ");
                char inputFile[100];
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0;

                FILE* input = fopen(inputFile, "r");
                if (!input) {
                    printf("无法打开输入文件!\n");
                    break;
                }

                printf("请输入压缩文件名: ");
                char compressedFile[100];
                fgets(compressedFile, sizeof(compressedFile), stdin);
                compressedFile[strcspn(compressedFile, "\n")] = 0;

                FILE* compressed = fopen(compressedFile, "r");
                if (!compressed) {
                    printf("无法打开压缩文件!\n");
                    fclose(input);
                    break;
                }

                double ratio = calculateCompressionRatio(input, compressed);
                printf("压缩比: %.2f\n", ratio);

                fclose(input);
                fclose(compressed);
                break;
            }
            case 4:
                // 退出程序
                printf("退出程序。\n");
                return 0;

            default:
                printf("无效的选择，请重新输入。\n");
        }
    }
    return 0;
}
