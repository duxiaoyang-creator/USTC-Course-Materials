#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 256  // ASCII字符集的大小

// 哈夫曼树节点
typedef struct MinHeapNode {
    unsigned char data;   // 存储字符
    unsigned freq;        // 存储字符的频率
    struct MinHeapNode *left, *right;  // 左右子节点
} MinHeapNode;

// 最小堆结构体
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** array;
} MinHeap;

// 创建一个新的哈夫曼树节点
MinHeapNode* createNode(unsigned char data, unsigned freq) {
    MinHeapNode* newNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 创建一个最小堆
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return heap;
}

// 节点比较函数
int compare(const void* a, const void* b) {
    return ((MinHeapNode*)a)->freq - ((MinHeapNode*)b)->freq;
}

// 插入节点到最小堆
void insertMinHeap(MinHeap* heap, MinHeapNode* node) {
    heap->array[heap->size++] = node;
    qsort(heap->array, heap->size, sizeof(MinHeapNode*), compare);  // 使用快速排序来保持堆的顺序
}

// 从堆中取出最小频率节点
MinHeapNode* extractMin(MinHeap* heap) {
    return heap->array[--heap->size];
}

// 构建哈夫曼树
MinHeapNode* buildHuffmanTree(int freq[]) {
    MinHeap* heap = createMinHeap(MAX_CHAR);
    
    // 创建每个字符的节点并插入堆
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (freq[i]) {
            insertMinHeap(heap, createNode(i, freq[i]));
        }
    }

    // 构建哈夫曼树，直到堆中只有一个节点
    while (heap->size > 1) {
        MinHeapNode* left = extractMin(heap);
        MinHeapNode* right = extractMin(heap);
        
        MinHeapNode* top = createNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;
        
        insertMinHeap(heap, top);
    }

    // 返回哈夫曼树的根节点
    return extractMin(heap);
}

// 递归生成哈夫曼编码并打印
void printCodes(MinHeapNode* root, int* arr, int top, char* codebook[MAX_CHAR]) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, codebook);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, codebook);
    }
    
    // 如果是叶子节点，则记录编码
    if (!root->left && !root->right) {
        char* code = (char*)malloc(top + 1);
        for (int i = 0; i < top; ++i) {
            code[i] = arr[i] ? '1' : '0';
        }
        code[top] = '\0';
        codebook[root->data] = code;
    }
}

// 生成字符的哈夫曼编码
void generateHuffmanCodes(MinHeapNode* root, char* codebook[MAX_CHAR]) {
    int arr[MAX_CHAR], top = 0;
    printCodes(root, arr, top, codebook);
}

// 压缩文件
void compress(FILE* input, FILE* output, char* codebook[MAX_CHAR]) {
    fseek(input, 0, SEEK_SET);
    unsigned char c;
    while (fread(&c, sizeof(unsigned char), 1, input)) {
        char* code = codebook[c];
        for (int i = 0; code[i] != '\0'; ++i) {
            fputc(code[i], output);  // 将编码写入输出文件
        }
    }
}

// 解压文件
void decompress(FILE* input, FILE* output, MinHeapNode* root) {
    MinHeapNode* current = root;
    unsigned char bit;
    
    while (fread(&bit, sizeof(unsigned char), 1, input)) {
        current = (bit == '0') ? current->left : current->right;
        
        // 如果到达叶子节点，输出字符
        if (!current->left && !current->right) {
            fputc(current->data, output);
            current = root;
        }
    }
}

// 计算压缩比
double calculateCompressionRatio(FILE* input, FILE* compressed) {
    fseek(input, 0, SEEK_END);
    long original_size = ftell(input);  // 获取原始文件大小
    
    fseek(compressed, 0, SEEK_END);
    long compressed_size = ftell(compressed);  // 获取压缩后的文件大小
    
    return (double)original_size / compressed_size;
}

