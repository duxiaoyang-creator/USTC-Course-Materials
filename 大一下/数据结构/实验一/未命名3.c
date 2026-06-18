#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;          // 系数
    int exp;           // 指数
    struct Node* next;  // 指向下一个节点
} Node;

typedef struct Polynomial {
    Node* head;        // 多项式头指针
} Polynomial;

// 创建新节点
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// 初始化多项式
Polynomial* createPolynomial() {
    Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
    poly->head = NULL;
    return poly;
}

// 插入节点（按指数降序）
void insertTerm(Polynomial* poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (!poly->head || poly->head->exp < exp) {
        newNode->next = poly->head;
        poly->head = newNode;
        return;
    }

    Node* current = poly->head;
    while (current->next && current->next->exp >= exp) {
        if (current->exp == exp) {
            current->coeff += coeff;  // 合并同类项
            free(newNode);            // 释放新节点内存
            return;
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// 打印多项式
void printPolynomial(Polynomial* poly) {
    Node* current = poly->head;
    if (!current) {
        printf("0\n");
        return;
    }

    while (current) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// 销毁多项式
void destroyPolynomial(Polynomial* poly) {
    Node* current = poly->head;
    Node* temp;
    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}

// 多项式的和
Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = createPolynomial();
    Node* p1 = poly1->head;
    Node* p2 = poly2->head;

    while (p1 || p2) {
        if (!p1) {
            insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else if (!p2) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp == p2->exp) {
            insertTerm(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    return result;
}

// 多项式的差
Polynomial* subtractPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = createPolynomial();
    Node* p1 = poly1->head;
    Node* p2 = poly2->head;

    while (p1 || p2) {
        if (!p1) {
            insertTerm(result, -p2->coeff, p2->exp);
            p2 = p2->next;
        } else if (!p2) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp == p2->exp) {
            insertTerm(result, p1->coeff - p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insertTerm(result, -p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    return result;
}

// 多项式的积
Polynomial* multiplyPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = createPolynomial();
    Node* p1 = poly1->head;

    while (p1) {
        Node* p2 = poly2->head;
        Polynomial* temp = createPolynomial();
        
        while (p2) {
            insertTerm(temp, p1->coeff * p2->coeff, p1->exp + p2->exp);
            p2 = p2->next;
        }
        
        Polynomial* tempResult = addPolynomials(result, temp);
        destroyPolynomial(result);
        result = tempResult;
        destroyPolynomial(temp);
        p1 = p1->next;
    }

    return result;
}

// 主函数
int main() {
    Polynomial* poly1 = createPolynomial();
    Polynomial* poly2 = createPolynomial();
    int choice;
    
    do {
        printf("菜单：(1)创建多项式；（2）打印显示多项式；（3）销毁多项式；\n（4）求两个多项式的和；（5）求两个多项式的差；（6）求两个多项式的积；（0）退出\n");
        printf("请输入你的选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int coeff, exp, terms;
                printf("请输入多项式的项数: ");
                scanf("%d", &terms);
                for (int i = 0; i < terms; i++) {
                    printf("请输入第%d项的系数和指数 (格式: coeff exp): ", i + 1);
                    scanf("%d %d", &coeff, &exp);
                    insertTerm(poly1, coeff, exp);
                }
                printf("多项式1创建成功！\n");
                break;
            }
            case 2: {
                printf("多项式1: ");
                printPolynomial(poly1);
                break;
            }
            case 3: {
                destroyPolynomial(poly1);
                poly1 = createPolynomial(); // 重新初始化多项式
                printf("多项式1已销毁！\n");
                break;
            }
            case 4: {
                printf("请输入第二个多项式的项数: ");
                int terms;
                scanf("%d", &terms);
                for (int i = 0; i < terms; i++) {
                    int coeff, exp;
                    printf("请输入第%d项的系数和指数 (格式: coeff exp): ", i + 1);
                    scanf("%d %d", &coeff, &exp);
                    insertTerm(poly2, coeff, exp);
                }
                Polynomial* sumPoly = addPolynomials(poly1, poly2);
                printf("多项式和: ");
                printPolynomial(sumPoly);
                destroyPolynomial(sumPoly);
                break;
            }
            case 5: {
                Polynomial* diffPoly = subtractPolynomials(poly1, poly2);
                printf("多项式差: ");
                printPolynomial(diffPoly);
                destroyPolynomial(diffPoly);
                break;
            }
            case 6: {
                Polynomial* prodPoly = multiplyPolynomials(poly1, poly2);
                printf("多项式积: ");
                printPolynomial(prodPoly);
                destroyPolynomial(prodPoly);
                break;
            }
            case 0:
                printf("程序结束。\n");
                break;
            default:
                printf("无效的选择，请重新输入。\n");
                break;
        }
    } while (choice != 0);

    destroyPolynomial(poly1);
    destroyPolynomial(poly2);
    return 0;
}
