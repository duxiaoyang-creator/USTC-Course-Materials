#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 运算符优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 执行算术操作
int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;  // 假设没有除数为零的情况
    }
    return 0;
}

// 计算表达式的值
int calculate(char* expr) {
    int values[100];  // 数字栈
    char ops[100];    // 运算符栈
    int valueTop = -1;  // 数字栈顶指针
    int opsTop = -1;    // 运算符栈顶指针

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // 如果是数字，处理多位数字
        if (isdigit(c)) {
            int val = 0;
            // 将数字字符转换为整数，直到遇到非数字字符
            while (i < strlen(expr) && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            i--;  // 回退一步，因为循环已经移动到下一个字符
            values[++valueTop] = val;  // 将数字压入栈
        }
        // 如果是左括号，直接压栈
        else if (c == '(') {
            ops[++opsTop] = c;
        }
        // 如果是右括号，弹出运算符栈直到遇到左括号
        else if (c == ')') {
            while (opsTop >= 0 && ops[opsTop] != '(') {
                int b = values[valueTop--];
                int a = values[valueTop--];
                char op = ops[opsTop--];
                values[++valueTop] = applyOperator(a, b, op);
            }
            opsTop--;  // 弹出 '('
        }
        // 如果是运算符
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // 处理运算符栈，优先级高的运算符先执行
            while (opsTop >= 0 && precedence(ops[opsTop]) >= precedence(c)) {
                int b = values[valueTop--];
                int a = values[valueTop--];
                char op = ops[opsTop--];
                values[++valueTop] = applyOperator(a, b, op);
            }
            ops[++opsTop] = c;  // 当前运算符压入栈
        }
    }

    // 处理栈中剩余的运算符
    while (opsTop >= 0) {
        int b = values[valueTop--];
        int a = values[valueTop--];
        char op = ops[opsTop--];
        values[++valueTop] = applyOperator(a, b, op);
    }

    // 栈顶的值即为最终结果
    return values[valueTop];
}

int main() {
    char expr[100];  // 存储输入表达式
    printf("请输入一个算术表达式: ");
    scanf("%s", expr);

    int result = calculate(expr);
    printf("表达式的值是: %d\n", result);

    return 0;
}
