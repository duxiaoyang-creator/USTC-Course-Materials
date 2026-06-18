#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 600

typedef struct CustNode {
    int arrtime;    // 到达时间
    int durtime;    // 处理时间
    int Leavetime;  // 离开时间
    int amount;     // 资金数额（负值为取款/借款，正值为存款/还款）
} CustNode;//客户节点 

typedef struct Queue {
    CustNode *nodes[MAX];//客户标号 
    int front;
    int rear;
} Queue;//客户排队 

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}//初始化队伍 

int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}//空队return1 

int isQueueFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}//满队return1 

void enqueue(Queue *q, CustNode *node) {
    if (!isQueueFull(q)) {//队不满可插 
        q->nodes[q->rear] = node;
        q->rear = (q->rear + 1) % MAX;
    }
}//新客户插入队尾 

CustNode* dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {//队不空可删 
        CustNode *node = q->nodes[q->front];
        q->front = (q->front + 1) % MAX;
        return node;
    }
    return NULL;
}//取出排在第一个的客户 

CustNode* createNode(int arrtime, int durtime, int amount) {
    CustNode *node = (CustNode *)malloc(sizeof(CustNode));
    if (node != NULL) {
        node->arrtime = arrtime;
        node->durtime = durtime;
        node->Leavetime = -1;
        node->amount = amount;
    }
    return node;
}

void freeNode(CustNode *node) {
    free(node);
}

int main() {
    int total = 10000; // 银行初始资金
    int closetime = 600; // 营业时间
    int arrivalIntervalMin, arrivalIntervalMax;
    int durationMin, durationMax;
    int amountMin, amountMax;

    // 输入到达间隔时间
    printf("请输入到达间隔时间的最小和最大值（以空格分隔）：");
    while (scanf("%d %d", &arrivalIntervalMin, &arrivalIntervalMax) != 2 || 
           arrivalIntervalMin < 0 || arrivalIntervalMax < arrivalIntervalMin||arrivalIntervalMin>600||arrivalIntervalMax>600) {
        printf("输入无效，请重新输入：");
        while(getchar() != '\n'); // 清空输入缓冲区
    }

    // 输入办理时间
    printf("请输入办理时间的最小和最大值（以空格分隔）：");
    while (scanf("%d %d", &durationMin, &durationMax) != 2 || 
           durationMin < 0 || durationMax < durationMin||durationMax>600||durationMin>600) {
        printf("输入无效，请重新输入：");
        while(getchar() != '\n');
    }

    // 输入金额范围
    printf("请输入金额的最小和最大值（以空格分隔）：");
    while (scanf("%d %d", &amountMin, &amountMax) != 2 || 
           amountMin > amountMax) {
        printf("输入无效，请重新输入：");
        while(getchar() != '\n');
    }

    Queue queue1, queue2;
    initQueue(&queue1);
    initQueue(&queue2);//初始化 

    srand(time(NULL));//时间随机数种子 

    // 生成事件
    int currentTime = 0;//此刻
	int start; 
    int eventCount = 0;
    CustNode *eventList[MAX];
    
    while (currentTime < closetime && eventCount < MAX) {//仍在营业且客户数未达到最大 
        int interval = rand() % (arrivalIntervalMax - arrivalIntervalMin + 1) + arrivalIntervalMin;
        int durtime = rand() % (durationMax - durationMin + 1) + durationMin;
        int amount = rand() % (amountMax - amountMin + 1) + amountMin;
        //为了确保在范围里
		
        // 创建事件
        CustNode *event = createNode(currentTime, durtime, amount);
        if (event != NULL) {
            eventList[eventCount++] = event;
        } else {
            printf("内存分配失败，无法创建事件。\n");
        }

        // 更新当前时间
        currentTime += interval;
    }

    // 处理事件
    for (int i = 0; i < eventCount; i++) {
        enqueue(&queue1, eventList[i]);//逐个插入客户 
    }

    int totalTimeInBank = 0;
    int processedCount = 0;
    currentTime=0;
    start=0;
    while (!isQueueEmpty(&queue1) || !isQueueEmpty(&queue2)) {
    	
	    if(isQueueEmpty(&queue1))break;
	    
	    
        if (!isQueueEmpty(&queue1)) {
            CustNode *currentCustomer = dequeue(&queue1);//对队首客户处理事件 
			processedCount++;
			if(currentCustomer->arrtime>=currentTime){//如果上一位客户结束后下一位客户还未到达 
                    	start=currentCustomer->arrtime;
					}else{//如果上一位客户还未完成下一位客户已到达 
						start=currentTime;
					}
            if(currentTime+currentCustomer->durtime>=600)break;
            
            
			if (currentCustomer->amount < 0) { // 取款/借款
                if (total + currentCustomer->amount < 0) {//0
                    enqueue(&queue2, currentCustomer); // 不满足条件，进入第二队列
                } else {//1
                    total += currentCustomer->amount;
                    
                    currentCustomer->Leavetime = start + currentCustomer->durtime;
					currentTime=currentCustomer->Leavetime;
                    totalTimeInBank += (currentCustomer->Leavetime - currentCustomer->arrtime);
                    
                    
                    printf("该客户的到达时间为%d,处理时间为%d,离开时间为%d，资金数额为%d,银行剩余资金为%d\n",currentCustomer->arrtime,currentCustomer->durtime,currentCustomer->Leavetime,currentCustomer->amount,total);
					}
			}else { // 存款/还款 1
                total += currentCustomer->amount;
                currentCustomer->Leavetime = start + currentCustomer->durtime;
                totalTimeInBank += (currentCustomer->Leavetime - currentCustomer->arrtime);
                currentTime=currentCustomer->Leavetime;
                printf("该客户的到达时间为%d,处理时间为%d,离开时间为%d，资金数额为%d,银行剩余资金为%d\n",currentCustomer->arrtime,currentCustomer->durtime,currentCustomer->Leavetime,currentCustomer->amount,total);
            // 处理第二队列的客户
                if (!isQueueEmpty(&queue2)) {
                    while(1){
					printf("ok");
					CustNode *secondCustomer = dequeue(&queue2);
                    if (total + secondCustomer->amount >= 0) {//1
                    total += secondCustomer->amount;
                    secondCustomer->Leavetime = start + secondCustomer->durtime;
                    totalTimeInBank += (secondCustomer->Leavetime - secondCustomer->arrtime);
                    currentTime=secondCustomer->Leavetime;
                    printf("该客户的到达时间为%d,处理时间为%d,离开时间为%d，资金数额为%d,银行剩余资金为%d\n",secondCustomer->arrtime,secondCustomer->durtime,secondCustomer->Leavetime,secondCustomer->amount,total);
                    } else {
                      enqueue(&queue2, secondCustomer); // 重新排队 0
                    }
					}
                }
		}
        }

    }
    while(!isQueueEmpty(&queue2)){
    	CustNode *secondCustomer = dequeue(&queue2);
    	secondCustomer->durtime=600-secondCustomer->arrtime;
		totalTimeInBank+= secondCustomer->durtime;
	}
	double averageTime = (double)totalTimeInBank / processedCount;
    // 计算并输出平均逗留时间
    if (processedCount > 0) {
        
        printf("客户在银行内逗留的平均时间: %.2f 分钟\n", averageTime);
    } else {
    	
        printf("客户在银行内逗留的平均时间: %.2f 分钟\n", averageTime);
    }

    // 释放事件内存
    for (int i = 0; i < eventCount; i++) {
        freeNode(eventList[i]);
    }

    return 0;
}
