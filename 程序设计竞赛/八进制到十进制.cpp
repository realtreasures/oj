#include<stdio.h>
#include<stdlib.h>

int main() {
    char octal[7];  // 八进制数最大长度为6，因此使用一个长度为7的数组（包括'\0'）
    
    while (1) {
        // 读入一个八进制数
        scanf("%s", octal);
        
        // 如果输入为"0"，则结束循环
        if (octal[0] == '0' && octal[1] == '\0') {
            break;
        }

        // 将八进制数转换为十进制数
        int decimal = strtol(octal, NULL, 8);
        
        // 输出转换后的十进制数
        printf("%d\n", decimal);
    }

    return 0;
}
