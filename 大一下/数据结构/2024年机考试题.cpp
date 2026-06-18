// 说明：
// 本次考试时间不超过100分钟，满分为100分，评分标准如下：
// 1. 算法原理正确，代码编译正确（编译时出现的警告若不影响功能则不扣分），执行结果正确，得60分
// 2. 书写规范，格式整齐，得20分
// 3. 交卷时间在60分钟内，得20分（超过60分钟的，每2分钟内扣1分，扣完为止，例如交卷时间>60且<=62分钟，得19分，以此类推）
// 答题完毕后，将本人所写的代码通过电子邮件发送给ustcdsa210070@163.com。邮件中写明本人学号、姓名，将代码作为附件。注意仅发送代码，不要附送其他文件，否则邮件可能会收不到。交卷时间以电子邮件系统显示的发送时间为准。

// 试题：
// 请补全下面的EnQueue、DeQueue、CreateExpression、CreateLayerOrderThread共四个函数，允许新增函数，不准删除或修改已有代码

#include <cstdio>
#include <cstring>
using namespace std;

typedef char TElemType;
typedef struct TriNode {
    TElemType data;
    TriNode *lchild;
    TriNode *rchild;
    TriNode *next;
} *Expression;
// 使用三叉链表存储表达式。结点中的data项存储运算符或运算数，除了+,-,*,/四个符号是运算符，其他符号如a,b,c都看作运算数。结点中的lchild和rchild分别表示二叉树中的左右子树，结点中的next表示层序遍历二叉树的后继结点。

const int QueueSize = 8;
typedef TriNode *QElemType;
typedef struct {
    QElemType *elem;
    int front;
    int rear;
    bool empty;
} CircleQueue;
// 使用循环队列辅助构造三叉链表。队列中存放三叉链表的结点指针。队列中的元素存放在以elem为首地址的数组中，front指示队首元素的位置，rear指示队尾元素的下一个位置，empty表示队列是否为空。注意当rear == front时，队列可能为空，也可能为满，此时通过empty即可区分两种状态，因此队列中最多容纳QueueSize个元素。

void InitQueue(CircleQueue &Q) {
    // 构造一个空队列，存储空间大小为QueueSize
    Q.elem = new QElemType[QueueSize];
    Q.front = 0;
    Q.rear = 0;
    Q.empty = true;
}

void DestroyQueue(CircleQueue &Q) {
    // 销毁一个队列
    delete []Q.elem;
}

void EnQueue(CircleQueue &Q, QElemType p) {
    // 入队，放置在队尾
    // 程序中不需要考虑内存大小限制，可以假设内存足够
}

bool DeQueue(CircleQueue &Q, QElemType &p) {
    // 出队，将队首元素通过引用参数p返回
    // 当队列为空时函数返回false，否则返回true
}

void CreateExpression(Expression &E, char *&s) {
    // 字符串s是表达式的前缀形式，写一个递归函数从字符串构造表达式二叉树
    // 注意：在这个函数中，结点的next指针可以暂时不考虑
}

void CreateLayerOrderThread(Expression &E) {
    // 对表达式二叉树进行层序遍历，从而正确设置三叉链表中所有结点的next指针
    // 要求：最后一个结点的next指针应设为NULL
}

void LayerOrderTraverse(Expression E) {
    // 对三叉链表通过next指针进行遍历，从而获得表达式二叉树的层序遍历序列
    TriNode *p = E;
    while (p) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    char *str = new char[12];
    strcpy(str, "-+a*b-cd/ef");
    char *s = str;
    Expression exp;
    CreateExpression(exp, str);
    delete []s;
    CreateLayerOrderThread(exp);
    LayerOrderTraverse(exp);
    return 0;
}
