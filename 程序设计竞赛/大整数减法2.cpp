#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 205

// 比较两个大数的大小，返回1表示a >= b，0表示a < b
bool compare(char *a, char *b) {
    int lenA = strlen(a), lenB = strlen(b);
    if (lenA != lenB) return lenA > lenB;
    for (int i = 0; i < lenA; i++) {
        if (a[i] != b[i]) return a[i] >= b[i];
    }
    return true; // 相等
}

// 大数减法（确保a >= b）
void subtract(char *a, char *b, int *result) {
    int lenA = strlen(a), lenB = strlen(b);
    int borrow = 0, idx = 0;

    // 从个位开始减（逆序处理）
    for (int i = lenA - 1, j = lenB - 1; i >= 0; i--, j--, idx++) {
        int digitA = a[i] - '0';
        int digitB = (j >= 0) ? b[j] - '0' : 0;
        
        int diff = digitA - digitB - borrow;
        borrow = 0;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        result[idx] = diff;
    }

    // 处理最高位可能的借位
    while (idx > 0 && result[idx-1] == 0) idx--; // 去除前导零
}

int main() {
    char a[MAX_LEN], b[MAX_LEN];
    int result[MAX_LEN] = {0};
    bool isNegative = false;

    // 安全输入
    fgets(a, MAX_LEN, stdin);
    fgets(b, MAX_LEN, stdin);
    a[strcspn(a, "\n")] = '\0'; // 去除换行符
    b[strcspn(b, "\n")] = '\0';

    // 处理符号
    if (!compare(a, b)) { // 如果a < b，计算b - a并添加负号
        isNegative = true;
        char temp[MAX_LEN];
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }

    subtract(a, b, result);

    // 输出结果
    if (isNegative) printf("-");
    int start = MAX_LEN - 1;
    while (start >= 0 && result[start] == 0) start--; // 找到第一个非零位
    
    if (start < 0) {
        printf("0");
    } else {
        for (int i = start; i >= 0; i--) {
            printf("%d", result[i]);
        }
    }
    printf("\n");

    return 0;
}