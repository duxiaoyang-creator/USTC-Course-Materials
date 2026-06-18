#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LEN 256

// 哈夫曼树节点结构
typedef struct HuffmanNode {
    unsigned char character;   // 字符
    unsigned int frequency;     // 字符出现的频率
    struct HuffmanNode *left, *right; // 左右子节点
} HuffmanNode;

// 哈夫曼编码结构
typedef struct {
    char code[MAX_CODE_LEN];
    int length;
} HuffmanCode;

// 优先队列节点
typedef struct PriorityQueueNode {
    HuffmanNode *node;
    struct PriorityQueueNode *next;
} PriorityQueueNode;

// 优先队列
typedef struct {
    PriorityQueueNode *head;
} PriorityQueue;

// 创建优先队列
PriorityQueue* createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

// 向优先队列插入节点
void enqueue(PriorityQueue *pq, HuffmanNode *node) {
    PriorityQueueNode *newNode = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if (!pq->head || pq->head->node->frequency > node->frequency) {
        newNode->next = pq->head;
        pq->head = newNode;
        return;
    }

    PriorityQueueNode *temp = pq->head;
    while (temp->next && temp->next->node->frequency <= node->frequency) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// 从优先队列中取出最小的节点
HuffmanNode* dequeue(PriorityQueue *pq) {
    if (!pq->head) return NULL;
    PriorityQueueNode *temp = pq->head;
    HuffmanNode *node = temp->node;
    pq->head = pq->head->next;
    free(temp);
    return node;
}

// 构建Huffman树
HuffmanNode* buildHuffmanTree(unsigned int *frequency) {
    PriorityQueue *pq = createPriorityQueue();

    // 将所有非零频率的字符加入队列
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (frequency[i] > 0) {
            HuffmanNode *node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
            node->character = (unsigned char)i;
            node->frequency = frequency[i];
            node->left = node->right = NULL;
            enqueue(pq, node);
        }
    }

    // 合并最小的两个节点，直到队列中只剩下一个节点
    while (pq->head && pq->head->next) {
        HuffmanNode *left = dequeue(pq);
        HuffmanNode *right = dequeue(pq);

        HuffmanNode *parent = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        parent->character = '\0'; // 内部节点没有字符
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;
        enqueue(pq, parent);
    }

    // 返回根节点
    HuffmanNode *root = dequeue(pq);
    free(pq);
    return root;
}

// 递归生成Huffman编码
void generateHuffmanCodes(HuffmanNode *root, HuffmanCode *codes, char *codeBuffer, int depth) {
    if (!root) return;

    if (root->left == NULL && root->right == NULL) {
        codes[root->character].length = depth;
        strcpy(codes[root->character].code, codeBuffer);
    } else {
        codeBuffer[depth] = '0';
        generateHuffmanCodes(root->left, codes, codeBuffer, depth + 1);
        codeBuffer[depth] = '1';
        generateHuffmanCodes(root->right, codes, codeBuffer, depth + 1);
    }
}

// 打印Huffman树
void printHuffmanTree(HuffmanNode *root, int level) {
    if (!root) return;

    if (root->left == NULL && root->right == NULL) {
        printf("%*s%c: %d\n", level * 2, "", root->character, root->frequency);
    } else {
        printHuffmanTree(root->left, level + 1);
        printHuffmanTree(root->right, level + 1);
    }
}

// 对文件进行编码
void encodeFile(const char *inputFile, const char *outputFile, HuffmanCode *codes) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");

    if (!inFile || !outFile) {
        perror("无法打开文件");
        return;
    }

    unsigned char ch;
    unsigned int bitBuffer = 0;
    int bitCount = 0;

    while (fread(&ch, 1, 1, inFile)) {
        char *code = codes[ch].code;
        int codeLength = codes[ch].length;

        for (int i = 0; i < codeLength; i++) {
            bitBuffer <<= 1;
            if (code[i] == '1') bitBuffer |= 1;
            bitCount++;

            if (bitCount == 8) {
                fwrite(&bitBuffer, 1, 1, outFile);
                bitBuffer = 0;
                bitCount = 0;
            }
        }
    }

    if (bitCount > 0) {
        bitBuffer <<= (8 - bitCount);
        fwrite(&bitBuffer, 1, 1, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

// 对文件进行解码
void decodeFile(const char *inputFile, const char *outputFile, HuffmanNode *root) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");

    if (!inFile || !outFile) {
        perror("无法打开文件");
        return;
    }

    unsigned char ch;
    HuffmanNode *currentNode = root;

    while (fread(&ch, 1, 1, inFile)) {
        for (int i = 7; i >= 0; i--) {
            if (ch & (1 << i)) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }

            if (!currentNode->left && !currentNode->right) {
                fwrite(&currentNode->character, 1, 1, outFile);
                currentNode = root;
            }
        }
    }

    fclose(inFile);
    fclose(outFile);
}

// 计算压缩比
void calculateCompressionRatio(const char *originalFile, const char *encodedFile) {
    FILE *origFile = fopen(originalFile, "rb");
    FILE *encodedFilePtr = fopen(encodedFile, "rb");

    if (!origFile || !encodedFilePtr) {
        perror("无法打开文件");
        return;
    }

    fseek(origFile, 0, SEEK_END);
    long originalSize = ftell(origFile);
    fseek(encodedFilePtr, 0, SEEK_END);
    long encodedSize = ftell(encodedFilePtr);

    printf("原文件大小: %ld 字节\n", originalSize);
    printf("压缩后文件大小: %ld 字节\n", encodedSize);
    printf("压缩比: %.2f\n", (double)originalSize / encodedSize);
}

int main() {
    int choice;
    char inputFile[100], outputFile[100];
    unsigned int frequency[MAX_TREE_NODES] = {0};
    HuffmanCode codes[MAX_TREE_NODES];
    HuffmanNode *root;

    while (1) {
        printf("\n请选择操作:\n");
        printf("1. 压缩文件\n");
        printf("2. 解压文件\n");
        printf("3. 退出\n");
        printf("请输入选项: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("请输入输入文件名: ");
            scanf("%s", inputFile);
            printf("请输入输出文件名: ");
            scanf("%s", outputFile);

            // 统计字符频率
            FILE *file = fopen(inputFile, "rb");
            unsigned char ch;
            while (fread(&ch, 1, 1, file)) {
                frequency[ch]++;
            }
            fclose(file);

            // 构建Huffman树
            root = buildHuffmanTree(frequency);

            // 生成Huffman编码
            char codeBuffer[MAX_CODE_LEN];
            generateHuffmanCodes(root, codes, codeBuffer, 0);

            // 打印Huffman树结构
            printf("Huffman树结构:\n");
            printHuffmanTree(root, 0);

            // 压缩文件
            encodeFile(inputFile, outputFile, codes);

            // 计算压缩比
            calculateCompressionRatio(inputFile, outputFile);
        }
 
                else if (choice == 2) {
		            printf("请输入输入文件名: ");
		            scanf("%s", inputFile);
		            printf("请输入输出文件名: ");
		            scanf("%s", outputFile);
		
		            // 读取压缩文件并解码
		            decodeFile(inputFile, outputFile, root);
		
		            printf("文件已解压成功。\n");
		        }
		        else if (choice == 3) {
		            printf("程序退出。\n");
		            break;
		        }
		        else {
		            printf("无效选项，请重新选择。\n");
		        }
		    }
		
		    return 0;
		}
		
