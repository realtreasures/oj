#include<stdio.h>

int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 平年每个月的天数
int b[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 闰年每个月的天数

// 判断是否为闰年
int is_leap_year(int year) {
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// 根据天数计算具体日期
void calculate_date(int n) {
    int year = 2007, month = 10, day = 10; // 初始日期 2007年10月10日
    int days_in_month;

    // 将n天加到当前日期
    day += n;

    // 处理日期跨月和跨年的情况
    while (1) {
        // 判断当前月是平年还是闰年
        if (is_leap_year(year)) {
            days_in_month = b[month - 1];
        } else {
            days_in_month = a[month - 1];
        }

        if (day > days_in_month) {
            day -= days_in_month;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        } else {
            break;
        }
    }

    printf("%04d-%02d-%02d\n", year, month, day);
}

int main() {
    int n;
    // 处理多组输入
    while (scanf("%d", &n) != EOF) {
        calculate_date(n);
    }
    return 0;
}
