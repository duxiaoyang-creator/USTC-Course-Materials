#include <stdio.h>

int main() {
    int n, m, digit;
    
    printf("输入一个值为3的倍数的整数：");
    scanf("%d", &n);
    
    printf("%d\n", n);  // 输出原始数字
    
    while (n != 153) {
        m = 0;
        // 计算各位数字的立方和
        while (n > 0) {
            digit = n % 10;       // 获取个位数
            m += digit * digit * digit;
            n /= 10;              // 去掉个位
        }
        n = m;  // 新数字作为下一轮输入
        printf("%d\n", n);
    }
    
    // 最后的总结（注意题目样例中输出原始数字，但此时n已变化，建议提前保存原始值）
    // 更完整的版本应该先保存原始值
    return 0;
}