// 打印哈夫曼树
void printHuffmanTree(MinHeapNode* root,int level){
    if (root == NULL) {
        return;
    }
    
    printHuffmanTree(root->right, level + 1);
    
    for (int i = 0; i < level; ++i) {
        printf("   ");
    }
    printf("%c:%d\n", root->data, root->freq);
    
    printHuffmanTree(root->left, level + 1);
}

void printMenu() {
    printf("1. 压缩文件\n");
    printf("2. 解压缩\n");
    printf("3. 显示压缩比\n");
    printf("4. 退出\n");
    printf("选择执行的操作: ");
}

int main() {
    int choice;
    FILE *input, *output, *compressed, *decompressed;
    char* codebook[MAX_CHAR] = {0};
    int freq[MAX_CHAR] = {0};
    MinHeapNode* root = NULL;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar();  // 清理输入缓冲区的换行符

        switch (choice) {
            case 1: {
                // 压缩文件
                printf("请输入要压缩的文件名： ");
                char inputFile[100];
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0;  // 去除换行符

                input = fopen(inputFile, "r");
                if (!input) {
                    printf("打开文件失败\n");
                    break;
                }

                // 统计字符频率
                memset(freq, 0, sizeof(freq));
                unsigned char c;
                while (fread(&c, sizeof(unsigned char), 1, input)) {
                    freq[c]++;
                }

                // 构建哈夫曼树
                root = buildHuffmanTree(freq);

                // 生成编码
                generateHuffmanCodes(root, codebook);
				printHuffmanTree(root,1);
                // 压缩文件
                printf("请输入压缩后的文件名: ");
                char compressedFile[100];
                fgets(compressedFile, sizeof(compressedFile), stdin);
                compressedFile[strcspn(compressedFile, "\n")] = 0;

                compressed = fopen(compressedFile, "w");
                if (!compressed) {
                    printf("Error opening compressed output file!\n");
                    fclose(input);
                    break;
                }

                compress(input, compressed, codebook);
                printf("压缩成功!\n");

                fclose(input);
                fclose(compressed);
                break;
            }
            case 2: {
                // 解压文件
                printf("请输入要解压缩的文件名: ");
                char compressedFile[100];
                fgets(compressedFile, sizeof(compressedFile), stdin);
                compressedFile[strcspn(compressedFile, "\n")] = 0;

                compressed = fopen(compressedFile, "r");
                if (!compressed) {
                    printf("Error opening compressed input file!\n");
                    break;
                }

                printf("请输入解压缩后的文件名: ");
                char decompressedFile[100];
                fgets(decompressedFile, sizeof(decompressedFile), stdin);
                decompressedFile[strcspn(decompressedFile, "\n")] = 0;

                decompressed = fopen(decompressedFile, "w");
                if (!decompressed) {
                    printf("Error opening decompressed output file!\n");
                    fclose(compressed);
                    break;
                }

                decompress(compressed, decompressed, root);
                printf("解压缩成功!\n");

                fclose(compressed);
                fclose(decompressed);
                break;
            }
            case 3: {
                // 显示压缩比
                printf("输入压缩后文件名: ");
                char inputFile[100];
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0;  // 去除换行符

                input = fopen(inputFile, "r");
                if (!input) {
                    printf("Error opening input file!\n");
                    break;
                }

                printf("输入原文件名: ");
                char compressedFile[100];
                fgets(compressedFile, sizeof(compressedFile), stdin);
                compressedFile[strcspn(compressedFile, "\n")] = 0;

                compressed = fopen(compressedFile, "r");
                if (!compressed) {
                    printf("Error opening compressed file!\n");
                    fclose(input);
                    break;
                }

                // 计算压缩比
                double ratio = calculateCompressionRatio(input, compressed);
                printf("压缩比为: %.2f\n", ratio);

                fclose(input);
                fclose(compressed);
                break;
            }
            case 4:
                // 退出
                printf("退出...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
